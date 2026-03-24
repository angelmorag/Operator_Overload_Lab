cmake_minimum_required(VERSION 4.1)
project(Pointer_Vectors_Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pointer_Vectors_Lab main.cpp
        Book.cpp
        Book.h
        Inventory.cpp
        Inventory.h)
