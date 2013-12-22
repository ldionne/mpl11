/*!
 * @file
 * Contains unit tests for `boost::mpl11::zip`.
 */

#include <boost/mpl11/zip.hpp>

#include <boost/mpl11/container.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/length.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

template <typename ...T>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>, vector<T...>
>;

template <typename ...T>
using container = test::wrapper<
    test::minimal_requirements<Container>, vector<T...>
>;

struct w0; struct w1; struct w2; struct w3; struct w4;
struct x0; struct x1; struct x2; struct x3; struct x4;
struct y0; struct y1; struct y2; struct y3; struct y4;
struct z0; struct z1; struct z2; struct z3; struct z4;

template <typename ...ToZip>
struct test_zip;

template <typename ...First, typename ...Rest>
struct test_zip<sequence<First...>, Rest...> {
    template <typename ...Elements>
    struct equals {
        using Lazy = zip<sequence<First...>, Rest...>;
        using Eager = zip_t<container<First...>, Rest...>;

        static_assert(equal<vector<Elements...>, Lazy>::value, "");
        static_assert(equal<vector<Elements...>, Eager>::value, "");

        static_assert(length<Lazy>::value == sizeof...(Elements), "");
        static_assert(length<Eager>::value == sizeof...(Elements), "");
    };
};

struct test_all :
    // zip 2 sequences
    test_zip<sequence<>, sequence<>>::equals<>,
    test_zip<sequence<>, sequence<x0>>::equals<>,
    test_zip<sequence<>, sequence<x0, x1>>::equals<>,

    test_zip<sequence<w0>, sequence<>>::equals<>,
    test_zip<sequence<w0>, sequence<x0>>::equals<vector<w0, x0>>,
    test_zip<sequence<w0>, sequence<x0, x1>>::equals<vector<w0, x0>>,

    test_zip<sequence<w0, w1>, sequence<>>::equals<>,
    test_zip<sequence<w0, w1>, sequence<x0>>::equals<vector<w0, x0>>,
    test_zip<sequence<w0, w1>, sequence<x0, x1>>::equals<vector<w0, x0>, vector<w1, x1>>,

    // zip 3 sequences
    test_zip<sequence<>, sequence<>, sequence<y0>>::equals<>,
    test_zip<sequence<>, sequence<x0>, sequence<>>::equals<>,
    test_zip<sequence<>, sequence<x0>, sequence<y0>>::equals<>,
    test_zip<sequence<w0>, sequence<>, sequence<>>::equals<>,
    test_zip<sequence<w0>, sequence<>, sequence<y0>>::equals<>,
    test_zip<sequence<w0>, sequence<x0>, sequence<>>::equals<>,
    test_zip<sequence<w0>, sequence<x0>, sequence<y0>>::equals<vector<w0, x0, y0>>,

    // zip 4 sequences with (sometimes) different sizes
    test_zip<
        sequence<w0, w1, w2, w3>,
        sequence<x0, x1, x2, x3, x4>,
        sequence<y0, y1, y2>,
        sequence<z0, z1, z2, z3, z4>
    >::equals<
        vector<w0, x0, y0, z0>,
        vector<w1, x1, y1, z1>,
        vector<w2, x2, y2, z2>
    >
{ };


int main() { }
