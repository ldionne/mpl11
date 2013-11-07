# mpl11 - a C++11 remake of the Boost.MPL


## Disclaimer
This is not an official Boost library. It might be proposed as a replacement
for the MPL in the future, but there is no guarantee.

The code is unstable at the moment; do not use for production.


## Requirements
A conformant C++11 compiler (a conformant C++11 standard library
is _not_ required).


## Getting started
The __mpl11__ is a header only library. Just add the _include_ directory to
your compiler's search path and you are good to go.


## Reference documentation
Available [here](http://ldionne.github.io/mpl11).


## Testing
To compile the tests, you will also need to have CMake installed.
If this is the case, you can go to the root of the project and do:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make unit # Compiles the tests. All tests are compile-time only.
