/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::variadic_at`.
 */

#include <boost/mpl11/detail/variadic_at.hpp>

#include <boost/mpl11/equal_to.hpp>


using namespace boost::mpl11;
using detail::variadic_at_c;

struct a0; struct a1; struct a2; struct a3; struct a4;

namespace test_indexing_at_the_beginning {
    static_assert(equal_to<
        variadic_at_c<0, a0>::type, a0
    >::type::value, "");

    static_assert(equal_to<
        variadic_at_c<0, a0, a1>::type, a0
    >::type::value, "");

    static_assert(equal_to<
        variadic_at_c<0, a0, a1, a2>::type, a0
    >::type::value, "");
}

namespace test_indexing_at_the_end {
    static_assert(equal_to<
        variadic_at_c<1, a0, a1>::type, a1
    >::type::value, "");

    static_assert(equal_to<
        variadic_at_c<2, a0, a1, a2>::type, a2
    >::type::value, "");

    static_assert(equal_to<
        variadic_at_c<3, a0, a1, a2, a3>::type, a3
    >::type::value, "");
}

namespace test_indexing_in_the_middle {
    static_assert(equal_to<
        variadic_at_c<1, a0, a1, a2>::type, a1
    >::type::value, "");

    static_assert(equal_to<
        variadic_at_c<2, a0, a1, a2, a3, a4>::type, a2
    >::type::value, "");

    static_assert(equal_to<
        variadic_at_c<3, a0, a1, a2, a3, a4>::type, a3
    >::type::value, "");
}


int main() { }
