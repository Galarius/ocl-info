#include "data.h"

/* platform info */
const cl_platform_info fields_pinfo[] = {CL_PLATFORM_PROFILE, CL_PLATFORM_VERSION, CL_PLATFORM_NAME, CL_PLATFORM_VENDOR, CL_PLATFORM_EXTENSIONS};
const char *names_pinfo[] = {"CL_PLATFORM_PROFILE", "CL_PLATFORM_VERSION", "CL_PLATFORM_NAME", "CL_PLATFORM_VENDOR", "CL_PLATFORM_EXTENSIONS"};
const char *descs_pinfo[] = {"OpenCL profile", "OpenCL version", "Platform name", "Platform vendor", "Extensions"};
const cl_uint order_pinfo[] = { 2, 1, 3, 0, 4};
const cl_uint n_pinfo = sizeof(fields_pinfo) / sizeof(fields_pinfo[0]);

/* device info */
const cl_device_info fields_dinfo[] = {    
    /*0*/ CL_DEVICE_ADDRESS_BITS,
    /*1*/ CL_DEVICE_AVAILABLE,
    /*2*/ CL_DEVICE_COMPILER_AVAILABLE,
    /*3*/ CL_DEVICE_DOUBLE_FP_CONFIG,
    /*4*/ CL_DEVICE_ENDIAN_LITTLE,
    /*5*/ CL_DEVICE_ERROR_CORRECTION_SUPPORT,
    /*6*/ CL_DEVICE_EXECUTION_CAPABILITIES,
    /*7*/ CL_DEVICE_EXTENSIONS,
    /*8*/ CL_DEVICE_GLOBAL_MEM_CACHE_SIZE,
    /*9*/ CL_DEVICE_GLOBAL_MEM_CACHE_TYPE,
    /*10*/ CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE,
    /*11*/ CL_DEVICE_GLOBAL_MEM_SIZE,
    /*12*/ CL_DEVICE_HALF_FP_CONFIG,
    /*13*/ CL_DEVICE_IMAGE_SUPPORT,
    /*14*/ CL_DEVICE_IMAGE2D_MAX_HEIGHT,
    /*15*/ CL_DEVICE_IMAGE2D_MAX_WIDTH,
    /*16*/ CL_DEVICE_IMAGE3D_MAX_DEPTH,
    /*17*/ CL_DEVICE_IMAGE3D_MAX_HEIGHT,
    /*18*/ CL_DEVICE_IMAGE3D_MAX_WIDTH,
    /*19*/ CL_DEVICE_LOCAL_MEM_SIZE,
    /*20*/ CL_DEVICE_LOCAL_MEM_TYPE,
    /*21*/ CL_DEVICE_MAX_CLOCK_FREQUENCY,
    /*22*/ CL_DEVICE_MAX_COMPUTE_UNITS,
    /*23*/ CL_DEVICE_MAX_CONSTANT_ARGS,
    /*24*/ CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE,
    /*25*/ CL_DEVICE_MAX_MEM_ALLOC_SIZE,
    /*26*/ CL_DEVICE_MAX_PARAMETER_SIZE,
    /*27*/ CL_DEVICE_MAX_READ_IMAGE_ARGS,
    /*28*/ CL_DEVICE_MAX_SAMPLERS,
    /*29*/ CL_DEVICE_MAX_WORK_GROUP_SIZE,
    /*30*/ CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS,
    /*31*/ CL_DEVICE_MAX_WORK_ITEM_SIZES,
    /*32*/ CL_DEVICE_MAX_WRITE_IMAGE_ARGS,
    /*33*/ CL_DEVICE_MEM_BASE_ADDR_ALIGN,
    /*34*/ CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE,
    /*35*/ CL_DEVICE_NAME,
    /*36*/ CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR,
    /*37*/ CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT,
    /*38*/ CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT,
    /*39*/ CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG,
    /*40*/ CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT,
    /*41*/ CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE,
    /*42*/ CL_DEVICE_PROFILE,
    /*43*/ CL_DEVICE_PROFILING_TIMER_RESOLUTION,
    /*44*/ CL_DEVICE_QUEUE_PROPERTIES,
    /*45*/ CL_DEVICE_SINGLE_FP_CONFIG,
    /*46*/ CL_DEVICE_TYPE,
    /*47*/ CL_DEVICE_VENDOR,
    /*48*/ CL_DEVICE_VENDOR_ID,
    /*49*/ CL_DEVICE_VERSION,
    /*50*/ CL_DRIVER_VERSION,
    /*51*/ INFO_SPACE};
const cl_uint order_dinfo[] = {
    35,46,47,49,48,50,
    /* space */ 51,
    28,29,30,31,0,
    /* space */ 51,
    20,19,9,8,10,11,
    /* space */ 51,
    1,2,4,5,13,
    /* space */ 51,
    15,14,18,17,16,
    /* space */ 51,
    43,21,22,23,24,25,26,27,32,33,34,
    /* space */ 51,
    36,37,38,39,40,41,
    /* space */ 51,
    45,3,12,6,44,7};
