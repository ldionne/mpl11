/*!
 * @file
 * Contains unit tests for `boost::mpl11::join`.
 */

#include <boost/mpl11/join.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/container.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/unpack.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::is_same;

template <typename S>
using as_seq = test::wrapper<test::minimal_requirements<Sequence>, S>;

template <typename S>
using as_cont = test::wrapper<test::minimal_requirements<Container>, S>;

struct f { template <typename ...> struct apply { struct type; }; };

template <typename S1, typename S2, typename ...Sn>
struct test_join {
    template <typename ...Catened>
    struct contains {
        static_assert(equal<
            vector<Catened...>,
            join<as_seq<S1>, as_seq<S2>, as_seq<Sn>...>
        >::value, "");

        static_assert(equal<
            vector<Catened...>,
            join_t<as_cont<S1>, as_seq<S2>, as_seq<Sn>...>
        >::value, "");

        static_assert(is_same<
            unpack_t<join<as_seq<S1>, as_seq<S2>, as_seq<Sn>...>, f>,
            apply_t<f, Catened...>
        >::value, "");
    };
};

struct a; struct b; struct c; struct d;
template <typename ...S1>
struct join_2 :
    test_join<vector<S1...>, vector<>>::template contains<S1...>,
    test_join<vector<S1...>, vector<a>>::template contains<S1..., a>,
    test_join<vector<S1...>, vector<a, b>>::template contains<S1..., a, b>
{ };

template <typename ...S1>
struct join_3 :
    test_join<vector<S1...>, vector<>, vector<>>::template contains<S1...>,
    test_join<vector<S1...>, vector<>, vector<a>>::template contains<S1..., a>,
    test_join<vector<S1...>, vector<>, vector<a, b>>::template contains<S1..., a, b>,

    test_join<vector<S1...>, vector<a>, vector<>>::template contains<S1..., a>,
    test_join<vector<S1...>, vector<a>, vector<b>>::template contains<S1..., a, b>,
    test_join<vector<S1...>, vector<a>, vector<b, c>>::template contains<S1..., a, b, c>,

    test_join<vector<S1...>, vector<a, b>, vector<>>::template contains<S1..., a, b>,
    test_join<vector<S1...>, vector<a, b>, vector<c>>::template contains<S1..., a, b, c>,
    test_join<vector<S1...>, vector<a, b>, vector<c, d>>::template contains<S1..., a, b, c, d>
{ };

struct x; struct y; struct z;
struct test_all :
    join_2<>,
    join_2<x>,
    join_2<x, y>,
    join_2<x, y, z>,

    // Join 3 sequences
    join_3<>,
    join_3<x>,
    join_3<x, y>,
    join_3<x, y, z>,

    // Join more than 3 sequences
    test_join<
        vector<a>, vector<b>, vector<>, vector<c, d>, vector<>, vector<x, y>,
        vector<z>, vector<>
    >::contains<a, b, c, d, x, y, z>
{ };


int main() { }
