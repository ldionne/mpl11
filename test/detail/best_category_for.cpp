/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::best_category_for`.
 */

#include <boost/mpl11/detail/best_category_for.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/tags.hpp>


using namespace boost::mpl11;
using detail::best_category_for;
using detail::is_same;

template <typename Category>
struct with_cat;

namespace boost { namespace mpl11 {
    template <typename Category>
    struct dispatch<tag::category_of, with_cat<Category>>
        : identity<Category>
    { };
}} // end namespace boost::mpl11

template <unsigned int N> struct cat : cat<N - 1> { };
template <> struct cat<0> { };

// When the category (or any parent category) is not supported, it is
// returned as-is.
namespace test_unsupported {
    static_assert(is_same<
        best_category_for<with_cat<cat<0>>>::type,
        cat<0>
    >::value, "");

    static_assert(is_same<
        best_category_for<with_cat<cat<0>>, cat<1>>::type,
        cat<0>
    >::value, "");

    static_assert(is_same<
        best_category_for<with_cat<cat<0>>, cat<1>, cat<2>>::type,
        cat<0>
    >::value, "");
}

// When the category (or any parent category) is supported, the best
// match is returned.
namespace test_best_match {
    static_assert(is_same<
        best_category_for<with_cat<cat<0>>, cat<0>>::type,
        cat<0>
    >::value, "");

    static_assert(is_same<
        best_category_for<with_cat<cat<1>>, cat<0>>::type,
        cat<0>
    >::value, "");

    static_assert(is_same<
        best_category_for<with_cat<cat<1>>, cat<0>, cat<1>>::type,
        cat<1>
    >::value, "");

    static_assert(is_same<
        best_category_for<with_cat<cat<2>>, cat<0>, cat<1>>::type,
        cat<1>
    >::value, "");
}


int main() { }
