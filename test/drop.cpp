/*!
 * @file
 * Contains unit tests for `boost::mpl11::drop`.
 */

#include <boost/mpl11/drop.hpp>

#include <boost/mpl11/detail/sequence_test.hpp>


using namespace boost::mpl11;

template <int> struct x;

template <unsigned long N>
struct dropping {
    template <int ...All>
    struct from {
        template <int ...Remaining>
        struct is
            : detail::sequence_test<
                drop_c_t<N, detail::minimal_sequence<x<All>...>>,
                x<Remaining>...
            >
        { };
    };
};

struct tests :
    dropping<0>::from<>::is<>,
    dropping<1>::from<>::is<>,
    dropping<2>::from<>::is<>,
    dropping<3>::from<>::is<>,

    dropping<0>::from<0>::is<0>,
    dropping<1>::from<0>::is<>,
    dropping<2>::from<0>::is<>,
    dropping<3>::from<0>::is<>,

    dropping<0>::from<0, 1>::is<0, 1>,
    dropping<1>::from<0, 1>::is<1>,
    dropping<2>::from<0, 1>::is<>,
    dropping<3>::from<0, 1>::is<>,

    dropping<0>::from<0, 1, 2>::is<0, 1, 2>,
    dropping<1>::from<0, 1, 2>::is<1, 2>,
    dropping<2>::from<0, 1, 2>::is<2>,
    dropping<3>::from<0, 1, 2>::is<>,
    dropping<4>::from<0, 1, 2>::is<>,
    dropping<5>::from<0, 1, 2>::is<>,

    dropping<0>::from<0, 1, 2, 3>::is<0, 1, 2, 3>,
    dropping<1>::from<0, 1, 2, 3>::is<1, 2, 3>,
    dropping<2>::from<0, 1, 2, 3>::is<2, 3>,
    dropping<3>::from<0, 1, 2, 3>::is<3>,
    dropping<4>::from<0, 1, 2, 3>::is<>,
    dropping<5>::from<0, 1, 2, 3>::is<>
{ };


int main() { }
