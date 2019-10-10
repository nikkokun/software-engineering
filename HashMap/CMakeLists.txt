cmake_minimum_required(VERSION 3.14)
project(HashMap)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_executable(HashMap src/main.cpp)