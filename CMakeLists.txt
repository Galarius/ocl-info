cmake_minimum_required (VERSION 3.1)
project (oclinfo)

# Handle OpenCL
find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})
link_directories(${OpenCL_LIBRARY})

# Print the list of known compile features for this version of CMake
message ("cxx Flags:" ${CMAKE_CXX_FLAGS})
message("List of compile features: ${CMAKE_CXX_COMPILE_FEATURES}")

file (GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.c")

source_group("sources" FILES ${SOURCES})

add_executable (oclinfo ${SOURCES})

# Properties->General->Output Directory
set_target_properties(oclinfo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# Set the direcoties that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(oclinfo PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries (oclinfo ${OpenCL_LIBRARY})

install (TARGETS oclinfo RUNTIME DESTINATION bin)