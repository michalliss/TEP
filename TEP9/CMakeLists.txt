cmake_minimum_required(VERSION 3.15)
project(TEP9)

set(CMAKE_CXX_STANDARD 14)

add_executable(TEP9 main.cpp CMscnProblem.cpp CMscnProblem.h CMatrix.cpp CMatrix.h CSolution.cpp CSolution.h Utils.cpp Utils.h constants.h)