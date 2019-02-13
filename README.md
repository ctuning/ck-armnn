# ArmNN installation

## Summary

Frontends/backends                            | Reference      | Neon                         | OpenCL                         | Neon, OpenCL                                 |
-|-|-|-|-|
[TF](https://www.tensorflow.org/)             | (default)      |                 `USE_NEON=1` |                 `USE_OPENCL=1` |                 `USE_NEON=1`, `USE_OPENCL=1` |
TF, [TFLite](https://www.tensorflow.org/lite) | `USE_TFLITE=1` | `USE_TFLITE=1`, `USE_NEON=1` | `USE_TFLITE=1`, `USE_OPENCL=1` | `USE_TFLITE=1`, `USE_NEON=1`, `USE_OPENCL=1` |
[ONNX](https://onnx.ai/)                      | N/A            | N/A                          | N/A                            | N/A                                          |

**NB:** Currently, following these instructions in order is important. Otherwise, CK will try to reuse environments, which will screw them up.

## Table of Contents

1. [Frontend: TF](#tf)
    1. [Backend: Reference](#tf_ref)
    1. [Backend: Neon](#tf_neon)
    1. [Backend: OpenCL](#tf_opencl)
    1. [Backends: Neon, OpenCL](#tf_neon_opencl)
1.  **TODO:** [Frontends: TF, TFLite](#tflite)
1.  **TODO:** [Frontend: ONNX](#onnx)


<a name="tf"></a>
## Frontend: TF

<a name="tf_ref"></a>
### Backend: Reference
```
$ ck install package --tags=lib,armnn
```

<a name="tf_neon"></a>
### Backend: Neon
```
$ ck install package --tags=lib,armcl,viascons \
--env.USE_NEON=1 \
--extra_tags=vneon \
--extra_path=-neon

$ ck install package --tags=lib,armnn \
--env.USE_NEON=1 \
--extra_tags=vneon \
--extra_version=-neon
```

<a name="tf_opencl"></a>
### Backend: OpenCL
```
$ ck install package --tags=lib,armcl,viascons \
--env.USE_OPENCL=1 \
--extra_tags=vopencl \
--extra_path=-opencl

$ ck install package --tags=lib,armnn \
--env.USE_OPENCL=1 \
--extra_tags=vopencl \
--extra_version=-opencl
```

<a name="tf_neon_opencl"></a>
### Backends: Neon, OpenCL
```
$ ck install package --tags=lib,armcl,viascons \
--env.USE_NEON=1 --env.USE_OPENCL=1 \
--extra_tags=vneon,vopencl \
--extra_path=-neon-opencl

$ ck install package --tags=lib,armnn \
--env.USE_NEON=1 --env.USE_OPENCL=1 \
--extra_tags=vneon,vopencl \
--extra_version=-neon-opencl
```

<a name="tflite"></a>
## Frontends: TF, TFLite
**TODO**

<a name="onnx"></a>
## Frontend: ONNX
**TODO**

