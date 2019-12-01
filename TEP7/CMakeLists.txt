cmake_minimum_required(VERSION 3.15)
project(TEP7)

set(CMAKE_CXX_STANDARD 98)

add_executable(TEP7 main.cpp CMySmartPointer.h CRefCounter.h)