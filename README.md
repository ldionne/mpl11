# duck - a C++11 template metaprogramming library
`duck` is a minimalistic template metaprogramming library aiming to provide
`boost::mpl`-like features for C++11 programmers. The big difference between
`duck` and `boost::mpl` is that `duck` works with parameter packs while
`boost::mpl` works with STL-like compile-time data structures. Also, since
`duck` can take advantage of C++11 features, metafunctions do not need to be
suffixed with the number of parameters they are called on. Finally, I find
the implementation of the `mpl` to be pretty unreadable. `duck` being pretty
straightforward, it can be used as a learning tool.


## Requirements
A conformant C++11 compiler and a C++11 standard library.
All the code is tested and compiles fine with _clang 3.0.0_ using _libc++_.


## Getting started
`duck` is a header only library. Just add the _include_ directory to your
compiler's search path and you are good to go. All you need to do is

    #include <duck.hpp>


## Running the tests
To run the tests, you will also need to have CMake installed.
If this is the case, you can go to the root of the project and do:

`make gen-cmake` --> Generates CMake files in the _build/_ directory.

`make unit-tests` --> Compiles the tests. All tests are compile-time.
