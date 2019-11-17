cmake_minimum_required(VERSION 3.14)
project(occ)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_executable(occ src/main.cpp)