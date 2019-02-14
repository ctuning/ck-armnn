# ArmNN installation

## Summary

Frontends/backends                            | Reference      | Neon                         | OpenCL                         | Neon, OpenCL                                 |
-|-|-|-|-|
[TF](https://www.tensorflow.org/)             | `USE_TF=1`     | `USE_TF=1`,     `USE_NEON=1` | `USE_TF=1`,     `USE_OPENCL=1` | `USE_TF=1`,     `USE_NEON=1`, `USE_OPENCL=1` |
TF, [TFLite](https://www.tensorflow.org/lite) | `USE_TFLITE=1` | `USE_TFLITE=1`, `USE_NEON=1` | `USE_TFLITE=1`, `USE_OPENCL=1` | `USE_TFLITE=1`, `USE_NEON=1`, `USE_OPENCL=1` |
[ONNX](https://onnx.ai/)                      | `USE_ONNX=1`   | `USE_ONNX=1`,   `USE_NEON=1` | `USE_ONNX=1`,   `USE_OPENCL=1` | `USE_ONNX=1`,   `USE_NEON=1`, `USE_OPENCL=1` |

**NB:** Currently, following these instructions in order is important. Otherwise, CK will try to reuse environments, which will screw them up.

## Table of Contents

1. [Frontend: TF](#tf)
    1. [Backend: Reference](#tf_ref)
    1. [Backend: Neon](#tf_neon)
    1. [Backend: OpenCL](#tf_opencl)
    1. [Backends: Neon, OpenCL](#tf_neon_opencl)
1. [Frontend: TFLite](#tflite)
    1. [Backend: Reference](#tflite_ref)
    1. [Backend: Neon](#tflite_neon)
    1. [Backend: OpenCL](#tflite_opencl)
    1. [Backends: Neon, OpenCL](#tflite_neon_opencl)
1. [Frontend: ONNX](#onnx)
    1. [Backend: Reference](#onnx_ref)
    1. [Backend: Neon](#onnx_neon)
    1. [Backend: OpenCL](#onnx_opencl)
    1. [Backends: Neon, OpenCL](#onnx_neon_opencl)


<a name="tf"></a>
## Frontend: TF

<a name="tf_ref"></a>
### Backend: Reference
```
$ ck install package --tags=lib,armnn,vtf --env.USE_TF=1
```

<a name="tf_neon"></a>
### Backend: Neon
```
$ ck install package --tags=lib,armcl,viascons \
--env.USE_NEON=1 \
--extra_tags=vneon \
--extra_path=-neon

$ ck install package --tags=lib,armnn,vtf \
--env.USE_TF=1 \
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

$ ck install package --tags=lib,armnn,vtf \
--env.USE_TF=1 \
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
--env.USE_TF=1 \
--env.USE_NEON=1 --env.USE_OPENCL=1 \
--extra_tags=vneon,vopencl \
--extra_version=-neon-opencl
```


<a name="tflite"></a>
## Frontend: TFLite

<a name="tflite_ref"></a>
### Backend: Reference
```
$ ck install package --tags=lib,armnn,vtf --env.USE_TFLITE=1
```

<a name="tflite_neon"></a>
### Backend: Neon
```
$ ck install package --tags=lib,armcl,viascons \
--env.USE_NEON=1 \
--extra_tags=vneon \
--extra_path=-neon

$ ck install package --tags=lib,armnn,vtf \
--env.USE_TFLITE=1 \
--env.USE_NEON=1 \
--extra_tags=vneon \
--extra_version=-neon
```

<a name="tflite_opencl"></a>
### Backend: OpenCL
```
$ ck install package --tags=lib,armcl,viascons \
--env.USE_OPENCL=1 \
--extra_tags=vopencl \
--extra_path=-opencl

$ ck install package --tags=lib,armnn,vtf \
--env.USE_TFLITE=1 \
--env.USE_OPENCL=1 \
--extra_tags=vopencl \
--extra_version=-opencl
```

<a name="tflite_neon_opencl"></a>
### Backends: Neon, OpenCL
```
$ ck install package --tags=lib,armcl,viascons \
--env.USE_NEON=1 --env.USE_OPENCL=1 \
--extra_tags=vneon,vopencl \
--extra_path=-neon-opencl

$ ck install package --tags=lib,armnn \
--env.USE_TFLITE=1 \
--env.USE_NEON=1 --env.USE_OPENCL=1 \
--extra_tags=vneon,vopencl \
--extra_version=-neon-opencl
```


<a name="onnx"></a>
## Frontend: ONNX

<a name="onnx_ref"></a>
### Backend: Reference
```
$ ck install package --tags=lib,armnn,vtf --env.USE_ONNX=1
```

<a name="onnx_neon"></a>
### Backend: Neon
```
$ ck install package --tags=lib,armcl,viascons \
--env.USE_NEON=1 \
--extra_tags=vneon \
--extra_path=-neon

$ ck install package --tags=lib,armnn,vtf \
--env.USE_ONNX=1 \
--env.USE_NEON=1 \
--extra_tags=vneon \
--extra_version=-neon
```

<a name="onnx_opencl"></a>
### Backend: OpenCL
```
$ ck install package --tags=lib,armcl,viascons \
--env.USE_OPENCL=1 \
--extra_tags=vopencl \
--extra_path=-opencl

$ ck install package --tags=lib,armnn,vtf \
--env.USE_ONNX=1 \
--env.USE_OPENCL=1 \
--extra_tags=vopencl \
--extra_version=-opencl
```

<a name="onnx_neon_opencl"></a>
### Backends: Neon, OpenCL
```
$ ck install package --tags=lib,armcl,viascons \
--env.USE_NEON=1 --env.USE_OPENCL=1 \
--extra_tags=vneon,vopencl \
--extra_path=-neon-opencl

$ ck install package --tags=lib,armnn \
--env.USE_ONNX=1 \
--env.USE_NEON=1 --env.USE_OPENCL=1 \
--extra_tags=vneon,vopencl \
--extra_version=-neon-opencl
```

