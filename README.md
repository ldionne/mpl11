# mpl11 - an implementation of the Boost.MPL library for C++11
`mpl11` is a minimalistic template metaprogramming library aiming to provide
`boost::mpl`-like features using C++11 techniques.


## Requirements
A conformant C++11 compiler and standard library.


## Getting started
The `mpl11` is a header only library. Just add the _include_ directory to
your compiler's search path and you are good to go. All you need to do is

    #include <mpl11.hpp>


## Running the tests
To run the tests, you will also need to have CMake installed.
If this is the case, you can go to the root of the project and do:

`make gen-cmake` --> Generates CMake files in the _build/_ directory.

`make unit-tests` --> Compiles the tests. All tests are compile-time only.
