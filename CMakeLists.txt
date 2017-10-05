cmake_minimum_required (VERSION 3.1)
project (oclinfo)

# Handle OpenCL
find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})
link_directories(${OpenCL_LIBRARY})

IF(OpenCL_FOUND)
    # Print the list of known compile features for this version of CMake
    message ("C Flags:" ${CMAKE_C_FLAGS})
    message("List of compile features: ${CMAKE_C_COMPILE_FEATURES}")

    file (GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.c")

    source_group("sources" FILES ${SOURCES})

    add_executable (oclinfo ${SOURCES})

    set_target_properties(oclinfo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

    target_include_directories(oclinfo PRIVATE ${PROJECT_SOURCE_DIR}/include)
    target_link_libraries (oclinfo ${OpenCL_LIBRARY})

    install (TARGETS oclinfo RUNTIME DESTINATION bin)
ENDIF()