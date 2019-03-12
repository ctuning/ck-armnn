# ArmNN-TFLite image classification program

## Compile with a particular backend

### Reference
```
$ ck compile program:image-classification-armnn-tflite
```

### Neon
```
$ ck compile program:image-classification-armnn-tflite --env.USE_NEON
```

### OpenCL
```
$ ck compile program:image-classification-armnn-tflite --env.USE_OPENCL
```

### Neon and OpenCL
```
$ ck compile program:image-classification-armnn-tflite --env.USE_NEON --env.USE_OPENCL
```

## Run

**NB:** Must use the same backend options as for compilation.

### Neon
```
$ ck run program:image-classification-armnn-tflite \
--env.CK_BATCH_COUNT=5 \
--env.USE_NEON
```
**where:**
 - `CK_BATCH_COUNT` - the number of batches to evaluate (1 by default).
 - `USE_NEON` - enable CPU acceleration.
 - `USE_OPENCL` - enable GPU acceleration.
