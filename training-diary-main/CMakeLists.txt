cmake_minimum_required(VERSION 3.28)
project(training_diary C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(training_diary
        main.c
        systemTech.c
        systemTech.h
        questionDataBool.c
        questionDataBool.h
        traningHooks.c
        traningHooks.h
        createTraning.c
        createTraning.h
        checkTraining.c
        checkTraining.h
        adviceTraining.c
        adviceTraining.h
        struct.h
        removeTraining.c
        removeTraining.h)
