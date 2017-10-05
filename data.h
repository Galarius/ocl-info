#ifndef __DATA_H__
#define __DATA_H__

#include "common.h"

enum {
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

/* platform info */
extern const cl_platform_info fields_platform_info[];
extern const char *cl_names_platform_info[];
extern const char *names_platform_info[];
extern const cl_uint order_platform_info[];
extern const cl_uint count_platform_info;

/* device info */
extern const cl_device_info fields_device_info[];
extern const char *cl_names_device_info[];
extern const char *names_device_info[];
extern const cl_uint types_device_info[];
extern const cl_uint order_device_info[];
extern const cl_uint count_device_info;

/* cl_device_fp_config */
extern const cl_uint fields_cl_device_fp_config[];
extern const char *cl_names_cl_device_fp_config[];
extern const char *names_cl_device_fp_config[];
extern const cl_uint count_cl_device_fp_config;

/* cl_bool */
extern const cl_uint fields_cl_bool[];
extern const char *cl_names_cl_bool[];
extern const char *names_cl_bool[];
extern const cl_uint count_cl_bool;

/* cl_device_exec_capabilities */
extern const cl_uint fields_cl_device_exec_capabilities[];
extern const char *cl_names_cl_device_exec_capabilities[];
extern const char *names_cl_device_exec_capabilities[];
extern const cl_uint count_cl_device_exec_capabilities;

/* cl_device_mem_cache_type */
extern const cl_uint fields_cl_device_mem_cache_type[];
extern const char *cl_names_cl_device_mem_cache_type[];
extern const char *names_cl_device_mem_cache_type[];
extern const cl_uint count_cl_device_mem_cache_type;

/* cl_command_queue_properties */
extern const cl_uint fields_cl_command_queue_properties[];
extern const char *cl_names_cl_command_queue_properties[];
extern const char *names_cl_command_queue_properties[];
extern const cl_uint count_cl_command_queue_properties;

/* cl_device_local_mem_type */
extern const cl_uint fields_cl_device_local_mem_type[];
extern const char *cl_names_cl_device_local_mem_type[];
extern const char *names_cl_device_local_mem_type[];
extern const cl_uint count_cl_device_local_mem_type;

/* cl_device_type */
extern const cl_uint fields_cl_device_type[];
extern const char *cl_names_cl_device_type[];
extern const char *names_cl_device_type[];
extern const cl_uint count_cl_device_type;

#endif /* __DATA_H__ */