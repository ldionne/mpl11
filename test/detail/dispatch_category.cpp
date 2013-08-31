/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::dispatch_category`.
 */

#include <boost/mpl11/detail/dispatch_category.hpp>

#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;
using detail::dispatch_category;

template <unsigned int N> struct priority : priority<N - 1> { };
template <> struct priority<0> { };

// When the category (or any parent category) is not supported, it is
// returned as-is.
namespace test_unsupported {
    static_assert(is_same<
        dispatch_category<priority<0>>::type,
        priority<0>
    >::value, "");

    static_assert(is_same<
        dispatch_category<priority<0>, priority<1>>::type,
        priority<0>
    >::value, "");

    static_assert(is_same<
        dispatch_category<priority<0>, priority<1>, priority<2>>::type,
        priority<0>
    >::value, "");
}

// When the category (or any parent category) is supported, the best
// match is returned.
namespace test_best_match {
    static_assert(is_same<
        dispatch_category<priority<0>, priority<0>>::type,
        priority<0>
    >::value, "");

    static_assert(is_same<
        dispatch_category<priority<1>, priority<0>>::type,
        priority<0>
    >::value, "");

    static_assert(is_same<
        dispatch_category<priority<1>, priority<0>, priority<1>>::type,
        priority<1>
    >::value, "");

    static_assert(is_same<
        dispatch_category<priority<2>, priority<0>, priority<1>>::type,
        priority<1>
    >::value, "");
}


int main() { }
