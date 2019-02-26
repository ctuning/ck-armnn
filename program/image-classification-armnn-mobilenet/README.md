# TensorFlow Lite image classification program

This program uses a statically linked [TensorFlow Lite](https://www.tensorflow.org/lite/) library.

## Prerequisites
Installed ArmCL. To install:
```
$ ck install package --tags=armcl,viascons --env.USE_NEON=1 --env.USE_OPENCL=1 --extra_tags=vneon,vopencl --extra_path=-neon-opencl
```
or minimum:
```
$ ck install package --tags=armcl,viascons
```


Installed ArmNN library. To install:
```
$ ck install package:lib-armnn-dev --env.USE_TFLITE=1 --env.USE_NEON=1 --env.USE_OPENCL=1 --extra_tags=vneon,vopencl --extra_version=-neon-opencl-dev
```
or minimum:
```
$ ck install package:lib-armnn-dev --env.USE_TFLITE=1
```

## Compile

```
$ ck compile program:image-classification-armnn-mobilenet
```

## Run

```
$ ck run program:image-classification-armnn-mobilenet  --env.CK_BATCH_COUNT=5 --env.CK_BACKEND=CpuAcc
```
**Here:**
 - CK_BATCH_COUNT - file's count to evaluate (default: 1)
 - CK_BACKEND - type of backend:
   - CpuRef - default
   - CpuAcc - NEON
   - GpuAcc - OpenCL
   - CpuGpuAcc - NEON + OpenCL
