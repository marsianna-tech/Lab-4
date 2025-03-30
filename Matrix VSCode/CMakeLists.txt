cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
project(Matrix VERSION 0.1.0 LANGUAGES C CXX)


file(GLOB_RECURSE SOURCES main.cpp matrix.cpp)

message(${SOURCES})
add_executable(${PROJECT_NAME} ${SOURCES})
