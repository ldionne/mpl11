# mpl11 - an implementation of the Boost.MPL library for C++11

## Requirements
A conformant C++11 compiler and standard library.


## Getting started
The __mpl11__ is a header only library. Just add the _include_ directory to
your compiler's search path and you are good to go. All you need to do is

    #include <mpl11.hpp>


## Running the tests
To run the tests, you will also need to have CMake installed.
If this is the case, you can go to the root of the project and do:

    $ make gen-cmake # Generates CMake files in the _build/_ directory
    $ make unit      # Compiles the tests. All tests are compile-time only.
