#ifndef __DATA_H__
#define __DATA_H__

#include "common.h"

/**
 * Describes type of information returned by clGetDeviceInfo
 */
enum {
	InfoTypeUInt,
	InfoTypeBool,
	InfoTypeFP,
	InfoTypeExec,
	InfoTypeChar,
	InfoTypeULong,
	InfoTypeMem,
	InfoTypeSizet,
	InfoTypeSizets,
	InfoTypeLocMem,
	InfoTypeLocQueue,
	InfoTypeDevice
};

#define INFO_SPACE 0xFFF

/* platform info */
extern const cl_platform_info fields_pinfo[];
extern const char *names_pinfo[];
extern const char *descs_pinfo[];
extern const cl_uint order_pinfo[];
extern const cl_uint n_pinfo;

/* device info */
extern const cl_device_info fields_dinfo[];
extern const char *names_dinfo[];
extern const char *descs_dinfo[];
extern const cl_uint types_dinfo[];
extern const cl_uint order_dinfo[];
extern const cl_uint n_dinfo;

/* cl_device_fp_config */
extern const cl_uint fields_fp[];
extern const char *names_fp[];
extern const char *descs_fp[];
extern const cl_uint n_fp;

/* cl_bool */
extern const cl_uint fields_bool[];
extern const char *names_bool[];
extern const char *descs_bool[];
extern const cl_uint count_bool;

/* cl_device_exec_capabilities */
extern const cl_uint fields_exec[];
extern const char *names_exec[];
extern const char *descs_exec[];
extern const cl_uint n_exec;

/* cl_device_mem_cache_type */
extern const cl_uint fields_mem[];
extern const char *names_mem[];
extern const char *descs_mem[];
extern const cl_uint n_mem;

/* cl_command_queue_properties */
extern const cl_uint fields_queue[];
extern const char *names_queue[];
extern const char *descs_queue[];
extern const cl_uint n_queue;

/* cl_device_local_mem_type */
extern const cl_uint fields_loc_mem[];
extern const char *names_loc_mem[];
extern const char *descs_loc_mem[];
extern const cl_uint n_loc_mem;

/* cl_device_type */
extern const cl_uint fields_device_type[];
extern const char *names_device_type[];
extern const char *descs_device_type[];
extern const cl_uint n_device_type;

#endif /* __DATA_H__ */