/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::sort`.
 */

#include <boost/mpl11/sort.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/vector.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/greater.hpp>
#include <boost/mpl11/less_equal.hpp>


using namespace boost::mpl11;
using algorithm::sort;
using container::vector;

template <int ...Values>
using vector_c = vector<int_<Values>...>;

namespace without_predicate {
    static_assert(equal_to<
        sort<vector_c<>>::type,
        vector_c<>
    >::type::value, "");

    static_assert(equal_to<
        sort<vector_c<0>>::type,
        vector_c<0>
    >::type::value, "");

    static_assert(equal_to<
        sort<vector_c<0, 1>>::type,
        vector_c<0, 1>
    >::type::value, "");

    static_assert(equal_to<
        sort<vector_c<1, 0>>::type,
        vector_c<0, 1>
    >::type::value, "");

    static_assert(equal_to<
        sort<vector_c<0, 3, 9, 4, 7, 2, 1, 8, 5, 6>>::type,
        vector_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>
    >::type::value, "");
}

namespace with_predicate {
    static_assert(equal_to<
        sort<vector_c<>, greater<_1, _2>>::type,
        vector_c<>
    >::type::value, "");

    static_assert(equal_to<
        sort<vector_c<0>, greater<_1, _2>>::type,
        vector_c<0>
    >::type::value, "");

    static_assert(equal_to<
        sort<vector_c<0, 1>, greater<_1, _2>>::type,
        vector_c<1, 0>
    >::type::value, "");

    static_assert(equal_to<
        sort<vector_c<1, 0>, greater<_1, _2>>::type,
        vector_c<1, 0>
    >::type::value, "");

    static_assert(equal_to<
        sort<vector_c<0, 3, 9, 4, 7, 2, 1, 8, 5, 6>, greater<_1, _2>>::type,
        vector_c<9, 8, 7, 6, 5, 4, 3, 2, 1, 0>
    >::type::value, "");
}

namespace with_non_strict_ordering_relation {
    static_assert(equal_to<
        sort<vector_c<1, 4, 3, 6>, less_equal<_1, _2>>::type,
        vector_c<1, 3, 4, 6>
    >::type::value, "");

    static_assert(equal_to<
        sort<vector_c<1, 2, 4, 3, 2, 6>, less_equal<_1, _2>>::type,
        vector_c<1, 2, 2, 3, 4, 6>
    >::type::value, "");

    static_assert(equal_to<
        sort<vector<true_, false_, true_>, _1>::type,
        vector<true_, true_, false_>
    >::type::value, "");
}


int main() { }
