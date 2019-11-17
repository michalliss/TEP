cmake_minimum_required(VERSION 3.15)
project(TEP5)

set(CMAKE_CXX_STANDARD 98)

add_executable(TEP5 main.cpp CTreeStatic.cpp CTreeStatic.h CTreeDynamic.cpp CTreeDynamic.h)