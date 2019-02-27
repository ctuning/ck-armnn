# TensorFlow Lite image classification program

This program uses a statically linked [TensorFlow Lite](https://www.tensorflow.org/lite/) library.

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
