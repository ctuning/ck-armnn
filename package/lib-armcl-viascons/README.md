# This package installs a desired version of ARM Compute Library

Selection of both the desired release { `release` | `rel.18.08` | `rel.19.02` | `dev` } and the accelerator support (`neon`? and `opencl`?) is now done via combining relevant tags.

# Examples:
```
ck install package --tags=lib,armcl,viascons,rel.18.08			# Release 18.08 without acceleration (reference implementation)

ck install package --tags=lib,armcl,viascons,rel.19.02,neon		# Release 19.02 with CPU acceleration

ck install package --tags=lib,armcl,viascons,release,opencl		# Current release with GPU acceleration

ck install package --tags=lib,armcl,viascons,dev,neon,opencl	# Development release with CPU and GPU acceleration
```

# Notes:
1. Release-related tags are all mutually exclusive, please choose exactly one.

2. If you are intending to simultaneously maintain versions with and without `neon`/`opencl` support, start compiling ones without the support, gradually adding these capabilities. It is currently a known CK constraint that a new package should not be added with a subset of tags of another currently installed environment.