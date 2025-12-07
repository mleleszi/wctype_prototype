cmake_minimum_required(VERSION 3.25.1)
project(wctype_cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(benchmarks)
