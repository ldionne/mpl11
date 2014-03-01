/*!
 * @file
 * Contains unit tests for `boost::mpl11::flip`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

template <typename, typename>
struct binary { struct type; };

template <typename ...>
struct variadic { struct type; };

struct a0; struct a1; struct a2; struct a3; struct a4; struct a5;

static_assert(std_is_same<
    flip<quote<binary>>::type::apply<a0, a1>::type,
    binary<a1, a0>::type
>::value, "");

static_assert(std_is_same<
    flip<quote<variadic>>::type::apply<a0, a1, a2>::type,
    variadic<a1, a0, a2>::type
>::value, "");

static_assert(std_is_same<
    flip<quote<variadic>>::type::apply<a0, a1, a2, a3>::type,
    variadic<a1, a0, a2, a3>::type
>::value, "");

static_assert(std_is_same<
    flip<quote<variadic>>::type::apply<a0, a1, a2, a3, a4>::type,
    variadic<a1, a0, a2, a3, a4>::type
>::value, "");

static_assert(std_is_same<
    flip<quote<variadic>>::type::apply<a0, a1, a2, a3, a4, a5>::type,
    variadic<a1, a0, a2, a3, a4, a5>::type
>::value, "");


int main() { }
