/*!
 * @file
 * Contains unit tests for `boost::mpl11::Couple`.
 */

#include <boost/mpl11/couple.hpp>

#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/pair.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

namespace test_equal {
    template <int X, int Y>
    using couple = test::wrapper<
        test::minimal_requirements<Couple>,
        pair<
            test::wrapper<test::minimal_requirements<Comparable>, int_<X>>,
            test::wrapper<test::minimal_requirements<Comparable>, int_<Y>>
        >
    >;

    static_assert( equal<couple<0, 0>, couple<0, 0>>::value, "");
    static_assert(!equal<couple<1, 0>, couple<0, 0>>::value, "");
    static_assert(!equal<couple<0, 1>, couple<0, 0>>::value, "");
    static_assert(!equal<couple<0, 0>, couple<1, 0>>::value, "");
    static_assert(!equal<couple<0, 0>, couple<0, 1>>::value, "");
}

namespace test_less {
    template <int X, int Y>
    using couple = test::wrapper<
        test::minimal_requirements<Couple>,
        pair<
            test::wrapper<test::minimal_requirements<Orderable>, int_<X>>,
            test::wrapper<test::minimal_requirements<Orderable>, int_<Y>>
        >
    >;

    static_assert(!less<couple<0, 0>, couple<0, 0>>::value, "");
    static_assert( less<couple<0, 0>, couple<0, 1>>::value, "");
    static_assert( less<couple<0, 0>, couple<1, 0>>::value, "");
    static_assert( less<couple<0, 0>, couple<1, 1>>::value, "");

    static_assert(!less<couple<0, 1>, couple<0, 0>>::value, "");
    static_assert(!less<couple<0, 1>, couple<0, 1>>::value, "");
    static_assert( less<couple<0, 1>, couple<1, 0>>::value, "");
    static_assert( less<couple<0, 1>, couple<1, 1>>::value, "");

    static_assert(!less<couple<1, 0>, couple<0, 0>>::value, "");
    static_assert(!less<couple<1, 0>, couple<0, 1>>::value, "");
    static_assert(!less<couple<1, 0>, couple<1, 0>>::value, "");
    static_assert( less<couple<1, 0>, couple<1, 1>>::value, "");

    static_assert(!less<couple<1, 1>, couple<0, 0>>::value, "");
    static_assert(!less<couple<1, 1>, couple<0, 1>>::value, "");
    static_assert(!less<couple<1, 1>, couple<1, 0>>::value, "");
    static_assert(!less<couple<1, 1>, couple<1, 1>>::value, "");
}


int main() { }
