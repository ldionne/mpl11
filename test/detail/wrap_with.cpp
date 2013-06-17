/*!
 * @file
 * This file contains unit tests for `boost::mpl11::detail::wrap`.
 */

#include <boost/mpl11/detail/wrap_with.hpp>
#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/identity.hpp>

#include <boost/type_traits/is_same.hpp>


using namespace boost;
using namespace boost::mpl11;
using boost::mpl11::detail::wrap;

template <typename ...> struct Wrapper;


// Unconditional wrapping
static_assert(is_same<
    wrap<int>::with<Wrapper>::type, Wrapper<int>
>::value, "");


// Conditional wrapping
static_assert(is_same<
    wrap<int>::with<Wrapper>::if_c<true>::type, Wrapper<int>
>::value, "");
static_assert(is_same<
    wrap<int>::with<Wrapper>::if_c<false>::type, int
>::value, "");


// use eval<>
static_assert(is_same<
    wrap<eval<identity<int>>>::with<Wrapper>::type, Wrapper<int>
>::value, "");


int main() { }
