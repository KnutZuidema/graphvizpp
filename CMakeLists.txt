cmake_minimum_required(VERSION 3.8)
project(graphvizpp)

set(CMAKE_CXX_STANDARD 17)

add_library(graphvizpp SHARED src/graphviz.cpp src/graphviz.h)