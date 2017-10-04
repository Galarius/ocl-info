#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __APPLE__
	#include <OpenCL/opencl.h>
#else
	#include <CL/cl.h>
#endif

enum
{
	t_uint,
	t_bool,
	t_device_fp_config,
	t_device_exec_capabilities,
	t_char,
	t_ulong,
	t_device_mem_cache_type,
	t_size_t,
	t_size_t_array,
	t_device_local_mem_type,
	t_command_queue_properties,
	t_device_type
};


size_t max_len(const char* names[], unsigned int count) {
	size_t sum = 0;
	for(int i = 0; i < count; ++i) {
		sum += strlen(names[i]);
	}
	return sum;
}

//----------------------------------------------------------------------------
// Platforms
//----------------------------------------------------------------------------

cl_uint available_platforms()
{
	cl_uint num_platforms;
	clGetPlatformIDs(0, NULL, &num_platforms);
	return num_platforms;
}

cl_uint platforms(cl_platform_id **platforms) 
{
	cl_uint num_platforms = available_platforms();
	if(!num_platforms) {
		fprintf(stderr, "Error: No OpenCL platforms found!\n");
		exit(EXIT_FAILURE);
	}
	*platforms = malloc(sizeof(cl_platform_id) * num_platforms);
	clGetPlatformIDs(num_platforms, *platforms, NULL);
	return num_platforms;
}

void platform_field(cl_platform_id id, cl_platform_info field, char** ret_info)
{
	size_t size = 0;
	clGetPlatformInfo(id, field, 0, NULL, &size);
	*ret_info = malloc(size);
	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}
	clGetPlatformInfo(id, field, size, *ret_info, NULL);
}

void platform_info(cl_platform_id platform)
{
	static const cl_platform_info fields[] = {CL_PLATFORM_PROFILE, CL_PLATFORM_VERSION, CL_PLATFORM_NAME, CL_PLATFORM_VENDOR, CL_PLATFORM_EXTENSIONS};
	static const char *cl_names[] = {"CL_PLATFORM_PROFILE","CL_PLATFORM_VERSION","CL_PLATFORM_NAME","CL_PLATFORM_VENDOR","CL_PLATFORM_EXTENSIONS"};
	static const char *names[] = {"OpenCL profile", "OpenCL version", "Platform name", "Platform vendor", "Extensions"};
	static const unsigned int order[] = { 2, 1, 3, 0, 4};
	static const unsigned int count = sizeof(fields) / sizeof(fields[0]);

	char *info;
	for(cl_uint i = 0; i < count; ++i) {
		platform_field(platform, fields[order[i]], &info);
		printf( "\t %s: %s\n", names[order[i]], info); 
		free(info);
	}
}

//----------------------------------------------------------------------------
// Devices
//----------------------------------------------------------------------------

cl_uint available_devices(cl_platform_id platform)
{
	cl_uint num_devices = 0;
	clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices);
	return num_devices;
}

cl_uint devices(cl_platform_id platform, cl_device_id **devices) 
{
	cl_uint num_devices = 0;
	clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices);
	if(!num_devices) {
		fprintf(stderr, "Error: No OpenCL devices found!\n");
		exit(EXIT_FAILURE);
	}	
	*devices = malloc(sizeof(cl_device_id) * num_devices);
	clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, num_devices, *devices, NULL);
	return num_devices;
}

void device_info_uint(cl_device_id id, cl_device_info field, cl_uint* ret_info)
{
	clGetDeviceInfo(id, field, sizeof(cl_uint), ret_info, NULL);
}

void device_info_bool(cl_device_id id, cl_device_info field, char** ret_info)
{
	static const cl_uint fields[] = {CL_TRUE, CL_FALSE};
	static const char* cl_names[] = {"CL_TRUE", "CL_FALSE"};
	static const char* names[] = {"Yes", "No"};
	static const unsigned int count = sizeof(fields) / sizeof(fields[0]);

	cl_bool value;
	clGetDeviceInfo(id, field, sizeof(cl_bool), &value, NULL);
	*ret_info = malloc(sizeof(char) * 8);
	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < count; ++i)
	{
		if(value == fields[i]) {
			strcpy(*ret_info, names[i]);
		}
	}
}

