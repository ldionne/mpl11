/*!
 * @file
 * Comparison of `boost::mpl11::foldl` and `boost::mpl::fold` on a vector.
 */

/*

The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null -I ~/code/mpl11/include -c vector_foldl.cpp
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null -I ~/code/mpl11/include -c vector_foldl.cpp
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null -I ~/code/mpl11/include -c vector_foldl.cpp

Commands were ran 5 times and the average was taken.

          | clang v3.4  | Apple LLVM clang 5.0 | GCC 4.9.0 20131201 (experimental) |
------------------------------------------------------------------------------------
USE_MPL11 |    0.32s    |         0.14s        |               0.16s               |
USE_MPL   |    0.26s    |         0.15s        |               0.25s               |

*/


#define USE_MPL11
// #define USE_MPL

#if defined(USE_MPL11)

    #include <boost/mpl11/vector.hpp>
    #include <boost/mpl11/foldl.hpp>
    namespace mpl = boost::mpl11;
    #define MPL_VECTOR mpl::vector
    #define MPL_FOLD mpl::foldl

#elif defined(USE_MPL)

    #include <boost/mpl/vector/vector50.hpp>
    #include <boost/mpl/fold.hpp>
    namespace mpl = boost::mpl;
    #define MPL_VECTOR mpl::vector50
    #define MPL_FOLD mpl::fold

#endif

template <int> struct x;

// ruby -e "puts 50.times.collect{|i| \"x<#{i}>\"}.join(', ')" | pbcopy
using Vector = MPL_VECTOR<
    x<0>, x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>, x<11>, x<12>, x<13>, x<14>, x<15>, x<16>, x<17>, x<18>, x<19>, x<20>, x<21>, x<22>, x<23>, x<24>, x<25>, x<26>, x<27>, x<28>, x<29>, x<30>, x<31>, x<32>, x<33>, x<34>, x<35>, x<36>, x<37>, x<38>, x<39>, x<40>, x<41>, x<42>, x<43>, x<44>, x<45>, x<46>, x<47>, x<48>, x<49>
>;

struct f { template <typename, typename> struct apply { struct type; }; };
using Go = MPL_FOLD<Vector, struct dummy, f>::type;


int main() { }
