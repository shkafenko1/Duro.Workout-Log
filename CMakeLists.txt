cmake_minimum_required(VERSION 3.27)
project(DuroApp C)

set(CMAKE_C_STANDARD 11)

add_executable(DuroApp main.c
        auth.c
        auth.h
        functions.h)
