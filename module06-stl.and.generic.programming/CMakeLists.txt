cmake_minimum_required(VERSION 3.23)
project(module06_stl_and_generic_programming)

set(CMAKE_CXX_STANDARD 17)

add_executable(exercise01 exercise01.cpp)
add_executable(exercise02 exercise02.cpp world-util.cpp world-util.h city.h city.cpp country.h country.cpp)
