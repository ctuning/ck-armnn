#!/bin/bash

#
# See CK LICENSE for licensing details.
# See CK COPYRIGHT for copyright details.
#
# Developer(s):
# - Leo Gordon, 2018
#

# for example,
#   INSTALL_DIR     = "lib-armnn-linux-64"
#   PACKAGE_SUB_DIR = "src"

ARMNN_SOURCE_DIR=$INSTALL_DIR/$PACKAGE_SUB_DIR
ARMNN_BUILD_DIR=$INSTALL_DIR/obj
ARMNN_TARGET_DIR=$INSTALL_DIR/install

TF_PB_DIR=$INSTALL_DIR/generated_tf_pb_files

############################################################
echo ""
echo "Building ArmNN package in $INSTALL_DIR ..."
echo ""

set

############################################################
echo ""
echo "Generating Protobuf files from Tensorflow ..."
echo ""

rm -rf "${TF_PB_DIR}"
mkdir ${TF_PB_DIR}
cd ${CK_ENV_LIB_TF}/src
${ARMNN_SOURCE_DIR}/scripts/generate_tensorflow_protobuf.sh ${TF_PB_DIR} ${CK_ENV_LIB_PROTOBUF_HOST}

############################################################
echo ""
echo "Running cmake for ArmNN with USE_TFLITE='${USE_TFLITE}' and USE_NEON='${USE_NEON}' and USE_OPENCL='${USE_OPENCL}' ..."
echo ""

if [ "$USE_NEON" == "YES" ] || [ "$USE_NEON" == "yes" ] || [ "$USE_NEON" == "ON" ] || [ "$USE_NEON" == "on" ] || [ "$USE_NEON" == "1" ]
then
    EXTRA_CMAKE_FOR_NEON=" -DARMCOMPUTENEON=1 "
else
    EXTRA_CMAKE_FOR_NEON=""
fi

if [ "$USE_OPENCL" == "YES" ] || [ "$USE_OPENCL" == "yes" ] || [ "$USE_OPENCL" == "ON" ] || [ "$USE_OPENCL" == "on" ] || [ "$USE_OPENCL" == "1" ]
then
    EXTRA_CMAKE_FOR_OPENCL=" -DARMCOMPUTECL=1 "
else
    EXTRA_CMAKE_FOR_OPENCL=""
fi

if [ "$USE_TFLITE" == "YES" ] || [ "$USE_TFLITE" == "yes" ] || [ "$USE_TFLITE" == "ON" ] || [ "$USE_TFLITE" == "on" ] || [ "$USE_TFLITE" == "1" ]
then
    EXTRA_CMAKE_FOR_TFLITE=" -DBUILD_TF_LITE_PARSER=1 -DTF_LITE_GENERATED_PATH=${CK_ENV_LIB_TF}/src/tensorflow/lite/schema -DFLATBUFFERS_ROOT=${CK_ENV_LIB_FLATBUFFERS} -DFLATBUFFERS_LIBRARY=${CK_ENV_LIB_FLATBUFFERS_LIB}/libflatbuffers.a "
else
    EXTRA_CMAKE_FOR_TFLITE=""
fi

rm -rf "${ARMNN_BUILD_DIR}"
mkdir ${ARMNN_BUILD_DIR}
cd ${ARMNN_BUILD_DIR}
cmake ${ARMNN_SOURCE_DIR} \
    -DCMAKE_C_COMPILER="${CK_CC_PATH_FOR_CMAKE}" \
    -DCMAKE_C_FLAGS="${CK_CC_FLAGS_FOR_CMAKE} ${EXTRA_FLAGS}" \
    -DCMAKE_CXX_COMPILER="${CK_CXX_PATH_FOR_CMAKE}" \
    -DCMAKE_CXX_FLAGS="${CK_CXX_FLAGS_FOR_CMAKE} ${EXTRA_FLAGS} ${CK_CXX_COMPILER_STDLIB}" \
    -DCMAKE_AR="${CK_AR_PATH_FOR_CMAKE}" \
    -DCMAKE_RANLIB="${CK_RANLIB_PATH_FOR_CMAKE}" \
    -DCMAKE_LINKER="${CK_LD_PATH_FOR_CMAKE}" \
    -DARMCOMPUTE_ROOT=${CK_ENV_LIB_ARMCL} \
    -DARMCOMPUTE_BUILD_DIR=${CK_ENV_LIB_ARMCL}/build \
    -DBOOST_ROOT=${CK_ENV_LIB_BOOST} \
    -DTF_GENERATED_SOURCES=${TF_PB_DIR} \
    -DBUILD_TF_PARSER=1 \
    -DPROTOBUF_ROOT=$CK_ENV_LIB_PROTOBUF_HOST \
    ${EXTRA_CMAKE_FOR_TFLITE} ${EXTRA_CMAKE_FOR_NEON} ${EXTRA_CMAKE_FOR_OPENCL} \
    -DCMAKE_INSTALL_PREFIX=${ARMNN_TARGET_DIR}

