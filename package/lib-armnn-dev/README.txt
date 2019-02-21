# This package can be built in 4 different modes:

ck install package:lib-armnn-dev

ck install package:lib-armnn-dev --env.USE_NEON=1 --extra_tags=vneon --extra_version=-neon-dev

ck install package:lib-armnn-dev --env.USE_OPENCL=1 --extra_tags=vopencl --extra_version=-opencl-dev

ck install package:lib-armnn-dev --env.USE_NEON=1 --env.USE_OPENCL=1 --extra_tags=vneon,vopencl --extra_version=-neon-opencl-dev

ck install package:lib-armnn-dev --env.USE_TFLITE=1 --env.USE_NEON=1 --env.USE_OPENCL=1 --extra_tags=vneon,vopencl --extra_version=-neon-opencl-dev
# NB! The order of builds is important - otherwise CK will try to reuse environments, which will screw them up.

