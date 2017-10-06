#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

size_t max_len(const char *names[], size_t count)
{
	size_t max = 0;
	size_t tmp = 0;
	size_t i = 0;

	for(; i < count; ++i) {
		tmp = strlen(names[i]);

		if(tmp > max)
			max = tmp;
	}

	return max;
}

size_t sum_len(const char *names[], size_t count)
{
	size_t sum = 0;
	size_t i = 0;

	for(; i < count; ++i) {
		sum += strlen(names[i]);
	}

	return sum;
}

void display_separated(char* str, const char* fmt, char sep[])
{
	char *pch = strtok(str, sep);
	while (pch != NULL) {
		  printf(fmt, "");
		  printf("\t%s\n", pch);
		  pch = strtok (NULL, sep);
	}
	printf(fmt, "");
}

/*----------------------------------------------------------------------------*/
/* Platforms																  */
/*----------------------------------------------------------------------------*/

cl_uint available_platforms()
{
	cl_uint num_platforms;
	clGetPlatformIDs(0, NULL, &num_platforms);
	return num_platforms;
}

cl_uint platforms(cl_platform_id **platforms)
{
	cl_uint num_platforms = available_platforms();

	if(num_platforms) {
		*platforms = malloc(sizeof(cl_platform_id) * num_platforms);
		clGetPlatformIDs(num_platforms, *platforms, NULL);
	}

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

void platform_info(cl_platform_id platform, const char **names)
{
	char *info;
	cl_uint i = 0;
	for(; i < count_platform_info; ++i) {
		platform_field(platform, fields_platform_info[order_platform_info[i]], &info);
		if(fields_platform_info[order_platform_info[i]] == CL_PLATFORM_EXTENSIONS) {
			printf("%-22s\t:\n", names[order_platform_info[4]]);
			char *pch = strtok(info, " ");
			while (pch != NULL) {
				  printf("%-22s\t:\t%s\n","", pch);
				  pch = strtok (NULL, " ");
			}
			printf("%-22s\t:\t\n", "");
		} else {
			printf("%-22s\t:\t%s\n", names[order_platform_info[i]], info);
		}
		free(info);
	}
}

/*----------------------------------------------------------------------------*/
/* Devices																	  */
/*----------------------------------------------------------------------------*/

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

	if(num_devices) {
		*devices = malloc(sizeof(cl_device_id) * num_devices);
		clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, num_devices, *devices, NULL);
	}

	return num_devices;
}

void info_bitwise_field(cl_device_id id, cl_device_info field,
                        const cl_uint *fields, const char **names,
                        const size_t count, const size_t value_size,
                        char **ret_info)
{
	static const char *sep = ";";
	unsigned long long value;
	size_t i = 0;
	size_t len = 0;
	*ret_info = (char *)malloc(sizeof(char) * sum_len(names, count) + count * strlen(sep) + 1);

	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	clGetDeviceInfo(id, field, value_size, &value, NULL);

	for(; i < count; ++i) {
		if(value & fields[i]) {
			strcat(*ret_info, names[i]);
			strcat(*ret_info, sep);
		}
	}

	len = strlen(*ret_info);

	if(len > strlen(sep)) {
		(*ret_info)[len - strlen(sep)] = '\0';
	}
}

