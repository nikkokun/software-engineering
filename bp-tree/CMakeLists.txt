cmake_minimum_required(VERSION 3.14)
project(bp_tree)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)
include_directories(lib)

set(Sources lib/block.cpp lib/node.cpp lib/bplustree.cpp)
set(Headers include/block.h include/node.h include/bplustree.h)

add_executable(bp_tree main.cpp ${Sources} ${Headers})