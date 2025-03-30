cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})



project(withlibs)
add_executable(simple simple.cpp)


find_package(VTK REQUIRED)

include(${VTK_USE_FILE})

target_link_libraries(simple ${VTK_LIBRARIES})