void device_info_cl_device_fp_config(cl_device_id id, cl_device_info field, char** ret_info)
{
	static const cl_uint fields[] = {CL_FP_DENORM, CL_FP_INF_NAN, CL_FP_ROUND_TO_NEAREST, CL_FP_ROUND_TO_ZERO, CL_FP_ROUND_TO_INF, CL_FP_FMA};
	static const char* cl_names[] = {"CL_FP_DENORM", "CL_FP_INF_NAN", "CL_FP_ROUND_TO_NEAREST", "CL_FP_ROUND_TO_ZERO", "CL_FP_ROUND_TO_INF", "CL_FP_FMA"};
	static const char* names[] = {"denorms are supported", "INF and NaNs are supported", "round to nearest even rounding mode supported", "round to zero rounding mode supported", "round to +ve and -ve infinity rounding modes supported", "IEEE754-2008 fused multiply-add is supported"};
	static const unsigned int count = sizeof(fields) / sizeof(fields[0]);

	cl_device_fp_config value;
	clGetDeviceInfo(id, field, sizeof(cl_device_fp_config), &value, NULL);

	*ret_info = malloc(sizeof(char) * max_len(names, count) + count * 4 + 1);
	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	bool hit = false;
	for(int i = 0; i < count; ++i) {
		if(value & fields[i]) {
			if(!hit) {
				strcat(*ret_info, "\n\t\t\t");
				hit = true;
			}
			strcat(*ret_info, names[i]);
			if(i < count - 1) {
				strcat(*ret_info, "\n\t\t\t");
			}
		}
	}
	if(!hit) {
		strcat(*ret_info, "None");
	}
}

void device_info_cl_device_exec_capabilities(cl_device_id id, cl_device_info field, char** ret_info)
{
	static const cl_uint fields[] = {CL_EXEC_KERNEL, CL_EXEC_NATIVE_KERNEL};
	static const char* cl_names[] = {"CL_EXEC_KERNEL", "CL_EXEC_NATIVE_KERNEL"};
	static const char* names[] = {"The OpenCL device can execute OpenCL kernels", "The OpenCL device can execute native kernels"};
	static const unsigned int count = sizeof(fields) / sizeof(fields[0]);

	cl_device_exec_capabilities value;
	clGetDeviceInfo(id, field, sizeof(cl_device_exec_capabilities), &value, NULL);
	
	*ret_info = malloc(sizeof(char) * max_len(names, count) + count);
	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < count; ++i) {
		if(value & fields[i]) {
			strcat(*ret_info, names[i]);
			if(i < count-1) {
				strcat(*ret_info, ", ");
			}
		}
	}
}

void device_info_char(cl_device_id id, cl_device_info field, char** ret_info)
{
	size_t size = 0;
	clGetDeviceInfo(id, field, 0, NULL, &size);
	*ret_info = malloc(size);
	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}
	clGetDeviceInfo(id, field, size, *ret_info, NULL);
}

void device_info_ulong(cl_device_id id, cl_device_info field, cl_ulong* ret_info)
{
	clGetDeviceInfo(id, field, sizeof(cl_ulong), ret_info, NULL);
}

void device_info_cl_device_mem_cache_type(cl_device_id id, cl_device_info field, char** ret_info)
{
	static const cl_uint fields[] = {CL_NONE, CL_READ_ONLY_CACHE, CL_READ_WRITE_CACHE};
	static const char* cl_names[] = {"CL_NONE", "CL_READ_ONLY_CACHE", "CL_READ_WRITE_CACHE"};
	static const char* names[] = {"None", "Read-Only cache", "Read-Write cache"};
	static const unsigned int count = sizeof(fields) / sizeof(fields[0]);

	cl_device_mem_cache_type value;
	clGetDeviceInfo(id, field, sizeof(cl_device_mem_cache_type), &value, NULL);
	*ret_info = malloc(sizeof(char) * 24);
	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}
	for(int i = 0; i < count; ++i)
	{
		if(value == fields[i]) {
			strcpy(*ret_info, names[i]);
		}
	}
}

