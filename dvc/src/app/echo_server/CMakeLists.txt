cmake_minimum_required(VERSION 2.6)

aux_source_directory(./ SRC_LIST)

include_directories(
  ./
)

set(targetName echo_server)
add_executable(${targetName} ${SRC_LIST})

#target_link_libraries(${targetName})

