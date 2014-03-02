/*!
 * @file
 * Contains unit tests for `boost::mpl11::arg`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/integer.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

template <unsigned long n>
struct nth {
    template <int ...xs>
    struct of {
        template <int x>
        struct is {
            static_assert(std_is_same<
                typename arg<n>::type::template apply<int_<xs>...>::type,
                int_<x>
            >::value, "");
        };
    };
};

struct tests
    : nth<1>::of<1>::is<1>
    , nth<1>::of<1, 2>::is<1>
    , nth<1>::of<1, 2, 3>::is<1>
    , nth<1>::of<1, 2, 3, 4>::is<1>

    , nth<2>::of<1, 2>::is<2>
    , nth<2>::of<1, 2, 3>::is<2>
    , nth<2>::of<1, 2, 3, 4>::is<2>
    , nth<2>::of<1, 2, 3, 4, 5>::is<2>

    , nth<3>::of<1, 2, 3>::is<3>
    , nth<3>::of<1, 2, 3, 4>::is<3>
    , nth<3>::of<1, 2, 3, 4, 5>::is<3>
{ };


int main() { }