void device_info_size_t(cl_device_id id, cl_device_info field, size_t* ret_info)
{
	clGetDeviceInfo(id, field, sizeof(size_t), ret_info, NULL);
}

void device_info_size_t_array(cl_device_id id, cl_device_info field, unsigned int n, char** ret_info)
{
	size_t* value = malloc(sizeof(size_t) * n);
	*ret_info = malloc(sizeof(char) * n * 3 + 1);
	if(!*ret_info || !value) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}
	clGetDeviceInfo(id, field, sizeof(size_t) * n, value, NULL);
	for(int i = 0; i < n; ++i) {
		char tmp[16];
		sprintf (tmp, "%zu", value[i]);
		strcat(*ret_info, tmp);
		if(i < n - 1) {
			strcat(*ret_info, ", ");
		}
	}
	free(value);
}

void device_info_cl_device_local_mem_type(cl_device_id id, cl_device_info field, char** ret_info)
{
	static const cl_uint fields[] = {CL_LOCAL, CL_GLOBAL};
	static const char* cl_names[] = {"CL_LOCAL", "CL_GLOBAL"};
	static const char* names[] = {"Local memory storage", "Global memory storage"};
	static const unsigned int count = sizeof(fields) / sizeof(fields[0]);

	cl_device_local_mem_type value;
	clGetDeviceInfo(id, field, sizeof(cl_device_local_mem_type), &value, NULL);
	*ret_info = malloc(sizeof(char) * 24);
	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}
	for(int i = 0; i < count; ++i)
	{
		if(value == fields[i]) {
			strcpy(*ret_info, names[i]);
		}
	}
}

void device_info_cl_command_queue_properties(cl_device_id id, cl_device_info field, char** ret_info)
{
	static const cl_uint fields[] = {CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, CL_QUEUE_PROFILING_ENABLE};
	static const char* cl_names[] = {"CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE", "CL_QUEUE_PROFILING_ENABLE"};
	static const char* names[] = {"Commands are executed out-of-order", "The profiling of commands is enabled"};
	static const unsigned int count = sizeof(fields) / sizeof(fields[0]);

	cl_command_queue_properties value;
	clGetDeviceInfo(id, field, sizeof(cl_command_queue_properties), &value, NULL);
	
	*ret_info = malloc(sizeof(char) * max_len(names, count) + count);
	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < count; ++i) {
		if(value & fields[i]) {
			strcat(*ret_info, names[i]);
			strcat(*ret_info, " ");
		}
	}
}

void device_info_cl_device_type(cl_device_id id, cl_device_info field, char** ret_info)
{
	static const cl_uint fields[] = {CL_DEVICE_TYPE_CPU, CL_DEVICE_TYPE_GPU, CL_DEVICE_TYPE_ACCELERATOR, CL_DEVICE_TYPE_DEFAULT};
	static const char* cl_names[] = {"CL_DEVICE_TYPE_CPU", "CL_DEVICE_TYPE_GPU", "CL_DEVICE_TYPE_ACCELERATOR", "CL_DEVICE_TYPE_DEFAULT"};
	static const char* names[] = {"CPU", "GPU", "Accelerator", "Default"};
	static const unsigned int count = sizeof(fields) / sizeof(fields[0]);

	cl_device_type value;
	clGetDeviceInfo(id, field, sizeof(cl_device_type), &value, NULL);

	*ret_info = malloc(sizeof(char) * max_len(names, count) + count);
	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < count; ++i) {
		if(value & fields[i]) {
			strcat(*ret_info, names[i]);
			strcat(*ret_info, " ");
		}
	}
}

