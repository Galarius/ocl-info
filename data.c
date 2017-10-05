#include "data.h"

/* platform info */
const cl_platform_info fields_platform_info[] = {CL_PLATFORM_PROFILE, CL_PLATFORM_VERSION, CL_PLATFORM_NAME, CL_PLATFORM_VENDOR, CL_PLATFORM_EXTENSIONS};
const char *cl_names_platform_info[] = {"CL_PLATFORM_PROFILE", "CL_PLATFORM_VERSION", "CL_PLATFORM_NAME", "CL_PLATFORM_VENDOR", "CL_PLATFORM_EXTENSIONS"};
const char *names_platform_info[] = {"OpenCL profile", "OpenCL version", "Platform name", "Platform vendor", "Extensions"};
const cl_uint order_platform_info[] = { 2, 1, 3, 0, 4};
const cl_uint count_platform_info = sizeof(fields_platform_info) / sizeof(fields_platform_info[0]);

/* device info */
const cl_device_info fields_device_info[] = {CL_DEVICE_ADDRESS_BITS, CL_DEVICE_AVAILABLE, CL_DEVICE_COMPILER_AVAILABLE, CL_DEVICE_DOUBLE_FP_CONFIG, CL_DEVICE_ENDIAN_LITTLE, CL_DEVICE_ERROR_CORRECTION_SUPPORT, CL_DEVICE_EXECUTION_CAPABILITIES, CL_DEVICE_EXTENSIONS, CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, CL_DEVICE_GLOBAL_MEM_SIZE, CL_DEVICE_HALF_FP_CONFIG, CL_DEVICE_IMAGE_SUPPORT, CL_DEVICE_IMAGE2D_MAX_HEIGHT, CL_DEVICE_IMAGE2D_MAX_WIDTH, CL_DEVICE_IMAGE3D_MAX_DEPTH, CL_DEVICE_IMAGE3D_MAX_HEIGHT, CL_DEVICE_IMAGE3D_MAX_WIDTH, CL_DEVICE_LOCAL_MEM_SIZE, CL_DEVICE_LOCAL_MEM_TYPE, CL_DEVICE_MAX_CLOCK_FREQUENCY, CL_DEVICE_MAX_COMPUTE_UNITS, CL_DEVICE_MAX_CONSTANT_ARGS, CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, CL_DEVICE_MAX_MEM_ALLOC_SIZE, CL_DEVICE_MAX_PARAMETER_SIZE, CL_DEVICE_MAX_READ_IMAGE_ARGS, CL_DEVICE_MAX_SAMPLERS, CL_DEVICE_MAX_WORK_GROUP_SIZE, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, CL_DEVICE_MAX_WORK_ITEM_SIZES, CL_DEVICE_MAX_WRITE_IMAGE_ARGS, CL_DEVICE_MEM_BASE_ADDR_ALIGN, CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE, CL_DEVICE_NAME, CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, CL_DEVICE_PROFILE, CL_DEVICE_PROFILING_TIMER_RESOLUTION, CL_DEVICE_QUEUE_PROPERTIES, CL_DEVICE_SINGLE_FP_CONFIG, CL_DEVICE_TYPE, CL_DEVICE_VENDOR, CL_DEVICE_VENDOR_ID, CL_DEVICE_VERSION, CL_DRIVER_VERSION};
const char *cl_names_device_info[] = {"CL_DEVICE_ADDRESS_BITS", "CL_DEVICE_AVAILABLE", "CL_DEVICE_COMPILER_AVAILABLE", "CL_DEVICE_DOUBLE_FP_CONFIG", "CL_DEVICE_ENDIAN_LITTLE", "CL_DEVICE_ERROR_CORRECTION_SUPPORT", "CL_DEVICE_EXECUTION_CAPABILITIES", "CL_DEVICE_EXTENSIONS", "CL_DEVICE_GLOBAL_MEM_CACHE_SIZE", "CL_DEVICE_GLOBAL_MEM_CACHE_TYPE", "CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE", "CL_DEVICE_GLOBAL_MEM_SIZE", "CL_DEVICE_HALF_FP_CONFIG", "CL_DEVICE_IMAGE_SUPPORT", "CL_DEVICE_IMAGE2D_MAX_HEIGHT", "CL_DEVICE_IMAGE2D_MAX_WIDTH", "CL_DEVICE_IMAGE3D_MAX_DEPTH", "CL_DEVICE_IMAGE3D_MAX_HEIGHT", "CL_DEVICE_IMAGE3D_MAX_WIDTH", "CL_DEVICE_LOCAL_MEM_SIZE", "CL_DEVICE_LOCAL_MEM_TYPE", "CL_DEVICE_MAX_CLOCK_FREQUENCY", "CL_DEVICE_MAX_COMPUTE_UNITS", "CL_DEVICE_MAX_CONSTANT_ARGS", "CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE", "CL_DEVICE_MAX_MEM_ALLOC_SIZE", "CL_DEVICE_MAX_PARAMETER_SIZE", "CL_DEVICE_MAX_READ_IMAGE_ARGS", "CL_DEVICE_MAX_SAMPLERS", "CL_DEVICE_MAX_WORK_GROUP_SIZE", "CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS", "CL_DEVICE_MAX_WORK_ITEM_SIZES", "CL_DEVICE_MAX_WRITE_IMAGE_ARGS", "CL_DEVICE_MEM_BASE_ADDR_ALIGN", "CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE", "CL_DEVICE_NAME", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT", "CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE", "CL_DEVICE_PROFILE", "CL_DEVICE_PROFILING_TIMER_RESOLUTION", "CL_DEVICE_QUEUE_PROPERTIES", "CL_DEVICE_SINGLE_FP_CONFIG", "CL_DEVICE_TYPE", "CL_DEVICE_VENDOR", "CL_DEVICE_VENDOR_ID", "CL_DEVICE_VERSION", "CL_DRIVER_VERSION"};
const char *names_device_info[] = {"Address space size", "Device is available", "Compiler is available", "Double precision floating-point capability", "Little endian device", "Error correction support", "Execution capabilities", "Extensions", "Size of global memory cache (in bytes)", "Type of global memory cache", "Size of global memory cache line (in bytes)", "Size of global device memory (in bytes)", "Half precision floating-point capability", "Images are supported", "Max height of 2D image (in pixels)", "Max width of 2D image (in pixels)", "Max depth of 3D image (in pixels)", "Max height of 3D image (in pixels)", "Max width of 3D image (in pixels)", "Size of local memory arena (in bytes)", "Type of local memory", "Maximum configured clock frequency (in MHz)", "The number of parallel compute cores", "Max number of __constant arguments in a kernel", "Max size of a constant buffer allocation (in bytes)", "Max size of memory object allocation (in bytes)", "Max size of kernel arguments (in bytes)", "Max number of simultaneously read image objects", "Maximum number of samplers", "Maximum number of work-items in a work-group", "Maximum dimensions that specify work-item IDs", "Maximum number of work-items in each dimension", "Max number of simultaneously written image objects", "Alignment of the base address of any allocated memory object (in bits)", "Minimum alignment for any data type (in bytes)", "Device name", "Preferred native vector width size for char type", "Preferred native vector width size for short type", "Preferred native vector width size for int type", "Preferred native vector width size for long type", "Preferred native vector width size for float type", "Preferred native vector width size for double type", "OpenCL profile", "Resolution of device timer (in nanoseconds)", "Supported command-queue properties", "Single precision floating-point capability", "OpenCL device type", "Vendor name", "Device vendor identifier", "OpenCL version", "OpenCL software driver version"};
const cl_uint types_device_info[] = {t_uint, t_bool, t_bool, t_device_fp_config, t_bool, t_bool, t_device_exec_capabilities, t_char, t_ulong, t_device_mem_cache_type, t_uint, t_ulong, t_device_fp_config, t_bool, t_size_t, t_size_t, t_size_t, t_size_t, t_size_t, t_ulong, t_device_local_mem_type, t_uint, t_uint, t_uint, t_ulong, t_ulong, t_size_t, t_uint, t_uint, t_size_t, t_uint, t_size_t_array, t_uint, t_uint, t_uint, t_char, t_uint, t_uint, t_uint, t_uint, t_uint, t_uint, t_char, t_size_t, t_command_queue_properties, t_device_fp_config, t_device_type, t_char, t_uint, t_char, t_char};
const cl_uint order_device_info[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
const cl_uint count_device_info = sizeof(fields_device_info) / sizeof(fields_device_info[0]);

/* cl_device_fp_config */
const cl_uint fields_cl_device_fp_config[] = {CL_FP_DENORM, CL_FP_INF_NAN, CL_FP_ROUND_TO_NEAREST, CL_FP_ROUND_TO_ZERO, CL_FP_ROUND_TO_INF, CL_FP_FMA};
const char *cl_names_cl_device_fp_config[] = {"CL_FP_DENORM", "CL_FP_INF_NAN", "CL_FP_ROUND_TO_NEAREST", "CL_FP_ROUND_TO_ZERO", "CL_FP_ROUND_TO_INF", "CL_FP_FMA"};
const char *names_cl_device_fp_config[] = {"denorms are supported", "INF and NaNs are supported", "round to nearest even rounding mode supported", "round to zero rounding mode supported", "round to +ve and -ve infinity rounding modes supported", "IEEE754-2008 fused multiply-add is supported"};
const cl_uint count_cl_device_fp_config = sizeof(fields_cl_device_fp_config) / sizeof(fields_cl_device_fp_config[0]);

/* cl_bool */
const cl_uint fields_cl_bool[] = {CL_TRUE, CL_FALSE};
const char *cl_names_cl_bool[] = {"CL_TRUE", "CL_FALSE"};
const char *names_cl_bool[] = {"Yes", "No"};
const cl_uint count_cl_bool = sizeof(fields_cl_bool) / sizeof(fields_cl_bool[0]);

/* cl_device_exec_capabilities */
const cl_uint fields_cl_device_exec_capabilities[] = {CL_EXEC_KERNEL, CL_EXEC_NATIVE_KERNEL};
const char *cl_names_cl_device_exec_capabilities[] = {"CL_EXEC_KERNEL", "CL_EXEC_NATIVE_KERNEL"};
const char *names_cl_device_exec_capabilities[] = {"The OpenCL device can execute OpenCL kernels", "The OpenCL device can execute native kernels"};
const cl_uint count_cl_device_exec_capabilities = sizeof(fields_cl_device_exec_capabilities) / sizeof(fields_cl_device_exec_capabilities[0]);

/* cl_device_mem_cache_type */
const cl_uint fields_cl_device_mem_cache_type[] = {CL_NONE, CL_READ_ONLY_CACHE, CL_READ_WRITE_CACHE};
const char *cl_names_cl_device_mem_cache_type[] = {"CL_NONE", "CL_READ_ONLY_CACHE", "CL_READ_WRITE_CACHE"};
const char *names_cl_device_mem_cache_type[] = {"None", "Read-Only cache", "Read-Write cache"};
const cl_uint count_cl_device_mem_cache_type = sizeof(fields_cl_device_mem_cache_type) / sizeof(fields_cl_device_mem_cache_type[0]);

/* cl_command_queue_properties */
const cl_uint fields_cl_command_queue_properties[] = {CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, CL_QUEUE_PROFILING_ENABLE};
const char *cl_names_cl_command_queue_properties[] = {"CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE", "CL_QUEUE_PROFILING_ENABLE"};
const char *names_cl_command_queue_properties[] = {"Commands are executed out-of-order", "The profiling of commands is enabled"};
const cl_uint count_cl_command_queue_properties = sizeof(fields_cl_command_queue_properties) / sizeof(fields_cl_command_queue_properties[0]);

/* cl_device_local_mem_type */
const cl_uint fields_cl_device_local_mem_type[] = {CL_LOCAL, CL_GLOBAL};
const char *cl_names_cl_device_local_mem_type[] = {"CL_LOCAL", "CL_GLOBAL"};
const char *names_cl_device_local_mem_type[] = {"Local memory storage", "Global memory storage"};
const cl_uint count_cl_device_local_mem_type = sizeof(fields_cl_device_local_mem_type) / sizeof(fields_cl_device_local_mem_type[0]);

/* cl_device_type */
const cl_uint fields_cl_device_type[] = {CL_DEVICE_TYPE_CPU, CL_DEVICE_TYPE_GPU, CL_DEVICE_TYPE_ACCELERATOR, CL_DEVICE_TYPE_DEFAULT};
const char *cl_names_cl_device_type[] = {"CL_DEVICE_TYPE_CPU", "CL_DEVICE_TYPE_GPU", "CL_DEVICE_TYPE_ACCELERATOR", "CL_DEVICE_TYPE_DEFAULT"};
const char *names_cl_device_type[] = {"CPU", "GPU", "Accelerator", "Default"};
const cl_uint count_cl_device_type = sizeof(fields_cl_device_type) / sizeof(fields_cl_device_type[0]);