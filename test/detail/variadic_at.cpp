/*!
 * @file
 * This file contains unit tests for `boost::mpl11::detail::variadic_at`.
 */

#include <boost/mpl11/detail/variadic_at.hpp>

#include <boost/mpl11/is_same.hpp>


using boost::mpl11::is_same;
using boost::mpl11::detail::variadic_at_c;

struct a0; struct a1; struct a2; struct a3; struct a4;

namespace test_indexing_at_the_beginning {
    static_assert(is_same<
        variadic_at_c<0, a0>::type, a0
    >::value, "");

    static_assert(is_same<
        variadic_at_c<0, a0, a1>::type, a0
    >::value, "");

    static_assert(is_same<
        variadic_at_c<0, a0, a1, a2>::type, a0
    >::value, "");
}

namespace test_indexing_at_the_end {
    static_assert(is_same<
        variadic_at_c<1, a0, a1>::type, a1
    >::value, "");

    static_assert(is_same<
        variadic_at_c<2, a0, a1, a2>::type, a2
    >::value, "");

    static_assert(is_same<
        variadic_at_c<3, a0, a1, a2, a3>::type, a3
    >::value, "");
}

namespace test_indexing_in_the_middle {
    static_assert(is_same<
        variadic_at_c<1, a0, a1, a2>::type, a1
    >::value, "");

    static_assert(is_same<
        variadic_at_c<2, a0, a1, a2, a3, a4>::type, a2
    >::value, "");

    static_assert(is_same<
        variadic_at_c<3, a0, a1, a2, a3, a4>::type, a3
    >::value, "");
}


int main() { }
