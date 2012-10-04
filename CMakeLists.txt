cmake_minimum_required(VERSION 2.6)

project(mpl11)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11 -stdlib=libc++")
include_directories(include)

add_subdirectory(test)
