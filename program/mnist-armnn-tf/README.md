
# Classification program for ArmNN

## Requirements


### ArmNN library
To build this program, you need ArmNN compiled with appropriated API (NEON, OPENCL)

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

**NB:** See corresponding [README](https://github.com/dividiti/ck-armnn/blob/master/README.md) for details

### Dataset and model package

Install a package providing dataset and model files:

```
ck install package --tags=armnn,dataset,model
```

## Compile

```
$ ck compile program:mnist-armnn-tf
```

## Run

```
$ ck run program:mnist-armnn-tf --env.CK_FILE_NUMBER=0 --env.CK_BACKEND="CpuRef"
```
Here:
 - CK_FILE_NUMBER - file number in dataset
 - CK_BACKEND - type of backend
   - CpuRef - default
   - CpuAcc - NEON
   - GpuAcc - OpenCL
   - CpuGpuAcc - NEON + OpenCL

