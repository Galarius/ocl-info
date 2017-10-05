#if defined(__APPLE__) || defined(__MACOSX)
    #include <OpenCL/opencl.h>
#elif defined(__linux__)
    #include <CL/cl.h>
    /* if ocl-icd-opencl-dev package is used */
    #ifndef CL_DEVICE_HALF_FP_CONFIG
    #define CL_DEVICE_HALF_FP_CONFIG            0x1033
    #endif
#else
    #include <CL/cl.h>
#endif