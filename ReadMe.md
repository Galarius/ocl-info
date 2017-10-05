# ocl-info

[![Build Status](https://travis-ci.org/Galarius/ocl-info.svg?branch=master)](https://travis-ci.org/Galarius/ocl-info)

Command-line tool to display information about available OpenCL platforms and devices.

Created for [OpenCL Extension for VS Code](https://marketplace.visualstudio.com/items?itemName=galarius.vscode-opencl).

## Prerequisites

* cmake

## How to install

```
mkdir build && cd build
cmake ..
make && make install
```

## How to use

Input `oclinfo` to display help message:

```
OVERVIEW:
        Get info about OpenCL platforms/devices
USAGE:
        ./oclinfo [option]
OPTIONS:
        -h, --help                      Show this help message
        -np,--num-platforms             Show number of available platforms
        -nd,--num-devices               Show number of available devices
        -ps,--platforms                 Show info about platforms
        -ds,--devices                   Show info about devices
        -pds,--platforms-devices        Show info about platforms and devices
        -cl,--cl-names                  Show platform/device fields with cl names
```

Input `oclinfo -pds` to display full info about platforms/devices, e.g.:

```
Platform(s): 1
Platform # 1
============
         Platform name: Apple
         OpenCL version: OpenCL 1.2 (May 26 2017 12:59:48)
         Platform vendor: Apple
         OpenCL profile: FULL_PROFILE
         Extensions: cl_APPLE_SetMemObjectDestructor cl_APPLE_ContextLoggingFunctions cl_APPLE_clut cl_APPLE_query_kernel_names cl_APPLE_gl_sharing cl_khr_gl_event
         Device(s): 2
Device # 1
----------
                 Address space size: 64
                 Device is available: Yes
                 Compiler is available: Yes
                 Double precision floating-point capability: denorms are supported; INF and NaNs are supported; round to nearest even rounding mode supported; round to zero rounding mode supported; round to +ve and -ve infinity rounding modes supported; IEEE754-2008 fused multiply-add is supported
                 Little endian device: Yes
                 Error correction support: No
                 Execution capabilities: The OpenCL device can execute OpenCL kernels; The OpenCL device can execute native kernels
                 Extensions: cl_APPLE_SetMemObjectDestructor cl_APPLE_ContextLoggingFunctions cl_APPLE_clut cl_APPLE_query_kernel_names cl_APPLE_gl_sharing cl_khr_gl_event cl_khr_fp64 cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_byte_addressable_store cl_khr_int64_base_atomics cl_khr_int64_extended_atomics cl_khr_3d_image_writes cl_khr_image2d_from_buffer cl_APPLE_fp64_basic_ops cl_APPLE_fixed_alpha_channel_orders cl_APPLE_biased_fixed_point_image_formats cl_APPLE_command_queue_priority
                 Size of global memory cache (in bytes): 64
                 Type of global memory cache: Read-Write cache
                 Size of global memory cache line (in bytes): 3145728
                 Size of global device memory (in bytes): 8589934592
                 Half precision floating-point capability: round to zero rounding mode supported; round to +ve and -ve infinity rounding modes supported
                 Images are supported: Yes
                 Max height of 2D image (in pixels): 8192
                 Max width of 2D image (in pixels): 8192
                 Max depth of 3D image (in pixels): 2048
                 Max height of 3D image (in pixels): 2048
                 Max width of 3D image (in pixels): 2048
                 Size of local memory arena (in bytes): 32768
                 Type of local memory: Global memory storage
                 Maximum configured clock frequency (in MHz): 2600
                 The number of parallel compute cores: 4
                 Max number of __constant arguments in a kernel: 8
                 Max size of a constant buffer allocation (in bytes): 65536
                 Max size of memory object allocation (in bytes): 2147483648
                 Max size of kernel arguments (in bytes): 4096
                 Max number of simultaneously read image objects: 128
                 Maximum number of samplers: 16
                 Maximum number of work-items in a work-group: 1024
                 Maximum dimensions that specify work-item IDs: 3
                 Maximum number of work-items in each dimension: 1024, 1, 1
                 Max number of simultaneously written image objects: 8
                 Alignment of the base address of any allocated memory object (in bits): 1024
                 Minimum alignment for any data type (in bytes): 128
                 Device name: Intel(R) Core(TM) i5-4278U CPU @ 2.60GHz
                 Preferred native vector width size for char type: 16
                 Preferred native vector width size for short type: 8
                 Preferred native vector width size for int type: 4
                 Preferred native vector width size for long type: 2
                 Preferred native vector width size for float type: 4
                 Preferred native vector width size for double type: 2
                 OpenCL profile: FULL_PROFILE
                 Resolution of device timer (in nanoseconds): 1
                 Supported command-queue properties: The profiling of commands is enabled
                 Single precision floating-point capability: denorms are supported; INF and NaNs are supported; round to nearest even rounding mode supported; round to zero rounding mode supported; round to +ve and -ve infinity rounding modes supported; IEEE754-2008 fused multiply-add is supported
                 OpenCL device type: CPU
                 Vendor name: Intel
                 Device vendor identifier: 4294967295
                 OpenCL version: OpenCL 1.2
                 OpenCL software driver version: 1.1
Device # 2
----------
                 Address space size: 64
                 Device is available: Yes
                 Compiler is available: Yes
                 Double precision floating-point capability:
                 Little endian device: Yes
                 Error correction support: No
                 Execution capabilities: The OpenCL device can execute OpenCL kernels
                 Extensions: cl_APPLE_SetMemObjectDestructor cl_APPLE_ContextLoggingFunctions cl_APPLE_clut cl_APPLE_query_kernel_names cl_APPLE_gl_sharing cl_khr_gl_event cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_byte_addressable_store cl_khr_image2d_from_buffer cl_khr_gl_depth_images cl_khr_depth_images cl_khr_3d_image_writes
                 Size of global memory cache (in bytes): 0
                 Type of global memory cache: None
                 Size of global memory cache line (in bytes): 0
                 Size of global device memory (in bytes): 1610612736
                 Half precision floating-point capability: round to zero rounding mode supported; round to +ve and -ve infinity rounding modes supported
                 Images are supported: Yes
                 Max height of 2D image (in pixels): 16384
                 Max width of 2D image (in pixels): 16384
                 Max depth of 3D image (in pixels): 2048
                 Max height of 3D image (in pixels): 2048
                 Max width of 3D image (in pixels): 2048
                 Size of local memory arena (in bytes): 65536
                 Type of local memory: Local memory storage
                 Maximum configured clock frequency (in MHz): 1100
                 The number of parallel compute cores: 40
                 Max number of __constant arguments in a kernel: 8
                 Max size of a constant buffer allocation (in bytes): 65536
                 Max size of memory object allocation (in bytes): 402653184
                 Max size of kernel arguments (in bytes): 1024
                 Max number of simultaneously read image objects: 128
                 Maximum number of samplers: 16
                 Maximum number of work-items in a work-group: 512
                 Maximum dimensions that specify work-item IDs: 3
                 Maximum number of work-items in each dimension: 512, 512, 512
                 Max number of simultaneously written image objects: 8
                 Alignment of the base address of any allocated memory object (in bits): 1024
                 Minimum alignment for any data type (in bytes): 128
                 Device name: Iris
                 Preferred native vector width size for char type: 1
                 Preferred native vector width size for short type: 1
                 Preferred native vector width size for int type: 1
                 Preferred native vector width size for long type: 1
                 Preferred native vector width size for float type: 1
                 Preferred native vector width size for double type: 0
                 OpenCL profile: FULL_PROFILE
                 Resolution of device timer (in nanoseconds): 80
                 Supported command-queue properties: The profiling of commands is enabled
                 Single precision floating-point capability: INF and NaNs are supported; round to nearest even rounding mode supported; round to zero rounding mode supported; round to +ve and -ve infinity rounding modes supported; IEEE754-2008 fused multiply-add is supported
                 OpenCL device type: GPU
                 Vendor name: Intel
                 Device vendor identifier: 16925952
                 OpenCL version: OpenCL 1.2
                 OpenCL software driver version: 1.2(Jun 15 2017 18:45:12)
```

To display standart names with `CL_` prefix input `oclinfo -cl -pds`:

```
Platform(s): 1
Platform # 1
============
         CL_PLATFORM_NAME: Apple
         CL_PLATFORM_VERSION: OpenCL 1.2 (May 26 2017 12:59:48)
         CL_PLATFORM_VENDOR: Apple
         CL_PLATFORM_PROFILE: FULL_PROFILE
         CL_PLATFORM_EXTENSIONS: cl_APPLE_SetMemObjectDestructor cl_APPLE_ContextLoggingFunctions cl_APPLE_clut cl_APPLE_query_kernel_names cl_APPLE_gl_sharing cl_khr_gl_event
         Device(s): 2
Device # 1
----------
                 CL_DEVICE_ADDRESS_BITS: 64
                 CL_DEVICE_AVAILABLE: CL_TRUE
                 CL_DEVICE_COMPILER_AVAILABLE: CL_TRUE
                 CL_DEVICE_DOUBLE_FP_CONFIG: CL_FP_DENORM; CL_FP_INF_NAN; CL_FP_ROUND_TO_NEAREST; CL_FP_ROUND_TO_ZERO; CL_FP_ROUND_TO_INF; CL_FP_FMA
                 CL_DEVICE_ENDIAN_LITTLE: CL_TRUE
                 CL_DEVICE_ERROR_CORRECTION_SUPPORT: CL_FALSE
                 CL_DEVICE_EXECUTION_CAPABILITIES: CL_EXEC_KERNEL; CL_EXEC_NATIVE_KERNEL
                 CL_DEVICE_EXTENSIONS: cl_APPLE_SetMemObjectDestructor cl_APPLE_ContextLoggingFunctions cl_APPLE_clut cl_APPLE_query_kernel_names cl_APPLE_gl_sharing cl_khr_gl_event cl_khr_fp64 cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomicscl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_byte_addressable_store cl_khr_int64_base_atomics cl_khr_int64_extended_atomics cl_khr_3d_image_writes cl_khr_image2d_from_buffer cl_APPLE_fp64_basic_ops cl_APPLE_fixed_alpha_channel_orderscl_APPLE_biased_fixed_point_image_formats cl_APPLE_command_queue_priority
                 CL_DEVICE_GLOBAL_MEM_CACHE_SIZE: 64
                 CL_DEVICE_GLOBAL_MEM_CACHE_TYPE: CL_READ_WRITE_CACHE
                 CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE: 3145728
                 CL_DEVICE_GLOBAL_MEM_SIZE: 8589934592
                 CL_DEVICE_HALF_FP_CONFIG: CL_FP_ROUND_TO_ZERO; CL_FP_ROUND_TO_INF
                 CL_DEVICE_IMAGE_SUPPORT: CL_TRUE
                 CL_DEVICE_IMAGE2D_MAX_HEIGHT: 8192
                 CL_DEVICE_IMAGE2D_MAX_WIDTH: 8192
                 CL_DEVICE_IMAGE3D_MAX_DEPTH: 2048
                 CL_DEVICE_IMAGE3D_MAX_HEIGHT: 2048
                 CL_DEVICE_IMAGE3D_MAX_WIDTH: 2048
                 CL_DEVICE_LOCAL_MEM_SIZE: 32768
                 CL_DEVICE_LOCAL_MEM_TYPE: CL_GLOBAL
                 CL_DEVICE_MAX_CLOCK_FREQUENCY: 2600
                 CL_DEVICE_MAX_COMPUTE_UNITS: 4
                 CL_DEVICE_MAX_CONSTANT_ARGS: 8
                 CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE: 65536
                 CL_DEVICE_MAX_MEM_ALLOC_SIZE: 2147483648
                 CL_DEVICE_MAX_PARAMETER_SIZE: 4096
                 CL_DEVICE_MAX_READ_IMAGE_ARGS: 128
                 CL_DEVICE_MAX_SAMPLERS: 16
                 CL_DEVICE_MAX_WORK_GROUP_SIZE: 1024
                 CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS: 3
                 CL_DEVICE_MAX_WORK_ITEM_SIZES: 1024, 1, 1
                 CL_DEVICE_MAX_WRITE_IMAGE_ARGS: 8
                 CL_DEVICE_MEM_BASE_ADDR_ALIGN: 1024
                 CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE: 128
                 CL_DEVICE_NAME: Intel(R) Core(TM) i5-4278U CPU @ 2.60GHz
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR: 16
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT: 8
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT: 4
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG: 2
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT: 4
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE: 2
                 CL_DEVICE_PROFILE: FULL_PROFILE
                 CL_DEVICE_PROFILING_TIMER_RESOLUTION: 1
                 CL_DEVICE_QUEUE_PROPERTIES: CL_QUEUE_PROFILING_ENABLE
                 CL_DEVICE_SINGLE_FP_CONFIG: CL_FP_DENORM; CL_FP_INF_NAN; CL_FP_ROUND_TO_NEAREST; CL_FP_ROUND_TO_ZERO; CL_FP_ROUND_TO_INF; CL_FP_FMA
                 CL_DEVICE_TYPE: CL_DEVICE_TYPE_CPU
                 CL_DEVICE_VENDOR: Intel
                 CL_DEVICE_VENDOR_ID: 4294967295
                 CL_DEVICE_VERSION: OpenCL 1.2
                 CL_DRIVER_VERSION: 1.1
Device # 2
----------
                 CL_DEVICE_ADDRESS_BITS: 64
                 CL_DEVICE_AVAILABLE: CL_TRUE
                 CL_DEVICE_COMPILER_AVAILABLE: CL_TRUE
                 CL_DEVICE_DOUBLE_FP_CONFIG:
                 CL_DEVICE_ENDIAN_LITTLE: CL_TRUE
                 CL_DEVICE_ERROR_CORRECTION_SUPPORT: CL_FALSE
                 CL_DEVICE_EXECUTION_CAPABILITIES: CL_EXEC_KERNEL
                 CL_DEVICE_EXTENSIONS: cl_APPLE_SetMemObjectDestructor cl_APPLE_ContextLoggingFunctions cl_APPLE_clut cl_APPLE_query_kernel_names cl_APPLE_gl_sharing cl_khr_gl_event cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_byte_addressable_store cl_khr_image2d_from_buffer cl_khr_gl_depth_images cl_khr_depth_images cl_khr_3d_image_writes
                 CL_DEVICE_GLOBAL_MEM_CACHE_SIZE: 0
                 CL_DEVICE_GLOBAL_MEM_CACHE_TYPE: CL_NONE
                 CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE: 0
                 CL_DEVICE_GLOBAL_MEM_SIZE: 1610612736
                 CL_DEVICE_HALF_FP_CONFIG: CL_FP_ROUND_TO_ZERO; CL_FP_ROUND_TO_INF
                 CL_DEVICE_IMAGE_SUPPORT: CL_TRUE
                 CL_DEVICE_IMAGE2D_MAX_HEIGHT: 16384
                 CL_DEVICE_IMAGE2D_MAX_WIDTH: 16384
                 CL_DEVICE_IMAGE3D_MAX_DEPTH: 2048
                 CL_DEVICE_IMAGE3D_MAX_HEIGHT: 2048
                 CL_DEVICE_IMAGE3D_MAX_WIDTH: 2048
                 CL_DEVICE_LOCAL_MEM_SIZE: 65536
                 CL_DEVICE_LOCAL_MEM_TYPE: CL_LOCAL
                 CL_DEVICE_MAX_CLOCK_FREQUENCY: 1100
                 CL_DEVICE_MAX_COMPUTE_UNITS: 40
                 CL_DEVICE_MAX_CONSTANT_ARGS: 8
                 CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE: 65536
                 CL_DEVICE_MAX_MEM_ALLOC_SIZE: 402653184
                 CL_DEVICE_MAX_PARAMETER_SIZE: 1024
                 CL_DEVICE_MAX_READ_IMAGE_ARGS: 128
                 CL_DEVICE_MAX_SAMPLERS: 16
                 CL_DEVICE_MAX_WORK_GROUP_SIZE: 512
                 CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS: 3
                 CL_DEVICE_MAX_WORK_ITEM_SIZES: 512, 512, 512
                 CL_DEVICE_MAX_WRITE_IMAGE_ARGS: 8
                 CL_DEVICE_MEM_BASE_ADDR_ALIGN: 1024
                 CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE: 128
                 CL_DEVICE_NAME: Iris
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR: 1
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT: 1
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT: 1
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG: 1
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT: 1
                 CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE: 0
                 CL_DEVICE_PROFILE: FULL_PROFILE
                 CL_DEVICE_PROFILING_TIMER_RESOLUTION: 80
                 CL_DEVICE_QUEUE_PROPERTIES: CL_QUEUE_PROFILING_ENABLE
                 CL_DEVICE_SINGLE_FP_CONFIG: CL_FP_INF_NAN; CL_FP_ROUND_TO_NEAREST; CL_FP_ROUND_TO_ZERO; CL_FP_ROUND_TO_INF; CL_FP_FMA
                 CL_DEVICE_TYPE: CL_DEVICE_TYPE_GPU
                 CL_DEVICE_VENDOR: Intel
                 CL_DEVICE_VENDOR_ID: 16925952
                 CL_DEVICE_VERSION: OpenCL 1.2
                 CL_DRIVER_VERSION: 1.2(Jun 15 2017 18:45:12)
```