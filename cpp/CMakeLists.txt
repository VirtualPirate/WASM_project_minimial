cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXECUTABLE_SUFFIX ".js")

add_definitions(-std=c++17 -O3)
include_directories(include)

file(GLOB SOURCES src/*.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../generated")
set(CMAKE_BUILD_RPATH "/build")
set(EXPORTED_FUNCTIONS "'[_main, _hello]'")

add_executable(compiled ${SOURCES})

set_target_properties(compiled PROPERTIES LINK_FLAGS "-O3 -s WASM=0 -s EXPORTED_FUNCTIONS=${EXPORTED_FUNCTIONS}")

