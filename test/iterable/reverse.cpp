/*!
 * @file
 * Contains unit tests for `boost::mpl11::reverse`.
 */

#include <boost/mpl11/iterable/reverse.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>


using namespace boost::mpl11;

template <int> struct x;

template <int ...Seq>
struct in_reverse_order {
    template <int ...Reversed>
    struct is
        : detail::iterable_test<
            reverse_t<detail::minimal_iterable<x<Seq>...>>,
            x<Reversed>...
        >
    { };
};

struct tests :
    in_reverse_order<>::is<>,
    in_reverse_order<0>::is<0>,
    in_reverse_order<0, 1>::is<1, 0>,
    in_reverse_order<0, 1, 2>::is<2, 1, 0>,
    in_reverse_order<0, 1, 2, 3>::is<3, 2, 1, 0>,
    in_reverse_order<0, 1, 2, 3, 4>::is<4, 3, 2, 1, 0>
{ };


int main() { }
