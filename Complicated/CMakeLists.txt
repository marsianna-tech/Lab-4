cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
project(complicated)
add_executable(challengind challengind.cpp)

add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
    IMPORTED_LOCATION "/usr/lib/x86_64-linux-gnu/libgmsh.so.4.12.1"
    INTERFACE_INCLUDE_DIRECTORIES "/usr/include"
)
set(GMSH_LIBRARIES gmsh)



find_package(VTK REQUIRED)

include(${VTK_USE_FILE})

target_link_libraries(challengind ${VTK_LIBRARIES})
target_link_libraries(challengind ${GMSH_LIBRARIES})

