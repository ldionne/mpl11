/*!
 * @file
 * Contains unit tests for `boost::mpl11::take`.
 */

#include <boost/mpl11/take.hpp>

#include <boost/mpl11/vector.hpp>
#include "sequence_test.hpp"


using namespace mpl11_test;
using boost::mpl11::take_c;

template <int> struct x;

template <unsigned long N>
struct taking {
    template <int ...Seq>
    struct from {
        template <int ...Taken>
        struct is :
            forward_sequence_test<      take_c_t<N, vector<x<Seq>...>>, x<Taken>...>,
            finite_sequence_test<       take_c_t<N, vector<x<Seq>...>>, x<Taken>...>,
            bidirectional_sequence_test<take_c_t<N, vector<x<Seq>...>>, x<Taken>...>,
            random_access_sequence_test<take_c_t<N, vector<x<Seq>...>>, x<Taken>...>
        { };
    };
};

struct tests :
    taking<0>::from<>::is<>,
    taking<1>::from<>::is<>,
    taking<2>::from<>::is<>,
    taking<3>::from<>::is<>,

    taking<0>::from<0>::is<>,
    taking<1>::from<0>::is<0>,
    taking<2>::from<0>::is<0>,
    taking<3>::from<0>::is<0>,

    taking<0>::from<0, 1>::is<>,
    taking<1>::from<0, 1>::is<0>,
    taking<2>::from<0, 1>::is<0, 1>,
    taking<3>::from<0, 1>::is<0, 1>,

    taking<0>::from<0, 1, 2>::is<>,
    taking<1>::from<0, 1, 2>::is<0>,
    taking<2>::from<0, 1, 2>::is<0, 1>,
    taking<3>::from<0, 1, 2>::is<0, 1, 2>,
    taking<4>::from<0, 1, 2>::is<0, 1, 2>,
    taking<5>::from<0, 1, 2>::is<0, 1, 2>,

    taking<0>::from<0, 1, 2, 3>::is<>,
    taking<1>::from<0, 1, 2, 3>::is<0>,
    taking<2>::from<0, 1, 2, 3>::is<0, 1>,
    taking<3>::from<0, 1, 2, 3>::is<0, 1, 2>,
    taking<4>::from<0, 1, 2, 3>::is<0, 1, 2, 3>,
    taking<5>::from<0, 1, 2, 3>::is<0, 1, 2, 3>
{ };


int main() { }
