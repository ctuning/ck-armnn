**All CK components for AI and ML are now collected in [one repository](https://github.com/ctuning/ai)!**

[![Travis Build Status](https://travis-ci.org/ctuning/ck-armnn.svg?branch=master)](https://travis-ci.org/ctuning/ck-armnn)

# ArmNN installation

To install a particular version of ArmNN we have to combine three kinds of tags:

- Frontend-related tags (based on supported ArmNN parsers): `tf`, `tflite`, `onnx`. These can be combined.

- Backend-related tags (based on a specific build of ArmCL): `neon`, `opencl`. These can be combined or both missing (reference).

- Version/Release-related tags: `rel.19.02` (a particular frozen release), `release` (the latest stable release), `dev` (the live development branch). These are mutually exclusive. Exactly one Version/Release tag must be present.

## Examples

The live development version supporting the TFLite frontend and Neon backend:
```
$ ck install package --tags=lib,armnn,tflite,neon,dev
```

The latest stable release supporting the TensorFlow frontend and OpenCL backend:
```
$ ck install package --tags=lib,armnn,tf,opencl,release
```

The 19.02 release supporting the TFLite and ONNX frontends and no optimized backends (i.e. reference):
```
$ ck install package --tags=lib,armnn,tflite,onnx,rel.19.02
```

