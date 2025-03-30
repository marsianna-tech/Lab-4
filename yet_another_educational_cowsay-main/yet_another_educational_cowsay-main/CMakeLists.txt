cmake_minimum_required(VERSION 3.10.0)

project(ExtProj)				# Название проекта


set(SOURCE_EXE main.cpp)
include_directories(src)			# Расположение заголовочных файлов

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

add_subdirectory(src)				# Добавление подпроекта, указывается имя дирректории

target_link_libraries(main src)		
