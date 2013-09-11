/*!
 * @file
 * Contains unit tests for `boost::mpl11::quote`.
 */

#include <boost/mpl11/functional/quote.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using boost::mpl11::detail::is_same;

namespace with_non_metafunction {
    template <typename ...> struct T;

    static_assert(is_same<
        quote<T>::apply<>::type,
        T<>
    >::value, "");

    static_assert(is_same<
        quote<T>::apply<struct a0>::type,
        T<struct a0>
    >::value, "");

    static_assert(is_same<
        quote<T>::apply<struct a0, struct a1>::type,
        T<struct a0, struct a1>
    >::value, "");
}

namespace with_metafunction {
    template <typename ...> struct F { struct type; };

    static_assert(is_same<
        quote<F>::apply<>::type,
        F<>::type
    >::value, "");

    static_assert(is_same<
        quote<F>::apply<struct a0>::type,
        F<struct a0>::type
    >::value, "");

    static_assert(is_same<
        quote<F>::apply<struct a0, struct a1>::type,
        F<struct a0, struct a1>::type
    >::value, "");
}


int main() { }
