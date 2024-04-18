cmake_minimum_required(VERSION 3.27)
project(DuroApp C)

set(CMAKE_C_STANDARD 11)

add_executable(DuroApp main.c
        auth.c
        settings.c
        access_functions.c
        write_functions.c
        tips_functions.c
        write_functions.h
        access_functions.h)