void device_info(cl_device_id device)
{
	static const cl_device_info fields[] = {CL_DEVICE_ADDRESS_BITS,CL_DEVICE_AVAILABLE,CL_DEVICE_COMPILER_AVAILABLE,CL_DEVICE_DOUBLE_FP_CONFIG,CL_DEVICE_ENDIAN_LITTLE,CL_DEVICE_ERROR_CORRECTION_SUPPORT,CL_DEVICE_EXECUTION_CAPABILITIES,CL_DEVICE_EXTENSIONS,CL_DEVICE_GLOBAL_MEM_CACHE_SIZE,CL_DEVICE_GLOBAL_MEM_CACHE_TYPE,CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE,CL_DEVICE_GLOBAL_MEM_SIZE,CL_DEVICE_HALF_FP_CONFIG,CL_DEVICE_IMAGE_SUPPORT,CL_DEVICE_IMAGE2D_MAX_HEIGHT,CL_DEVICE_IMAGE2D_MAX_WIDTH,CL_DEVICE_IMAGE3D_MAX_DEPTH,CL_DEVICE_IMAGE3D_MAX_HEIGHT,CL_DEVICE_IMAGE3D_MAX_WIDTH,CL_DEVICE_LOCAL_MEM_SIZE,CL_DEVICE_LOCAL_MEM_TYPE,CL_DEVICE_MAX_CLOCK_FREQUENCY,CL_DEVICE_MAX_COMPUTE_UNITS,CL_DEVICE_MAX_CONSTANT_ARGS,CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE,CL_DEVICE_MAX_MEM_ALLOC_SIZE,CL_DEVICE_MAX_PARAMETER_SIZE,CL_DEVICE_MAX_READ_IMAGE_ARGS,CL_DEVICE_MAX_SAMPLERS,CL_DEVICE_MAX_WORK_GROUP_SIZE,CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS,CL_DEVICE_MAX_WORK_ITEM_SIZES,CL_DEVICE_MAX_WRITE_IMAGE_ARGS,CL_DEVICE_MEM_BASE_ADDR_ALIGN,CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE,CL_DEVICE_NAME,CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR,CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT,CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT,CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG,CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT,CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE,CL_DEVICE_PROFILE,CL_DEVICE_PROFILING_TIMER_RESOLUTION,CL_DEVICE_QUEUE_PROPERTIES,CL_DEVICE_SINGLE_FP_CONFIG,CL_DEVICE_TYPE,CL_DEVICE_VENDOR,CL_DEVICE_VENDOR_ID,CL_DEVICE_VERSION,CL_DRIVER_VERSION};

	static const char *cl_names[] = {"CL_DEVICE_ADDRESS_BITS","CL_DEVICE_AVAILABLE","CL_DEVICE_COMPILER_AVAILABLE","CL_DEVICE_DOUBLE_FP_CONFIG","CL_DEVICE_ENDIAN_LITTLE","CL_DEVICE_ERROR_CORRECTION_SUPPORT","CL_DEVICE_EXECUTION_CAPABILITIES","CL_DEVICE_EXTENSIONS","CL_DEVICE_GLOBAL_MEM_CACHE_SIZE","CL_DEVICE_GLOBAL_MEM_CACHE_TYPE","CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE","CL_DEVICE_GLOBAL_MEM_SIZE","CL_DEVICE_HALF_FP_CONFIG","CL_DEVICE_IMAGE_SUPPORT","CL_DEVICE_IMAGE2D_MAX_HEIGHT","CL_DEVICE_IMAGE2D_MAX_WIDTH","CL_DEVICE_IMAGE3D_MAX_DEPTH","CL_DEVICE_IMAGE3D_MAX_HEIGHT","CL_DEVICE_IMAGE3D_MAX_WIDTH","CL_DEVICE_LOCAL_MEM_SIZE","CL_DEVICE_LOCAL_MEM_TYPE","CL_DEVICE_MAX_CLOCK_FREQUENCY","CL_DEVICE_MAX_COMPUTE_UNITS","CL_DEVICE_MAX_CONSTANT_ARGS","CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE","CL_DEVICE_MAX_MEM_ALLOC_SIZE","CL_DEVICE_MAX_PARAMETER_SIZE","CL_DEVICE_MAX_READ_IMAGE_ARGS","CL_DEVICE_MAX_SAMPLERS","CL_DEVICE_MAX_WORK_GROUP_SIZE","CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS","CL_DEVICE_MAX_WORK_ITEM_SIZES","CL_DEVICE_MAX_WRITE_IMAGE_ARGS","CL_DEVICE_MEM_BASE_ADDR_ALIGN","CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE","CL_DEVICE_NAME","CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR","CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT","CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT","CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG","CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT","CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE","CL_DEVICE_PROFILE","CL_DEVICE_PROFILING_TIMER_RESOLUTION","CL_DEVICE_QUEUE_PROPERTIES","CL_DEVICE_SINGLE_FP_CONFIG","CL_DEVICE_TYPE","CL_DEVICE_VENDOR","CL_DEVICE_VENDOR_ID","CL_DEVICE_VERSION","CL_DRIVER_VERSION"};

	static const char *names[] = {"Address space size","Device is available","Compiler is available","Double precision floating-point capability","Little endian device","Error correction support","Execution capabilities","Extensions","Size of global memory cache (in bytes)","Type of global memory cache","Size of global memory cache line (in bytes)","Size of global device memory (in bytes)","Half precision floating-point capability","Images are supported","Max height of 2D image (in pixels)","Max width of 2D image (in pixels)","Max depth of 3D image (in pixels)","Max height of 3D image (in pixels)","Max width of 3D image (in pixels)","Size of local memory arena (in bytes)","Type of local memory","Maximum configured clock frequency (in MHz)","The number of parallel compute cores","Max number of __constant arguments in a kernel","Max size of a constant buffer allocation (in bytes)","Max size of memory object allocation (in bytes)","Max size of kernel arguments (in bytes)","Max number of simultaneously read image objects","Maximum number of samplers","Maximum number of work-items in a work-group","Maximum dimensions that specify work-item IDs","Maximum number of work-items in each dimension","Max number of simultaneously written image objects","Alignment of the base address of any allocated memory object (in bits)","Minimum alignment for any data type (in bytes)","Device name","Preferred native vector width size for char type","Preferred native vector width size for short type","Preferred native vector width size for int type","Preferred native vector width size for long type","Preferred native vector width size for float type","Preferred native vector width size for double type","OpenCL profile","Resolution of device timer (in nanoseconds)","Supported command-queue properties","Single precision floating-point capability","OpenCL device type","Vendor name","Device vendor identifier","OpenCL version","OpenCL software driver version"};

	static const unsigned int types[] = {t_uint,t_bool,t_bool,t_device_fp_config,t_bool,t_bool,t_device_exec_capabilities,t_char,t_ulong,t_device_mem_cache_type,t_uint,t_ulong,t_device_fp_config,t_bool,t_size_t, t_size_t, t_size_t, t_size_t, t_size_t, t_ulong, t_device_local_mem_type, t_uint,t_uint, t_uint, t_ulong, t_ulong, t_size_t, t_uint, t_uint, t_size_t, t_uint, t_size_t_array, t_uint, t_uint, t_uint, t_char, t_uint, t_uint, t_uint, t_uint, t_uint, t_uint, t_char, t_size_t, t_command_queue_properties, t_device_fp_config, t_device_type, t_char, t_uint, t_char, t_char};

	static const unsigned int order[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};

	for(cl_uint i = 0; i < 51; ++i) {
		switch(types[order[i]])
		{
			case t_uint: {
				cl_uint info;
				device_info_uint(device, fields[order[i]], &info);
				printf( "\t\t %s: %u\n", names[order[i]], info);
				break;
			}
			case t_bool: {
				char *info;
				device_info_bool(device, fields[order[i]], &info);
				printf( "\t\t %s: %s\n", names[order[i]], info);
				free(info);
				break;
			}
			case t_device_fp_config:{
				char *info;
				device_info_cl_device_fp_config(device, fields[order[i]], &info);
				printf( "\t\t %s: %s\n", names[order[i]], info);
				free(info);
				break;
			}
			case t_device_exec_capabilities:{
				char *info;
				device_info_cl_device_exec_capabilities(device, fields[order[i]], &info);
				printf( "\t\t %s: %s\n", names[order[i]], info);
				free(info);
				break;
			}
			case t_char: {
				char *info;
				device_info_char(device, fields[order[i]], &info);
				printf( "\t\t %s: %s\n", names[order[i]], info);
				free(info);
				break;
			}
			case t_ulong:{
				cl_ulong info;
				device_info_ulong(device, fields[order[i]], &info);
				printf( "\t\t %s: %llu\n", names[order[i]], info);
				break;
			}
			case t_device_mem_cache_type:{
				char *info;
				device_info_cl_device_mem_cache_type(device, fields[order[i]], &info);
				printf( "\t\t %s: %s\n", names[order[i]], info);
				free(info);
				break;
			}
			case t_size_t:{
				size_t info;
				device_info_size_t(device, fields[order[i]], &info);
				printf( "\t\t %s: %zu\n", names[order[i]], info);
				break;
			}
			case t_size_t_array:{
				char* info;
				unsigned int n;
				device_info_uint(device, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, &n);
				device_info_size_t_array(device, fields[order[i]], n, &info);
				printf( "\t\t %s: %s\n", names[order[i]], info);
				free(info);
				break;
			}
			case t_device_local_mem_type:{
				char *info;
				device_info_cl_device_local_mem_type(device, fields[order[i]], &info);
				printf( "\t\t %s: %s\n", names[order[i]], info);
				free(info);
				break;
			}
			case t_command_queue_properties:{
				char *info;
				device_info_cl_command_queue_properties(device, fields[order[i]], &info);
				printf( "\t\t %s: %s\n", names[order[i]], info);
				free(info);
				break;
			}
			case t_device_type:{
				char *info;
				device_info_cl_device_type(device, fields[order[i]], &info);
				printf( "\t\t %s: %s\n", names[order[i]], info);
				free(info);
				break;
			}
		}
	}
}