void info_enum_field(cl_device_id id, cl_device_info field,
                     const cl_uint *fields, const char **names,
                     const size_t count, char **ret_info)
{
	cl_uint value;
	size_t i = 0;
	*ret_info = malloc(sizeof(char) * max_len(names, count) + 1);

	if(!*ret_info) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	clGetDeviceInfo(id, field, sizeof(cl_uint), &value, NULL);

	for(; i < count; ++i) {
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

void device_info_size_t_array(cl_device_id id, cl_device_info field, cl_uint n, char **ret_info)
{
	size_t *value = malloc(sizeof(size_t) * n);
	*ret_info = malloc(sizeof(char) * n * 3 + 1);
	cl_uint i = 0;
	char tmp[16];

	if(!*ret_info || !value) {
		fprintf(stderr, "malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	clGetDeviceInfo(id, field, sizeof(size_t) * n, value, NULL);

	for(; i < n; ++i) {
		memset(tmp, 0, sizeof(tmp)/sizeof(tmp[0]));
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
	cl_uint i = 0;
	cl_uint info_uint;
	cl_ulong info_ulong;
	size_t info_size_t;
	char *info_char = NULL;
	char* formats[] = {"%-39s\t:", "%-70s\t:"};
	char* fmt = NULL;
	const char* name = NULL;
	cl_device_info field;

	for(; i < count_device_info; ++i) {

		field = fields_device_info[order_device_info[i]];
		if(use_cl_names) {
			name = cl_names_device_info[order_device_info[i]];
			fmt = formats[0];
		} else {
			name = names_device_info[order_device_info[i]];
			fmt = formats[1];
		}

		switch(types_device_info[order_device_info[i]]) {
			case InfoTypeUInt:
				clGetDeviceInfo(device, field, sizeof(cl_uint), &info_uint, NULL);
				printf(fmt, name);
				printf("\t%u\n", info_uint);
				break;

			case InfoTypeBool:
				if(use_cl_names)
					info_enum_field(device, field, fields_cl_bool, cl_names_cl_bool, count_cl_bool, &info_char);
				else 
					info_enum_field(device, field, fields_cl_bool, names_cl_bool, count_cl_bool, &info_char);
				printf(fmt, name);
				printf("\t%s\n", info_char);
				free(info_char);
				break;

			case InfoTypeFP:

				if(use_cl_names)
					info_bitwise_field(device, field, fields_cl_device_fp_config, cl_names_cl_device_fp_config, count_cl_device_fp_config, sizeof(cl_device_fp_config), &info_char);
				else
					info_bitwise_field(device, field, fields_cl_device_fp_config, names_cl_device_fp_config, count_cl_device_fp_config, sizeof(cl_device_fp_config), &info_char);
				printf(fmt, name); printf("\n");
				display_separated(info_char, fmt, ";");
				printf(fmt, "");   printf("\n");
				free(info_char);
				break;

			case InfoTypeExec:
				if(use_cl_names)
					info_bitwise_field(device, field, fields_cl_device_exec_capabilities, cl_names_cl_device_exec_capabilities, count_cl_device_exec_capabilities, sizeof(cl_device_exec_capabilities), &info_char);
				else
					info_bitwise_field(device, field, fields_cl_device_exec_capabilities, names_cl_device_exec_capabilities, count_cl_device_exec_capabilities, sizeof(cl_device_exec_capabilities), &info_char);
				printf(fmt, name);
				printf("\t%s\n", info_char);
				free(info_char);
				break;

			case InfoTypeChar:
				device_info_char(device, field, &info_char);
				if(field == CL_DEVICE_EXTENSIONS) {
					printf(fmt, name); printf("\n");
					display_separated(info_char, fmt, " ");
					printf(fmt, "");   printf("\n");
				} else {
					printf(fmt, name);
					printf("\t%s\n", info_char);
				}
				free(info_char);
				break;

			case InfoTypeULong:
				clGetDeviceInfo(device, field, sizeof(cl_ulong), &info_ulong, NULL);
				printf(fmt, name);
				printf("\t%llu\n", info_ulong);
				break;

			case InfoTypeMem:
				if(use_cl_names)
					info_enum_field(device, field, fields_cl_device_mem_cache_type, cl_names_cl_device_mem_cache_type, count_cl_device_mem_cache_type, &info_char);
				else
					info_enum_field(device, field, fields_cl_device_mem_cache_type, names_cl_device_mem_cache_type, count_cl_device_mem_cache_type, &info_char);
				printf(fmt, name);
				printf("\t%s\n", info_char);
				free(info_char);
				break;

			case InfoTypeSizet:
				clGetDeviceInfo(device, field, sizeof(size_t), &info_size_t, NULL);
				printf(fmt, name);
				printf("\t%zu\n", info_size_t);
				break;
			case InfoTypeSizets:
				clGetDeviceInfo(device, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(cl_uint), &info_uint, NULL);
				device_info_size_t_array(device, field, info_uint, &info_char);
				printf(fmt, name);
				printf("\t%s\n", info_char);
				free(info_char);
				break;

			case InfoTypeLocMem:
				if(use_cl_names)
					info_bitwise_field(device, field, fields_cl_device_local_mem_type, cl_names_cl_device_local_mem_type, count_cl_device_local_mem_type, sizeof(cl_device_local_mem_type), &info_char);
				else
					info_bitwise_field(device, field, fields_cl_device_local_mem_type, names_cl_device_local_mem_type, count_cl_device_local_mem_type, sizeof(cl_device_local_mem_type), &info_char);
				printf(fmt, name);
				printf("\t%s\n", info_char);
				free(info_char);
				break;

			case InfoTypeLocQueue:
				if(use_cl_names)
					info_bitwise_field(device, field, fields_cl_command_queue_properties, cl_names_cl_command_queue_properties, count_cl_command_queue_properties, sizeof(cl_command_queue_properties), &info_char);
				else
					info_bitwise_field(device, field, fields_cl_command_queue_properties, names_cl_command_queue_properties, count_cl_command_queue_properties, sizeof(cl_command_queue_properties), &info_char);
				printf(fmt, name);
				printf("\t%s\n", info_char);
				free(info_char);
				break;

			case InfoTypeDevice:
				if(use_cl_names)
					info_bitwise_field(device, field, fields_cl_device_type, cl_names_cl_device_type, count_cl_device_type, sizeof(cl_device_type), &info_char);
				else
					info_bitwise_field(device, field, fields_cl_device_type, names_cl_device_type, count_cl_device_type, sizeof(cl_device_type), &info_char);
				printf(fmt, name);
				printf("\t%s\n", info_char);
				free(info_char);
				break;
		}
	}
}

void show_usage(char *name)
{
	printf("OVERVIEW:\n\tGet info about OpenCL platforms/devices\n");
	printf("USAGE:\n\t%s [option]\n", name);
	printf("OPTIONS:\n");
	printf("\t-h, --help\t\t\tShow this help message\n");
	printf("\t-np,--num-platforms\t\tShow number of available platforms\n");
	printf("\t-nd,--num-devices\t\tShow number of available devices\n");
	printf("\t-ps,--platforms\t\t\tShow info about platforms\n");
	printf("\t-ds,--devices\t\t\tShow info about devices\n");
	printf("\t-pds,--platforms-devices\tShow info about platforms and devices\n");
	printf("\t-cl,--cl-names\t\t\tShow platform/device fields with cl names\n");
}

int main(int argc, char *argv[])
{
	cl_uint i = 0;
	cl_uint j = 0;
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

	if(argc == 1) {
		show_usage(argv[0]);
		return EXIT_SUCCESS;
	}

	for(i = 1; i < argc; ++i) {
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

	printf("\nPlatform(s): %u\n\n", available_platforms());

	if(mode != mode_platform_count) {
		cl_platform_id *p_ids;
		cl_uint num_platforms = platforms(&p_ids);

		if(!num_platforms) {
			fprintf(stderr, "No OpenCL platforms found!\n");
			exit(EXIT_SUCCESS);
		}

		for(i = 0; i < num_platforms; ++i) {
			printf("================\n");
			printf("  Platform # %d\n", i+1);
			printf("================\n\n");

			if(mode == mode_platform_info ||
			        mode == mode_platform_info_device_count ||
			        mode == mode_full_info) {
				if(opt & opt_cl) {
					platform_info(p_ids[i], cl_names_platform_info);
				} else {
					platform_info(p_ids[i], names_platform_info);
				}
			}

			if(mode == mode_device_count ||
			        mode == mode_platform_info_device_count ||
			        mode == mode_full_info) {
				cl_uint num_devices = available_devices(p_ids[i]);
				printf("%-22s\t:\t%u\n", "Device(s)", num_devices);
			}

			if(mode == mode_full_info) {
				cl_device_id *d_ids;
				cl_uint num_devices = devices(p_ids[i], &d_ids);

				if(!num_devices) {
					fprintf(stderr, "No OpenCL devices found!\n");
					exit(EXIT_SUCCESS);
				}

				for(j = 0; j < num_devices; ++j) {
					printf("\n----------------\n");
					printf("  Device # %d\n", j+1);
					printf("----------------\n\n");
					device_info(d_ids[j], opt & opt_cl);
				}

				free(d_ids);
			}
		}

		free(p_ids);
	}

	return EXIT_SUCCESS;
}

