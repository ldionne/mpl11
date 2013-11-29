/*!
 * @file
 * Contains unit tests for `boost::mpl11::filter`.
 */

#include <boost/mpl11/filter.hpp>

#include <boost/mpl11/container.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
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

template <bool> struct x;
template <bool> struct y;
template <bool> struct z;

struct f {
    template <typename> struct apply;

    template <template <bool> class X, bool Keep>
    struct apply<X<Keep>>
        : bool_<Keep>
    { };
};

template <typename ...T>
struct test_filter {
    template <template <bool> class ...Kept>
    struct keeps {
        // We use vector to dispatch the equal<> because filter<> is not
        // a DirectionalSequence.
        static_assert(equal<
            vector<Kept<true>...>,
            filter<sequence<T...>, f>
        >::value, "");

        static_assert(equal<
            vector<Kept<true>...>,
            filter_t<container<T...>, f>
        >::value, "");
    };
};

struct test_all :
    test_filter<>::keeps<>,

    test_filter<x<true>>::keeps<x>,
    test_filter<x<false>>::keeps<>,

    test_filter<x<true>, y<true>>::keeps<x, y>,
    test_filter<x<true>, y<false>>::keeps<x>,
    test_filter<x<false>, y<true>>::keeps<y>,
    test_filter<x<false>, y<false>>::keeps<>,

    test_filter<x<true>, y<true>, z<true>>::keeps<x, y, z>,
    test_filter<x<true>, y<true>, z<false>>::keeps<x, y>,
    test_filter<x<true>, y<false>, z<true>>::keeps<x, z>,
    test_filter<x<true>, y<false>, z<false>>::keeps<x>,
    test_filter<x<false>, y<true>, z<true>>::keeps<y, z>,
    test_filter<x<false>, y<true>, z<false>>::keeps<y>,
    test_filter<x<false>, y<false>, z<true>>::keeps<z>,
    test_filter<x<false>, y<false>, z<false>>::keeps<>
{ };


int main() { }
