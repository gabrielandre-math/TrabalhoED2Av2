cmake_minimum_required(VERSION 3.28)
project(ED2___AV2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ED2___AV2
        "bin/Debug/ED2 - AV2.exe"
        obj/Debug/main.o
        obj/Debug/Q1.o
        obj/Debug/Q2.o
        obj/Debug/Q3.o
        obj/Debug/Q4.o
        "ED2 - AV2.cbp"
        "ED2 - AV2.depend"
        "ED2 - AV2.layout"
        grafo.csv
        main.c
        Q1.c
        Q2.c
        Q3.c
        Q4.c)
