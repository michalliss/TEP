cmake_minimum_required(VERSION 3.15)
project(TEP6)

set(CMAKE_CXX_STANDARD 98)

add_executable(TEP6 main.cpp CTreeDynamic.tpp CTreeDynamic.h constants.h)