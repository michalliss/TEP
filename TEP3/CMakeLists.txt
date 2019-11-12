cmake_minimum_required(VERSION 3.15)
project(TEP3)

set(CMAKE_CXX_STANDARD 98)

add_executable(TEP3 main.cpp CFileLastError.cpp CFileLastError.h CFileThrowEx.cpp CFileThrowEx.h CFileErrCode.cpp CFileErrCode.h constants.h)