cmake_minimum_required(VERSION 3.3)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c arch_logic.h arch_logic.c information.c information.h file_In_out.c
        file_In_out.h math_func.h math_func.c types.h)

add_executable(test ${SOURCE_FILES})