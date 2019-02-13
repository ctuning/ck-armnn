# ArmNN installation

Frontend/backend | Reference | Neon | OpenCL | Neon + OpenCL |
-|-|-|-|-|
[TensorFlow](https://www.tensorflow.org/) | (default)      |                 `USE_NEON=1` |                 `USE_OPENCL=1` |                 `USE_NEON=1`, `USE_OPENCL=1` |
[TFLite](https://www.tensorflow.org/lite) | `USE_TFLITE=1` | `USE_TFLITE=1`, `USE_NEON=1` | `USE_TFLITE=1`, `USE_OPENCL=1` | `USE_TFLITE=1`, `USE_NEON=1`, `USE_OPENCL=1` |
[ONNX](https://onnx.ai/)                  | N/A            | N/A                          | N/A                            | N/A                                          |

**NB:** Currently, the order of builds is important. Otherwise, CK will try to reuse environments, which will screw them up.

## Frontend: TensorFlow

### Backend: Reference
```
$ ck install package --tags=lib,armnn
```

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

## Frontend: ONNX
**TODO**

