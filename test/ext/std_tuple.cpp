/*!
 * @file
 * Contains unit tests for `std::tuple`.
 */

#include <boost/mpl11/ext/std_tuple.hpp>

#include "../check_finite_iterable.hpp"
#include <boost/mpl11/list.hpp>
#include <boost/mpl11/functional.hpp>
#include <tuple>


using namespace boost::mpl11;

template <int> struct t;

template <int ...xs>
struct tuple_of {
    using lst = list<box<t<xs>>...>;
    using tpl = std::tuple<t<xs>...>;
    using conses = typename foldr<lift<cons>, list<>, lst>::type;

    // Check Iterable instantiation
    static_assert(sizeof(
        check_finite_iterable<box<std::tuple<t<xs>...>>, box<t<xs>>...>
    ), "");


    // Check conversion to List
    static_assert(equal<
        typename cast_to<List>::type::template apply<tpl>,
        lst
    >::value, "");


    // Check conversion from List
    static_assert(equal<
        typename cast_to<StdTuple>::type::template apply<lst>,
        box<tpl>
    >::value, "");

    static_assert(equal<
        typename cast_to<StdTuple>::type::template apply<conses>,
        box<tpl>
    >::value, "");
};

struct tests
    : tuple_of<>
    , tuple_of<0>
    , tuple_of<0, 1>
    , tuple_of<0, 1, 2>
    , tuple_of<0, 1, 2, 3>
    , tuple_of<0, 1, 2, 3, 4>
    , tuple_of<0, 1, 2, 3, 4, 5>
{ };


int main() { }
