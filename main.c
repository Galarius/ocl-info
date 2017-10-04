#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

size_t max_len(const char *names[], unsigned int count)
{
	size_t max = 0;
	size_t tmp = 0;

	for(int i = 0; i < count; ++i) {
		tmp = strlen(names[i]);

		if(tmp > max) {
			max = tmp;
		}
	}

	return max;
}

size_t sum_len(const char *names[], unsigned int count)
{
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

void platform_field(cl_platform_id id, cl_platform_info field, char **ret_info)
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

void platform_info(cl_platform_id platform, int use_cl_names)
{
	char *info;

	for(cl_uint i = 0; i < count_platform_info; ++i) {
		platform_field(platform, fields_platform_info[order_platform_info[i]], &info);
		if(use_cl_names) {
			printf("\t %s: %s\n", cl_names_platform_info[order_platform_info[i]], info);
		} else {
			printf("\t %s: %s\n", names_platform_info[order_platform_info[i]], info);
		}
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

void info_bitwise_field(cl_device_id id, cl_device_info field,
                        const cl_uint *fields, const char **names,
                        const size_t count, const size_t value_size,
                        char **ret_info)
{
	static const char *sep = "; ";
	*ret_info = (char *)malloc(sizeof(char) * sum_len(names, count) + count * strlen(sep) + 1);

	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	unsigned long long value;
	clGetDeviceInfo(id, field, value_size, &value, NULL);
	int hits = 0;

	for(int i = 0; i < count; ++i) {
		if(value & fields[i]) {
			strcat(*ret_info, names[i]);
			strcat(*ret_info, sep);
			++hits;
		}
	}

	size_t len = strlen(*ret_info);

	if(len > strlen(sep)) {
		(*ret_info)[len - strlen(sep)] = '\0';
	}
}

void info_enum_field(cl_device_id id, cl_device_info field,
                     const cl_uint *fields, const char **names,
                     const size_t count, char **ret_info)
{
	*ret_info = malloc(sizeof(char) * max_len(names, count) + 1);

	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	cl_uint value;
	clGetDeviceInfo(id, field, sizeof(cl_uint), &value, NULL);

	for(int i = 0; i < count; ++i) {
		if(value == fields[i]) {
			strcpy(*ret_info, names[i]);
			break;
		}
	}
}

void device_info_char(cl_device_id id, cl_device_info field, char **ret_info)
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

void device_info_size_t_array(cl_device_id id, cl_device_info field, unsigned int n, char **ret_info)
{
	size_t *value = malloc(sizeof(size_t) * n);
	*ret_info = malloc(sizeof(char) * n * 3 + 1);

	if(!*ret_info || !value) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	clGetDeviceInfo(id, field, sizeof(size_t) * n, value, NULL);

	for(int i = 0; i < n; ++i) {
		char tmp[16];
		sprintf(tmp, "%zu", value[i]);
		strcat(*ret_info, tmp);

		if(i < n - 1) {
			strcat(*ret_info, ", ");
		}
	}

	free(value);
}

void device_info(cl_device_id device, int use_cl_names)
{
	for(unsigned int i = 0; i < count_device_info; ++i) {
		switch(types_device_info[order_device_info[i]]) {
			case t_uint: {
					cl_uint info;
					clGetDeviceInfo(device, fields_device_info[order_device_info[i]], sizeof(cl_uint), &info, NULL);
					if(use_cl_names) {
						printf("\t\t %s: %u\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						printf("\t\t %s: %u\n", names_device_info[order_device_info[i]], info);
					}
					break;
				}

			case t_bool: {
					char *info;
					if(use_cl_names) {
						info_enum_field(device, fields_device_info[order_device_info[i]], fields_cl_bool, cl_names_cl_bool, count_cl_bool, &info);
						printf("\t\t %s: %s\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						info_enum_field(device, fields_device_info[order_device_info[i]], fields_cl_bool, names_cl_bool, count_cl_bool, &info);
						printf("\t\t %s: %s\n", names_device_info[order_device_info[i]], info);
					}
					free(info);
					break;
				}

			case t_device_fp_config: {
					char *info;
					if(use_cl_names) {
						info_bitwise_field(device, fields_device_info[order_device_info[i]], fields_cl_device_fp_config, cl_names_cl_device_fp_config, count_cl_device_fp_config, sizeof(cl_device_fp_config), &info);
						printf("\t\t %s: %s\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						info_bitwise_field(device, fields_device_info[order_device_info[i]], fields_cl_device_fp_config, names_cl_device_fp_config, count_cl_device_fp_config, sizeof(cl_device_fp_config), &info);
						printf("\t\t %s: %s\n", names_device_info[order_device_info[i]], info);
					}
					free(info);
					break;
				}

			case t_device_exec_capabilities: {
					char *info;
					if(use_cl_names) {
						info_bitwise_field(device, fields_device_info[order_device_info[i]], fields_cl_device_exec_capabilities, cl_names_cl_device_exec_capabilities, count_cl_device_exec_capabilities, sizeof(cl_device_exec_capabilities), &info);
						printf("\t\t %s: %s\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						info_bitwise_field(device, fields_device_info[order_device_info[i]], fields_cl_device_exec_capabilities, names_cl_device_exec_capabilities, count_cl_device_exec_capabilities, sizeof(cl_device_exec_capabilities), &info);
						printf("\t\t %s: %s\n", names_device_info[order_device_info[i]], info);
					}
					free(info);
					break;
				}

			case t_char: {
					char *info;
					device_info_char(device, fields_device_info[order_device_info[i]], &info);
					if(use_cl_names) {
						printf("\t\t %s: %s\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						printf("\t\t %s: %s\n", names_device_info[order_device_info[i]], info);
					}
					free(info);
					break;
				}

			case t_ulong: {
					cl_ulong info;
					clGetDeviceInfo(device, fields_device_info[order_device_info[i]], sizeof(cl_ulong), &info, NULL);
					if(use_cl_names) {
						printf("\t\t %s: %llu\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						printf("\t\t %s: %llu\n", names_device_info[order_device_info[i]], info);	
					}
					break;
				}

			case t_device_mem_cache_type: {
					char *info;
					if(use_cl_names) {
						info_enum_field(device, fields_device_info[order_device_info[i]], fields_cl_device_mem_cache_type, cl_names_cl_device_mem_cache_type, count_cl_device_mem_cache_type, &info);
						printf("\t\t %s: %s\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						info_enum_field(device, fields_device_info[order_device_info[i]], fields_cl_device_mem_cache_type, names_cl_device_mem_cache_type, count_cl_device_mem_cache_type, &info);
						printf("\t\t %s: %s\n", names_device_info[order_device_info[i]], info);	
					}
					free(info);
					break;
				}

			case t_size_t: {
					size_t info;
					clGetDeviceInfo(device, fields_device_info[order_device_info[i]], sizeof(size_t), &info, NULL);
					if(use_cl_names) {
						printf("\t\t %s: %zu\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						printf("\t\t %s: %zu\n", names_device_info[order_device_info[i]], info);	
					}
					break;
				}

			case t_size_t_array: {
					char *info;
					cl_uint n;
					clGetDeviceInfo(device, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(cl_uint), &n, NULL);
					device_info_size_t_array(device, fields_device_info[order_device_info[i]], n, &info);
					if(use_cl_names) {
						printf("\t\t %s: %s\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						printf("\t\t %s: %s\n", names_device_info[order_device_info[i]], info);	
					}
					free(info);
					break;
				}

			case t_device_local_mem_type: {
					char *info;
					if(use_cl_names) {
						info_bitwise_field(device, fields_device_info[order_device_info[i]], fields_cl_device_local_mem_type, cl_names_cl_device_local_mem_type, count_cl_device_local_mem_type, sizeof(cl_device_local_mem_type), &info);
						printf("\t\t %s: %s\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						info_bitwise_field(device, fields_device_info[order_device_info[i]], fields_cl_device_local_mem_type, names_cl_device_local_mem_type, count_cl_device_local_mem_type, sizeof(cl_device_local_mem_type), &info);
						printf("\t\t %s: %s\n", names_device_info[order_device_info[i]], info);	
					}
					free(info);
					break;
				}

			case t_command_queue_properties: {
					char *info;
					if(use_cl_names) {
						info_bitwise_field(device, fields_device_info[order_device_info[i]], fields_cl_command_queue_properties, cl_names_cl_command_queue_properties, count_cl_command_queue_properties, sizeof(cl_command_queue_properties), &info);
						printf("\t\t %s: %s\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						info_bitwise_field(device, fields_device_info[order_device_info[i]], fields_cl_command_queue_properties, names_cl_command_queue_properties, count_cl_command_queue_properties, sizeof(cl_command_queue_properties), &info);
						printf("\t\t %s: %s\n", names_device_info[order_device_info[i]], info);	
					}
					free(info);
					break;
				}

			case t_device_type: {
					char *info;
					if(use_cl_names) {
						info_bitwise_field(device, fields_device_info[order_device_info[i]], fields_cl_device_type, cl_names_cl_device_type, count_cl_device_type, sizeof(cl_device_type), &info);
						printf("\t\t %s: %s\n", cl_names_device_info[order_device_info[i]], info);
					} else {
						info_bitwise_field(device, fields_device_info[order_device_info[i]], fields_cl_device_type, names_cl_device_type, count_cl_device_type, sizeof(cl_device_type), &info);
						printf("\t\t %s: %s\n", names_device_info[order_device_info[i]], info);	
					}
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
	printf("\t-pds,--platforms-devices\t\tShow info about platforms and devices\n");
	printf("\t-cl,--cl-names\t\tShow platform/device fields with cl names.\n");
}

int main(int argc, char *argv[])
{
	if(argc == 1) {
		show_usage(argv[0]);
		return EXIT_SUCCESS;
	}

	enum {
		opt_np = 1 << 0,
		opt_nd = 1 << 1,
		opt_ps = 1 << 2,
		opt_ds = 1 << 3,
		opt_pds= 1 << 4,
		opt_cl = 1 << 5,
	} opt;
	enum {
		mode_none = 0,
		mode_platform_count,
		mode_device_count,
		mode_platform_info,
		mode_device_info,
		mode_platform_info_device_count,
		mode_full_info
	} mode;
	mode = mode_none;

	for(int i = 1; i < argc; ++i) {
		if(!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
			show_usage(argv[0]);
			return EXIT_SUCCESS;
		}

		if(!strcmp(argv[i], "-np") || !strcmp(argv[i], "--num-platforms")) {
			opt |= opt_np;
		}

		if(!strcmp(argv[i], "-nd") || !strcmp(argv[i], "--num-devices")) {
			opt |= opt_nd;
		}

		if(!strcmp(argv[i], "-ps") || !strcmp(argv[i], "--platforms")) {
			opt |= opt_ps;
		}

		if(!strcmp(argv[i], "-ds") || !strcmp(argv[i], "--devices")) {
			opt |= opt_ds;
		}

		if(!strcmp(argv[i], "-pds") || !strcmp(argv[i], "--platforms-devices")) {
			opt |= opt_pds;
		}

		if(!strcmp(argv[i], "-cl") || !strcmp(argv[i], "--cl-names")) {
			opt |= opt_cl;
		}
	}

	if(opt & opt_pds || (opt & opt_ps && opt & opt_ds)) {
		mode = mode_full_info;
	} else if(opt & opt_ps && opt & opt_nd) {
		mode = mode_platform_info_device_count;
	} else if(opt & opt_ds) {
		mode = mode_device_info;
	} else if(opt & opt_ps) {
		mode = mode_platform_info;
	} else if(opt & opt_nd) {
		mode = mode_device_count;
	} else if(opt & opt_np) {
		mode = mode_platform_count;
	}

	if(mode == mode_none) {
		show_usage(argv[0]);
		return EXIT_SUCCESS;
	}

	printf("Platform(s): %u\n", available_platforms());

	if(mode != mode_platform_count) {
		cl_platform_id *p_ids;
		cl_uint num_platforms = platforms(&p_ids);

		for(int i = 0; i < num_platforms; ++i) {
			printf("Platform # %d\n", i+1);
			printf("============\n");

			if(mode == mode_platform_info ||
			        mode == mode_platform_info_device_count) {
				platform_info(p_ids[i], opt & opt_cl);
			}

			if(mode == mode_device_count ||
			        mode == mode_platform_info_device_count) {
				cl_uint num_devices = available_devices(p_ids[i]);
				printf("\tDevice(s): %u\n", num_devices);
			}

			if(mode == mode_full_info) {
				cl_device_id *d_ids;
				cl_uint num_devices = devices(p_ids[i], &d_ids);

				for(int j = 0; j < num_devices; ++j) {
					printf("Device # %d\n", j+1);
					printf("----------\n");
					device_info(d_ids[j], opt & opt_cl);
				}
				free(d_ids);
			}
		}
		free(p_ids);
	}

	return EXIT_SUCCESS;
}

