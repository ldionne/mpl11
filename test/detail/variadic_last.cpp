/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::variadic_last`.
 */

#include <boost/mpl11/detail/variadic_last.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;
using detail::variadic_last;

template <int> struct x;

template <int ...Seq>
struct last_of {
    template <int Last>
    struct is {
        static_assert(is_same<
            typename variadic_last<x<Seq>...>::type,
            x<Last>
        >::value, "");
    };
};

struct tests :
    last_of<0>::is<0>,
    last_of<0, 1>::is<1>,
    last_of<0, 1, 2>::is<2>,
    last_of<0, 1, 2, 3>::is<3>,
    last_of<0, 1, 2, 3, 4>::is<4>,
    last_of<0, 1, 2, 3, 4, 5>::is<5>,
    last_of<0, 1, 2, 3, 4, 5, 6>::is<6>
{ };


int main() { }
