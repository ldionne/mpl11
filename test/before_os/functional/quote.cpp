/*!
 * @file
 * Contains unit tests for `boost::mpl11::quote`.
 */

#include <boost/mpl11/quote.hpp>

#include <boost/mpl11/equal_to.hpp>


using namespace boost::mpl11;

namespace with_non_metafunction {
    template <typename ...> struct T;

    static_assert(equal_to<
        quote<T>::apply<>::type,
        T<>
    >::type::value, "");

    static_assert(equal_to<
        quote<T>::apply<struct a0>::type,
        T<struct a0>
    >::type::value, "");

    static_assert(equal_to<
        quote<T>::apply<struct a0, struct a1>::type,
        T<struct a0, struct a1>
    >::type::value, "");
}

namespace with_metafunction {
    template <typename ...> struct F { struct type; };

    static_assert(equal_to<
        quote<F>::apply<>::type,
        F<>::type
    >::type::value, "");

    static_assert(equal_to<
        quote<F>::apply<struct a0>::type,
        F<struct a0>::type
    >::type::value, "");

    static_assert(equal_to<
        quote<F>::apply<struct a0, struct a1>::type,
        F<struct a0, struct a1>::type
    >::type::value, "");
}


int main() { }
