cmake_minimum_required(VERSION 3.23)
project(PolynomialExpressions)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PolynomialExpressions
        main.cpp
        main.h
        IO.cpp
        node.cpp)
