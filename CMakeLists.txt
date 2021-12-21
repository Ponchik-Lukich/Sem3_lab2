cmake_minimum_required(VERSION 3.20)
project(Newlaba)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("Newlaba-tests")

add_executable(Newlaba main.cpp Function.h Pair.h)
