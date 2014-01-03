/*!
 * @file
 * Contains unit tests for `boost::mpl11::drop`.
 */

#include <boost/mpl11/drop.hpp>

#include <boost/mpl11/list.hpp>
#include "sequence_test.hpp"


using namespace mpl11_test;

template <int> struct x;

template <unsigned long N>
struct dropping {
    template <int ...Seq>
    struct from {
        template <int ...Dropped>
        struct is :
            forward_sequence_test<      drop_c_t<N, list<x<Seq>...>>, x<Dropped>...>,
            finite_sequence_test<       drop_c_t<N, list<x<Seq>...>>, x<Dropped>...>,
            bidirectional_sequence_test<drop_c_t<N, list<x<Seq>...>>, x<Dropped>...>,
            random_access_sequence_test<drop_c_t<N, list<x<Seq>...>>, x<Dropped>...>
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
