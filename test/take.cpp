/*!
 * @file
 * Contains unit tests for `boost::mpl11::take`.
 */

#include <boost/mpl11/take.hpp>

#include <boost/mpl11/detail/sequence_test.hpp>
#include <boost/mpl11/list.hpp>


using namespace boost::mpl11;

template <int> struct x;

template <unsigned long N>
struct taking {
    template <int ...All>
    struct from {
        template <int ...Taken>
        struct is :
            detail::sequence_test<
                take_c_t<N, list<x<All>...>>,
                x<Taken>...
            >
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
