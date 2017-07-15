cmake_minimum_required(VERSION 3.5)
project(dataStructure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -v")

set(SOURCE_FILES hashTable_main.c hashTable.h)
add_executable(dataStructure ${SOURCE_FILES})