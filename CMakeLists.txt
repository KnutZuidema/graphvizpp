cmake_minimum_required(VERSION 3.10)
project(graphvizpp)

set(CMAKE_CXX_STANDARD 17)

add_library(graphvizpp SHARED library.cpp library.h)