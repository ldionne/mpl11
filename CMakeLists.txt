
project(duck)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++0x -stdlib=libc++")
include_directories(include)

add_subdirectory(test)
