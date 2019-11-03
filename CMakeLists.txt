cmake_minimum_required(VERSION 3.15)
project(022_Algorithms C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(022_Algorithms
        binarysearch.c
        main.c
        queue.c
        stack.c)
