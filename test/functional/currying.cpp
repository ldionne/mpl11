/*!
 * @file
 * Contains unit tests for curry-related metafunctions from @ref Functional.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

template <typename ...x>
struct f { struct type; };

template <int> struct x;

template <typename ...x>
struct test_with_args {
    using curried = curry<sizeof...(x), quote<f>>;
    using uncurried = uncurry<sizeof...(x), curried>;

    static_assert(std_is_same<
        typename apply_curried<curried, x...>::type,
        typename f<x...>::type
    >::value, "");

    static_assert(std_is_same<
        typename apply<uncurried, x...>::type,
        typename f<x...>::type
    >::value, "");
};

struct tests
    : test_with_args<x<0>>
    , test_with_args<x<0>, x<1>>
    , test_with_args<x<0>, x<1>, x<2>>
    , test_with_args<x<0>, x<1>, x<2>, x<3>>
    , test_with_args<x<0>, x<1>, x<2>, x<3>, x<4>>
{ };


int main() { }
