cmake_minimum_required(VERSION 2.6)

set(PRJ ${PROJECT_SOURCE_DIR})
set(BIN ${PRJ}/bin)
set(LIB ${PRJ}/lib)
set(INC ${PRJ}/include)

set(LIBRARY_OUTPUT_PATH ${LIB})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN})

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 -fexceptions -fPIC -Wl,-v -Wall -Wno-strict-aliasing -Wno-unknown-pragmas -Wno-switch")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-reorder -Wno-unused-function -Wno-unused-variable -Wno-unused-parameter -Wno-deprecated-declarations")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")

link_directories(
  ${LIB}
)

include_directories(
  ${INC}
)

add_subdirectory(src)

execute_process(
  COMMAND mkdir -p ${BIN}
)

