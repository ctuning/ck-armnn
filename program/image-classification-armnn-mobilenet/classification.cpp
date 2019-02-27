/*
 * Copyright (c) 2018 cTuning foundation.
 * See CK COPYRIGHT.txt for copyright details.
 *
 * SPDX-License-Identifier: BSD-3-Clause.
 * See CK LICENSE.txt for licensing details.
 */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <array>
#include <algorithm>
#include <sys/stat.h>
#include "armnn/ArmNN.hpp"
#include "armnn/Exceptions.hpp"
#include "armnn/Tensor.hpp"
#include "armnn/INetwork.hpp"
#include "armnnTfLiteParser/ITfLiteParser.hpp"

#include "benchmark.h"

using namespace std;
using namespace CK;

template <typename TData, typename TInConverter, typename TOutConverter>
class TFLiteBenchmark : public Benchmark<TData, TInConverter, TOutConverter> {
public:
    TFLiteBenchmark(const BenchmarkSettings* settings, TData *in_ptr, TData *out_ptr, int input_index)
            : Benchmark<TData, TInConverter, TOutConverter>(settings, in_ptr, out_ptr) {
    }
};

armnn::InputTensors MakeInputTensors(const std::pair<armnn::LayerBindingId,
        armnn::TensorInfo>& input, const void* inputTensorData)
{
    return { {input.first, armnn::ConstTensor(input.second, inputTensorData) } };
}

armnn::OutputTensors MakeOutputTensors(const std::pair<armnn::LayerBindingId,
        armnn::TensorInfo>& output, void* outputTensorData)
{
    return { {output.first, armnn::Tensor(output.second, outputTensorData) } };
}


int main(int argc, char* argv[]) {
    const char *backend = getenv("CK_BACKEND");
    string ck_backend;
    if (!backend) ck_backend = "CpuRef";
    else ck_backend = backend;

    try {
        init_benchmark();

        BenchmarkSettings settings;

        // TODO: learn how to process batches via tflite.
        // currently interpreter->tensor(input_index)->dims[0] = 1
        if (settings.batch_size != 1)
            throw string("Only BATCH_SIZE=1 is currently supported");

        BenchmarkSession session(&settings);

        unique_ptr<IBenchmark> benchmark;
        armnnTfLiteParser::ITfLiteParserPtr parser = armnnTfLiteParser::ITfLiteParser::Create();
        armnn::NetworkId networkIdentifier;
        armnn::IRuntime::CreationOptions options;
        armnn::IRuntimePtr runtime = armnn::IRuntime::Create(options);
        armnn::OutputTensors outputTensor;
        armnn::InputTensors inputTensor;

        // Optimize the network for a specific runtime compute device, e.g. CpuAcc, GpuAcc
        //std::vector<armnn::BackendId> optOptions = {armnn::Compute::CpuAcc, armnn::Compute::GpuAcc};
        std::vector<armnn::BackendId> optOptions = {armnn::Compute::CpuRef};
        if (ck_backend == "CpuAcc") {
            optOptions = {armnn::Compute::CpuAcc};
        } else if (ck_backend == "GpuAcc") {
            optOptions = {armnn::Compute::GpuAcc};
        } else if (ck_backend == "CpuGpuAcc") {
            optOptions = {armnn::Compute::CpuAcc, armnn::Compute::GpuAcc};
        }

        cout << "\nLoading graph..." << endl;
        measure_setup([&]{
            armnn::INetworkPtr network = parser->CreateNetworkFromBinaryFile(settings.graph_file.c_str());
            if (!network)
                throw "Failed to load graph from file";

            armnnTfLiteParser::BindingPointInfo inputBindingInfo = parser->GetNetworkInputBindingInfo(0,"input");
            armnnTfLiteParser::BindingPointInfo outputBindingInfo = parser->GetNetworkOutputBindingInfo(0,"MobilenetV1/Predictions/Reshape_1");

            armnn::TensorShape inShape = inputBindingInfo.second.GetShape();
            armnn::TensorShape outShape = outputBindingInfo.second.GetShape();
            std::size_t inSize = inShape[0] * inShape[1] * inShape[2] * inShape[3];
            std::size_t outSize = outShape[0] * outShape[1];

            armnn::IOptimizedNetworkPtr optNet = armnn::Optimize(*network, optOptions, runtime->GetDeviceSpec());

            runtime->LoadNetwork(networkIdentifier, std::move(optNet));
            float *output = new float[outSize];
            float *input = new float[inSize];

            outputTensor = MakeOutputTensors(outputBindingInfo, output);
            inputTensor = MakeInputTensors(inputBindingInfo, input);

            benchmark.reset(new TFLiteBenchmark<float, InNormalize, OutCopy>(&settings, input, output, 0));

            int out_num = outShape[0];
            int out_classes = outShape[1];
            cout << format("Output tensor dimensions: %d*%d", out_num, out_classes) << endl;
            if (out_classes != settings.num_classes && out_classes != settings.num_classes+1)
                throw format("Unsupported number of classes in graph's output tensor. Supported numbers are %d and %d",
                             settings.num_classes, settings.num_classes+1);
            benchmark->has_background_class = out_classes == settings.num_classes+1;
        });

        cout << "\nProcessing batches..." << endl;
        measure_prediction([&]{
            while (session.get_next_batch()) {
                session.measure_begin();
                benchmark->load_images(session.batch_files());
                session.measure_end_load_images();

                session.measure_begin();
                if (runtime->EnqueueWorkload(networkIdentifier, inputTensor, outputTensor) != armnn::Status::Success)
                    throw "Failed to invoke tflite";
                session.measure_end_prediction();

                benchmark->save_results(session.batch_files());
            }
        });

        finish_benchmark(session);
    }
    catch (const string& error_message) {
        cerr << "ERROR: " << error_message << endl;
        return -1;
    }
    return 0;
}
