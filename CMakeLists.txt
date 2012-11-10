cmake_minimum_required(VERSION 2.8)

project(mpl11)

add_definitions(-Wall -Wextra -pedantic -std=c++11)
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    add_definitions(-stdlib=libc++)
endif()

include_directories(include)

add_subdirectory(test)
