cmake_minimum_required(VERSION 2.8.4)
project(Practical-C2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/treenode.h src/treenode.c src/stacknode.c src/practical_trees.c)
add_executable(main ${SOURCE_FILES})