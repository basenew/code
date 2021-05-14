cmake_minimum_required(VERSION 2.6)

set(project_name hello_cmake)

project(${project_name})
set(CMAKE_CXX_COMPILER c++)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -g -W)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS: " "${CMAKE_CXX_FLAGS}")

aux_source_directory(. DIR_SRCS)
add_executable(main ${DIR_SRCS})

