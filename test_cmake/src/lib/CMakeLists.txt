cmake_minimum_required(VERSION 3.10)

aux_source_directory(. SRC_FILES)
add_library (test_lib SHARED ${SRC_FILES})

