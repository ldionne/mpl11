/*!
 * @file
 * Contains unit tests for `boost::mpl11::lift`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct a0; struct a1; struct a2;
template <typename ...> struct f { struct type; };

static_assert(std_is_same<
    lift<f>::type::apply<>::type,
    f<>::type
>::value, "");

static_assert(std_is_same<
    lift<f>::type::apply<a0>::type,
    f<a0>::type
>::value, "");

static_assert(std_is_same<
    lift<f>::type::apply<a0, a1>::type,
    f<a0, a1>::type
>::value, "");

static_assert(std_is_same<
    lift<f>::type::apply<a0, a1, a2>::type,
    f<a0, a1, a2>::type
>::value, "");


int main() { }
