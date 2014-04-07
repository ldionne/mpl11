/*!
 * @file
 * Contains unit tests for `std::tuple`.
 */

#include <boost/mpl11/ext/std_tuple.hpp>

#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/list.hpp>
#include <boost/mpl11/test/expect.hpp>
#include <boost/mpl11/test/iterable.hpp>
#include <tuple>


using namespace boost::mpl11;

template <typename ...xs>
struct tuple { using type = std::tuple<xs...>; };

template <int>
struct t;

template <int ...xs>
struct test_conversion {
    template <typename Datatype, typename x>
    using _cast = typename cast_to<Datatype>::type::
                  template apply<typename x::type>;

    using as_list = list_<t<xs>...>;
    using as_tuple = tuple<t<xs>...>;
    using as_cons = foldr<lift<cons>, list<>, as_list>;

    using go = typename test::instantiate<
        typename test::expect<_cast<List, as_tuple>>::template to_eq<as_list>,
        typename test::expect<_cast<StdTuple, as_list>>::template to_eq<as_tuple>,
        typename test::expect<_cast<StdTuple, as_cons>>::template to_eq<as_tuple>
    >::type;
};

struct tests
    : test::Iterable<tuple>

    , test_conversion<>
    , test_conversion<0>
    , test_conversion<0, 1>
    , test_conversion<0, 1, 2>
    , test_conversion<0, 1, 2, 3>
    , test_conversion<0, 1, 2, 3, 4>
    , test_conversion<0, 1, 2, 3, 4, 5>
{ };


int main() { }
