/*!
 * @file
 * Contains unit tests for `boost::mpl11::flatten_if`.
 */

#include <boost/mpl11/flatten_if.hpp>

#include <boost/mpl11/container.hpp>
#include <boost/mpl11/directional_sequence.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

template <typename ...T>
using sequence = test::wrapper<
    test::minimal_requirements<DirectionalSequence>, vector<T...>
>;

struct flat_minimal_sequence : test::minimal_requirements<Sequence> { };
template <typename ...T>
using flat_sequence = test::wrapper<
    flat_minimal_sequence, vector<T...>
>;

template <typename ...T>
using container = test::wrapper<
    test::minimal_requirements<Container>, vector<T...>
>;

struct x0; struct x1; struct x2;
struct y0; struct y1; struct y2;
struct z0; struct z1; struct z2;

struct must_flatten {
    template <typename T>
    struct apply
        : false_
    { };

    template <typename ...T>
    struct apply<flat_sequence<T...>>
        : true_
    { };
};

template <typename ...ToFlatten>
struct test_flatten {
    template <typename ...Elements>
    struct equals {
        using Lazy = flatten_if<sequence<ToFlatten...>, must_flatten>;
        using Eager = flatten_if_t<container<ToFlatten...>, must_flatten>;

        static_assert(equal<vector<Elements...>, Lazy>::value, "");
        static_assert(equal<vector<Elements...>, Eager>::value, "");
    };
};

struct test_all :
    // 0 elements
    test_flatten<>::equals<>,


    // 1 element
    test_flatten<x0>::equals<x0>,

    test_flatten<sequence<>>::equals<sequence<>>,
    test_flatten<sequence<x0>>::equals<sequence<x0>>,
    test_flatten<sequence<x0, x1>>::equals<sequence<x0, x1>>,

    test_flatten<flat_sequence<>>::equals<>,
    test_flatten<flat_sequence<x0>>::equals<x0>,
    test_flatten<flat_sequence<x0, x1>>::equals<x0, x1>,


    // 2 elements
    test_flatten<x0, x1>::equals<x0, x1>,
    test_flatten<x0, sequence<y0>>::equals<x0, sequence<y0>>,
    test_flatten<x0, flat_sequence<y0>>::equals<x0, y0>,

    test_flatten<flat_sequence<>, x0>::equals<x0>,
    test_flatten<flat_sequence<y0>, x0>::equals<y0, x0>,


    // 3 elements
    test_flatten<
        flat_sequence<x0, x1>,
        flat_sequence<y0, y1>,
        flat_sequence<z0, z1, z2>
    >::equals<x0, x1, y0, y1, z0, z1, z2>,

    test_flatten<
        flat_sequence<x0, x1>,
        y0, y1,
        flat_sequence<z0, z1, z2>
    >::equals<x0, x1, y0, y1, z0, z1, z2>,

    test_flatten<
        flat_sequence<x0, x1>,
        flat_sequence<>,
        flat_sequence<z0, z1, z2>
    >::equals<x0, x1, z0, z1, z2>
{ };


int main() { }