const char *names_dinfo[] = {
    "CL_DEVICE_ADDRESS_BITS", "CL_DEVICE_AVAILABLE", "CL_DEVICE_COMPILER_AVAILABLE", "CL_DEVICE_DOUBLE_FP_CONFIG", "CL_DEVICE_ENDIAN_LITTLE", "CL_DEVICE_ERROR_CORRECTION_SUPPORT", "CL_DEVICE_EXECUTION_CAPABILITIES", "CL_DEVICE_EXTENSIONS", "CL_DEVICE_GLOBAL_MEM_CACHE_SIZE", "CL_DEVICE_GLOBAL_MEM_CACHE_TYPE", "CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE", "CL_DEVICE_GLOBAL_MEM_SIZE", "CL_DEVICE_HALF_FP_CONFIG", "CL_DEVICE_IMAGE_SUPPORT", "CL_DEVICE_IMAGE2D_MAX_HEIGHT", "CL_DEVICE_IMAGE2D_MAX_WIDTH", "CL_DEVICE_IMAGE3D_MAX_DEPTH", "CL_DEVICE_IMAGE3D_MAX_HEIGHT", "CL_DEVICE_IMAGE3D_MAX_WIDTH", "CL_DEVICE_LOCAL_MEM_SIZE", "CL_DEVICE_LOCAL_MEM_TYPE", "CL_DEVICE_MAX_CLOCK_FREQUENCY", "CL_DEVICE_MAX_COMPUTE_UNITS", "CL_DEVICE_MAX_CONSTANT_ARGS", "CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE", "CL_DEVICE_MAX_MEM_ALLOC_SIZE", "CL_DEVICE_MAX_PARAMETER_SIZE", "CL_DEVICE_MAX_READ_IMAGE_ARGS", "CL_DEVICE_MAX_SAMPLERS", "CL_DEVICE_MAX_WORK_GROUP_SIZE", "CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS", "CL_DEVICE_MAX_WORK_ITEM_SIZES", "CL_DEVICE_MAX_WRITE_IMAGE_ARGS", "CL_DEVICE_MEM_BASE_ADDR_ALIGN", "CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE", "CL_DEVICE_NAME", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE", "CL_DEVICE_PROFILE", "CL_DEVICE_PROFILING_TIMER_RESOLUTION", "CL_DEVICE_QUEUE_PROPERTIES", "CL_DEVICE_SINGLE_FP_CONFIG", "CL_DEVICE_TYPE", "CL_DEVICE_VENDOR", "CL_DEVICE_VENDOR_ID", "CL_DEVICE_VERSION", "CL_DRIVER_VERSION"
};
const char *descs_dinfo[] = {
    "Address space size",
    "Device is available",
    "Compiler is available",
    "Double precision fp capability",
    "Little endian device",
    "Error correction support",
    "Execution capabilities",
    "Extensions",
    "Size of global memory cache (in bytes)",
    "Type of global memory cache",
    "Size of global memory cache line (in bytes)",
    "Size of global device memory (in bytes)",
    "Half precision fp capability",
    "Images are supported",
    "Max height of 2D image (in pixels)",
    "Max width of 2D image (in pixels)",
    "Max depth of 3D image (in pixels)",
    "Max height of 3D image (in pixels)",
    "Max width of 3D image (in pixels)",
    "Size of local memory arena (in bytes)",
    "Type of local memory",
    "Maximum configured clock frequency (in MHz)",
    "The number of parallel compute cores",
    "Max number of __constant arguments in a kernel",
    "Max size of a constant buffer allocation (in bytes)",
    "Max size of memory object allocation (in bytes)",
    "Max size of kernel arguments (in bytes)",
    "Max number of simultaneously read image objects",
    "Maximum number of samplers",
    "Maximum number of work-items in a work-group",
    "Maximum dimensions that specify work-item IDs",
    "Maximum number of work-items in each dimension",
    "Max number of simultaneously written image objects",
    "Alignment of the base address (in bits)",
    "Minimum alignment for any data type (in bytes)",
    "Device name",
    "Preferred native vector width size for char type",
    "Preferred native vector width size for short type",
    "Preferred native vector width size for int type",
    "Preferred native vector width size for long type",
    "Preferred native vector width size for float type",
    "Preferred native vector width size for double type",
    "OpenCL profile",
    "Resolution of device timer (in nanoseconds)",
    "Supported command-queue properties",
    "Single precision floating-point capability",
    "OpenCL device type",
    "Vendor name",
    "Device vendor identifier",
    "OpenCL version",
    "OpenCL software driver version"
};
const cl_uint types_dinfo[] = {InfoTypeUInt, InfoTypeBool, InfoTypeBool, InfoTypeFP, InfoTypeBool, InfoTypeBool, InfoTypeExec, InfoTypeChar, InfoTypeULong, InfoTypeMem, InfoTypeUInt, InfoTypeULong, InfoTypeFP, InfoTypeBool, InfoTypeSizet, InfoTypeSizet, InfoTypeSizet, InfoTypeSizet, InfoTypeSizet, InfoTypeULong, InfoTypeLocMem, InfoTypeUInt, InfoTypeUInt, InfoTypeUInt, InfoTypeULong, InfoTypeULong, InfoTypeSizet, InfoTypeUInt, InfoTypeUInt, InfoTypeSizet, InfoTypeUInt, InfoTypeSizets, InfoTypeUInt, InfoTypeUInt, InfoTypeUInt, InfoTypeChar, InfoTypeUInt, InfoTypeUInt, InfoTypeUInt, InfoTypeUInt, InfoTypeUInt, InfoTypeUInt, InfoTypeChar, InfoTypeSizet, InfoTypeLocQueue, InfoTypeFP, InfoTypeDevice, InfoTypeChar, InfoTypeUInt, InfoTypeChar, InfoTypeChar};

