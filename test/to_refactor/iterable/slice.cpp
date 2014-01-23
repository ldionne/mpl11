/*!
 * @file
 * Contains unit tests for `boost::mpl11::slice`.
 */

#include <boost/mpl11/iterable/slice.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>


using namespace boost::mpl11;

template <int> struct x { struct type; };

template <int ...i>
using seq = detail::minimal_iterable<x<i>...>;

template <int ...All>
struct slicing {
    template <unsigned long Start, unsigned long Stop>
    struct at {
        template <int ...Sliced>
        struct is
            : detail::iterable_test<
                slice_c<seq<All...>, Start, Stop>,
                x<Sliced>...
            >
        { };
    };
};

struct tests :
    slicing<>::at<0, 0>::is<>,

    slicing<0>::at<0, 0>::is<>,
    slicing<0>::at<0, 1>::is<0>,
    slicing<0>::at<1, 1>::is<>,

    slicing<0, 1>::at<0, 0>::is<>,
    slicing<0, 1>::at<0, 1>::is<0>,
    slicing<0, 1>::at<0, 2>::is<0, 1>,
    slicing<0, 1>::at<1, 1>::is<>,
    slicing<0, 1>::at<1, 2>::is<1>,
    slicing<0, 1>::at<2, 2>::is<>,

    slicing<0, 1, 2>::at<0, 0>::is<>,
    slicing<0, 1, 2>::at<0, 1>::is<0>,
    slicing<0, 1, 2>::at<0, 2>::is<0, 1>,
    slicing<0, 1, 2>::at<0, 3>::is<0, 1, 2>,
    slicing<0, 1, 2>::at<1, 1>::is<>,
    slicing<0, 1, 2>::at<1, 2>::is<1>,
    slicing<0, 1, 2>::at<1, 3>::is<1, 2>,
    slicing<0, 1, 2>::at<2, 2>::is<>,
    slicing<0, 1, 2>::at<2, 3>::is<2>,
    slicing<0, 1, 2>::at<3, 3>::is<>
{ };


int main() { }
