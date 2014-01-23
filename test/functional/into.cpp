/*!
 * @file
 * Contains unit tests for `boost::mpl11::into`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

template <int> struct t;


template <typename ...>
struct variadic;

static_assert(std_is_same<
    into<variadic>::type::apply<>::type,
    variadic<>
>::value, "");

static_assert(std_is_same<
    into<variadic>::type::apply<t<0>>::type,
    variadic<t<0>>
>::value, "");

static_assert(std_is_same<
    into<variadic>::type::apply<t<0>, t<1>>::type,
    variadic<t<0>, t<1>>
>::value, "");

static_assert(std_is_same<
    into<variadic>::type::apply<t<0>, t<1>, t<2>>::type,
    variadic<t<0>, t<1>, t<2>>
>::value, "");



template <typename>
struct unary;

static_assert(std_is_same<
    into<unary>::type::apply<t<0>>::type,
    unary<t<0>>
>::value, "");



template <typename = struct default_>
struct unary_with_def;

static_assert(std_is_same<
    into<unary_with_def>::type::apply<>::type,
    unary_with_def<struct default_>
>::value, "");

static_assert(std_is_same<
    into<unary_with_def>::type::apply<t<0>>::type,
    unary_with_def<t<0>>
>::value, "");



template <typename, typename>
struct binary;

static_assert(std_is_same<
    into<binary>::type::apply<t<0>, t<1>>::type,
    binary<t<0>, t<1>>
>::value, "");


int main() { }
