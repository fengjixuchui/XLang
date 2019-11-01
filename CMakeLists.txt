cmake_minimum_required(VERSION 3.15)
project(XLang)
set(CMAKE_CXX_STANDARD 17)
add_executable(XLang main.cpp parser.cpp parser.h node.cpp node.h tokens.h)