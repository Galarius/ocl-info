cmake_minimum_required (VERSION 2.8)
project (oclinfo)

# Handle OpenCL
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package( OpenCL REQUIRED )

message(STATUS "OpenCL found: ${OPENCL_FOUND}")
message(STATUS "OpenCL includes: ${OPENCL_INCLUDE_DIRS}")
message(STATUS "OpenCL CXX includes: ${OPENCL_HAS_CPP_BINDINGS}")
message(STATUS "OpenCL libraries: ${OPENCL_LIBRARIES}")

include_directories(${OPENCL_INCLUDE_DIRS})
link_directories(${OPENCL_LIBRARIES})

IF(OpenCL_FOUND)
    set(CMAKE_C_FLAGS "-std=c90")
    message ("C Flags:" ${CMAKE_C_FLAGS})
    message("List of compile features: ${CMAKE_C_COMPILE_FEATURES}")

    file (GLOB HEADERS "${PROJECT_SOURCE_DIR}/src/*.h")
    file (GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

    source_group("headers" FILES ${HEADERS})
    source_group("sources" FILES ${SOURCES})

    add_executable (oclinfo ${HEADERS} ${SOURCES})

    set_target_properties(oclinfo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

    target_include_directories(oclinfo PRIVATE ${PROJECT_SOURCE_DIR}/include)
    target_link_libraries (oclinfo ${OPENCL_LIBRARIES})

    # install (TARGETS oclinfo RUNTIME DESTINATION bin)
ENDIF()