cmake_minimum_required(VERSION 4.1)
project(Operator_Overload_Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(Operator_Overload_Lab main.cpp
        BANKACCOUNT.h
        BankAccount.cpp)
