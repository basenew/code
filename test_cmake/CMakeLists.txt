cmake_minimum_required(VERSION 3.10)
message("project dir:${PROJECT_SOURCE_DIR}")
set(OUTPUT_PATHS ${PROJECT_SOURCE_DIR}/build/output)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3 -fexceptions -fPIC -Wl,-v -Wall -Wno-strict-aliasing -Wno-unknown-pragmas -Wno-switch")

link_directories(
  ${OUTPUT_PATHS}/lib
)

add_subdirectory(src)