void show_usage(char *name)
{
	printf("OVERVIEW:\n\tGet info about OpenCL platforms/devices\n");
	printf("USAGE:\n\t%s [option]\n", name);
	printf("OPTIONS:\n"); 
	printf("\t-h, --help\t\tShow this help message\n");
	printf("\t-np,--num-platforms\tShow number of available platforms\n");
	printf("\t-nd,--num-devices\tShow number of available devices\n");
	printf("\t-ps,--platforms\t\tShow info about platforms\n");
	printf("\t-ds,--devices\t\tShow info about devices\n");
}

int main(int argc, char *argv[])
{
	if(argc == 1) {
		show_usage(argv[0]);
		return EXIT_SUCCESS;
	}

	for(int i = 1; i < argc; ++i) {
		if(!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
			show_usage(argv[0]);
			return EXIT_SUCCESS;
		} else if( !strcmp(argv[i], "-np") || !strcmp(argv[i], "--num-platforms")) {
			printf("Platform(s): %u\n", available_platforms());
			return EXIT_SUCCESS;
		} else if( !strcmp(argv[i], "-nd") || !strcmp(argv[i], "--num-devices")) {
			cl_platform_id *p_ids;
			cl_uint num_platforms = platforms(&p_ids);
			for(int i = 0; i < num_platforms; ++i) {
				cl_uint num_devices = available_devices(p_ids[i]);
				printf("Platform # %d\n", i+1);
				printf("------------\n");
				printf("\tDevice(s): %u\n", num_devices);
			}
			free(p_ids);
			return EXIT_SUCCESS;
		} else if( !strcmp(argv[i], "-ps") || !strcmp(argv[i], "--platforms")) {
			cl_platform_id *p_ids;
			cl_uint num_platforms = platforms(&p_ids);
			for(int i = 0; i < num_platforms; ++i) {
				printf("Platform # %d\n", i+1);
				printf("============\n");
				platform_info(p_ids[i]);
			}
			free(p_ids);
			return EXIT_SUCCESS;
		} else if( !strcmp(argv[i], "-ds") || !strcmp(argv[i], "--devices")) {
			cl_platform_id *p_ids;
			cl_uint num_platforms = platforms(&p_ids);
			for(int i = 0; i < num_platforms; ++i) {
				printf("Platform # %d\n", i+1);
				printf("============\n");
				cl_device_id *d_ids;
				cl_uint num_devices = devices(p_ids[i], &d_ids);
				for(int j = 0; j < num_devices; ++j) {
					printf("Device # %d\n", j+1);
					printf("----------\n");
					device_info(d_ids[j]);
				}
				free(d_ids);
			}
			free(p_ids);
			return EXIT_SUCCESS;
		}
	}
	return EXIT_SUCCESS;
}

