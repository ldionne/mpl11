/*!
 * @file
 * Contains unit tests for `boost::mpl11::DirectionalSequence`.
 */

#include <boost/mpl11/directional_sequence.hpp>

#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/front.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::is_same;

namespace test_front {
    template <int> struct x;
    template <int ...i>
    using seq = test::wrapper<
        test::minimal_requirements<DirectionalSequence>, vector<x<i>...>
    >;

    static_assert(is_same<front<seq<0>>::type, x<0>>::value, "");
    static_assert(is_same<front<seq<0, 1>>::type, x<0>>::value, "");
    static_assert(is_same<front<seq<0, 1, 2>>::type, x<0>>::value, "");
}

namespace test_equal {
    template <int ...i>
    using seq = test::wrapper<
        test::minimal_requirements<DirectionalSequence>,
        vector<
            test::wrapper<test::minimal_requirements<Comparable>, int_<i>>...
        >
    >;

    static_assert(equal<seq<>, seq<>>::value, "");
    static_assert(equal<seq<0>, seq<0>>::value, "");
    static_assert(equal<seq<0, 1>, seq<0, 1>>::value, "");

    static_assert(!equal<seq<>, seq<0>>::value, "");
    static_assert(!equal<seq<0>, seq<>>::value, "");
    static_assert(!equal<seq<0>, seq<0, 1>>::value, "");
    static_assert(!equal<seq<0, 1>, seq<0>>::value, "");

    static_assert(!equal<seq<0>, seq<1>>::value, "");
    static_assert(!equal<seq<0, 1>, seq<0, 2>>::value, "");
    static_assert(!equal<seq<0, 1, 2>, seq<0, 1, 3>>::value, "");
}

namespace test_less {
    template <int ...i>
    using seq = test::wrapper<
        test::minimal_requirements<DirectionalSequence>,
        vector<
            test::wrapper<test::minimal_requirements<Orderable>, int_<i>>...
        >
    >;

    static_assert(!less<seq<>, seq<>>::value, "");
    static_assert( less<seq<>, seq<0>>::value, "");
    static_assert( less<seq<>, seq<0, 1>>::value, "");

    static_assert(!less<seq<0>, seq<>>::value, "");
    static_assert(!less<seq<0>, seq<0>>::value, "");
    static_assert( less<seq<0>, seq<1>>::value, "");
    static_assert( less<seq<0>, seq<0, 1>>::value, "");

    static_assert(!less<seq<0, 1>, seq<>>::value, "");
    static_assert(!less<seq<0, 1>, seq<0>>::value, "");
    static_assert( less<seq<0, 1>, seq<1>>::value, "");
    static_assert(!less<seq<0, 1>, seq<0, 1>>::value, "");
    static_assert( less<seq<0, 1>, seq<0, 1, 2>>::value, "");
    static_assert(!less<seq<0, 2>, seq<0, 1>>::value, "");
    static_assert(!less<seq<0, 2>, seq<0, 1, 2>>::value, "");

    // miscellaneous tests for less
    static_assert( less<seq<0, 1, 2, 3, 4>, seq<0, 1, 4, 1>>::value, "");
    static_assert(!less<seq<0, 1, 4, 3, 4>, seq<0, 1, 2, 3, 4>>::value, "");
}


int main() { }
