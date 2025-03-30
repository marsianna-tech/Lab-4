cmake_minimum_required(VERSION 3.10.0)


project(src)

file(GLOB_RECURSE SOURCES *.cpp)

add_library(src STATIC ${SOURCES})