const cl_uint n_dinfo = sizeof(order_dinfo) / sizeof(order_dinfo[0]);

/* cl_device_fp_config */
const cl_uint fields_fp[] = {CL_FP_DENORM, CL_FP_INF_NAN, CL_FP_ROUND_TO_NEAREST, CL_FP_ROUND_TO_ZERO, CL_FP_ROUND_TO_INF, CL_FP_FMA};
const char *names_fp[] = {"CL_FP_DENORM", "CL_FP_INF_NAN", "CL_FP_ROUND_TO_NEAREST", "CL_FP_ROUND_TO_ZERO", "CL_FP_ROUND_TO_INF", "CL_FP_FMA"};
const char *descs_fp[] = {"denorms are supported", "INF and NaNs are supported", "round to nearest even rounding mode supported", "round to zero rounding mode supported", "round to +ve and -ve infinity rounding modes supported", "IEEE754-2008 fused multiply-add is supported"};
const cl_uint n_fp = sizeof(fields_fp) / sizeof(fields_fp[0]);

/* cl_bool */
const cl_uint fields_bool[] = {CL_TRUE, CL_FALSE};
const char *names_bool[] = {"CL_TRUE", "CL_FALSE"};
const char *descs_bool[] = {"Yes", "No"};
const cl_uint count_bool = sizeof(fields_bool) / sizeof(fields_bool[0]);

/* cl_device_exec_capabilities */
const cl_uint fields_exec[] = {CL_EXEC_KERNEL, CL_EXEC_NATIVE_KERNEL};
const char *names_exec[] = {"CL_EXEC_KERNEL", "CL_EXEC_NATIVE_KERNEL"};
const char *descs_exec[] = {"The OpenCL device can execute OpenCL kernels", "The OpenCL device can execute native kernels"};
const cl_uint n_exec = sizeof(fields_exec) / sizeof(fields_exec[0]);

/* cl_device_mem_cache_type */
const cl_uint fields_mem[] = {CL_NONE, CL_READ_ONLY_CACHE, CL_READ_WRITE_CACHE};
const char *names_mem[] = {"CL_NONE", "CL_READ_ONLY_CACHE", "CL_READ_WRITE_CACHE"};
const char *descs_mem[] = {"None", "Read-Only cache", "Read-Write cache"};
const cl_uint n_mem = sizeof(fields_mem) / sizeof(fields_mem[0]);

/* cl_command_queue_properties */
const cl_uint fields_queue[] = {CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, CL_QUEUE_PROFILING_ENABLE};
const char *names_queue[] = {"CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE", "CL_QUEUE_PROFILING_ENABLE"};
const char *descs_queue[] = {"Commands are executed out-of-order", "The profiling of commands is enabled"};
const cl_uint n_queue = sizeof(fields_queue) / sizeof(fields_queue[0]);

/* cl_device_local_mem_type */
const cl_uint fields_loc_mem[] = {CL_LOCAL, CL_GLOBAL};
const char *names_loc_mem[] = {"CL_LOCAL", "CL_GLOBAL"};
const char *descs_loc_mem[] = {"Local memory storage", "Global memory storage"};
const cl_uint n_loc_mem = sizeof(fields_loc_mem) / sizeof(fields_loc_mem[0]);

/* cl_device_type */
const cl_uint fields_device_type[] = {CL_DEVICE_TYPE_CPU, CL_DEVICE_TYPE_GPU, CL_DEVICE_TYPE_ACCELERATOR, CL_DEVICE_TYPE_DEFAULT};
const char *names_device_type[] = {"CL_DEVICE_TYPE_CPU", "CL_DEVICE_TYPE_GPU", "CL_DEVICE_TYPE_ACCELERATOR", "CL_DEVICE_TYPE_DEFAULT"};
const char *descs_device_type[] = {"CPU", "GPU", "Accelerator", "Default"};
const cl_uint n_device_type = sizeof(fields_device_type) / sizeof(fields_device_type[0]);