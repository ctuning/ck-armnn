# ArmNN installation

## Summary

Frontends/backends                            | Reference | Neon          | OpenCL          | Neon, OpenCL         |
-|-|-|-|-|
[TF](https://www.tensorflow.org/)             | `tf`      | `tf,neon`     | `tf,opencl`     | `tf,neon,opencl`     |
[TFLite](https://www.tensorflow.org/lite)     | `tflite`  | `tflite,neon` | `tflite,opencl` | `tflite,neon,opencl` |
[ONNX](https://onnx.ai/)                      | `onnx`    | `onnx,neon`   | `onnx,opencl`   | `onnx,neon,opencl`   |

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
$ ck install package --tags=lib,armnn,tf
```

<a name="tf_neon"></a>
### Backend: Neon
```
$ ck install package --tags=lib,armnn,tf,neon
```

<a name="tf_opencl"></a>
### Backend: OpenCL
```
$ ck install package --tags=lib,armnn,tf,opencl
```

<a name="tf_neon_opencl"></a>
### Backends: Neon, OpenCL
```
$ ck install package --tags=lib,armnn,tf,neon,opencl
```


<a name="tflite"></a>
## Frontend: TFLite

<a name="tflite_ref"></a>
### Backend: Reference
```
$ ck install package --tags=lib,armnn,tflite
```

<a name="tflite_neon"></a>
### Backend: Neon
```
$ ck install package --tags=lib,armnn,tflite,neon
```

<a name="tflite_opencl"></a>
### Backend: OpenCL
```
$ ck install package --tags=lib,armnn,tflite,opencl
```

<a name="tflite_neon_opencl"></a>
### Backends: Neon, OpenCL
```
$ ck install package --tags=lib,armnn,tflite,neon,opencl
```


<a name="onnx"></a>
## Frontend: ONNX

<a name="onnx_ref"></a>
### Backend: Reference
```
$ ck install package --tags=lib,armnn,onnx
```

<a name="onnx_neon"></a>
### Backend: Neon
```
$ ck install package --tags=lib,armnn,onnx,neon
```

<a name="onnx_opencl"></a>
### Backend: OpenCL
```
$ ck install package --tags=lib,armnn,onnx,opencl
```

<a name="onnx_neon_opencl"></a>
### Backends: Neon, OpenCL
```
$ ck install package --tags=lib,armnn,onnx,neon,opencl
```

