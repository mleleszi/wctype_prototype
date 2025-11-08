cmake_minimum_required(VERSION 3.31)
project(wctype_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(wctype_cpp main.cpp
        generator.h)
