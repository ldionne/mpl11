/*!
 * @file
 * Contains unit tests for variadic folds.
 */

#include <boost/mpl11/detail/lazy_variadic_foldr.hpp>
#include <boost/mpl11/detail/strict_variadic_foldl.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/integer.hpp>

#include "../minimal_foldable.hpp"


using namespace boost::mpl11;

template <typename x, typename y>
struct f { using type = f<typename x::type, typename y::type>; };
struct s { using type = s; };

template <int ...xs>
struct folding {
    static_assert(detail::std_is_same<
        typename foldr<lift<f>, s, minimal_foldable<int_<xs>...>>::type,
        typename detail::lazy_variadic_foldr<lift<f>, s, int_<xs>...>::type
    >::value, "");

    static_assert(detail::std_is_same<
        typename foldl<lift<f>, s, minimal_foldable<int_<xs>...>>::type,
        typename detail::strict_variadic_foldl<lift<f>, s, int_<xs>...>::type
    >::value, "");
};

struct tests
    : folding<>
    , folding<0>
    , folding<0, 1>
    , folding<0, 1, 2>
    , folding<0, 1, 2, 3>
    , folding<0, 1, 2, 3, 4>
    , folding<0, 1, 2, 3, 4, 5>
{ };


int main() { }
