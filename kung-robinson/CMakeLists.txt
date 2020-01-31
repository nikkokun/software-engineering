cmake_minimum_required(VERSION 3.14)
project(kung-robinson)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_executable(kung-robinson src/main.cpp)