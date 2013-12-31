/*!
 * @file
 * Contains unit tests for `boost::mpl11::args`.
 */

#include <boost/mpl11/args.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int> struct x;
template <int ...sequence>
struct slicing {
    template <unsigned int ...indices>
    struct at {
        template <int ...sliced>
        struct gives {
            static_assert(is_same<
                apply_t<args<indices...>, x<sequence>...>,
                vector<x<sliced>...>
            >::value, "");
        };
    };
};

struct test_as_metafunction_class :
    // test the default bounds when nothing is specified: args<>
    slicing<>::at<>::gives<>,
    slicing<0>::at<>::gives<0>,
    slicing<0, 1>::at<>::gives<0, 1>,
    slicing<0, 1, 2>::at<>::gives<0, 1, 2>,

    // test the default bound when only first is specified: args<First>
    slicing<0>::at<0>::gives<0>,
    slicing<0, 1>::at<0>::gives<0, 1>,
    slicing<0, 1, 2>::at<0>::gives<0, 1, 2>,

    slicing<0>::at<1>::gives<>,
    slicing<0, 1>::at<1>::gives<1>,
    slicing<0, 1, 2>::at<1>::gives<1, 2>,

    slicing<0, 1>::at<2>::gives<>,
    slicing<0, 1, 2>::at<2>::gives<2>,

    // test with an empty slice
    slicing<>::at<0, 0>::gives<>,
    slicing<0>::at<0, 0>::gives<>,
    slicing<0, 1>::at<0, 0>::gives<>,
    slicing<0, 1, 2>::at<0, 0>::gives<>,

    slicing<0>::at<1, 1>::gives<>,
    slicing<0, 1>::at<1, 1>::gives<>,
    slicing<0, 1, 2>::at<1, 1>::gives<>,

    // test other various slicing patterns
    slicing<0>::at<0, 1>::gives<0>,
    slicing<0, 1>::at<0, 1>::gives<0>,
    slicing<0, 1, 2>::at<0, 1>::gives<0>,

    slicing<0, 1>::at<0, 2>::gives<0, 1>,
    slicing<0, 1, 2>::at<0, 2>::gives<0, 1>,
    slicing<0, 1, 2, 3>::at<0, 2>::gives<0, 1>,

    slicing<0, 1>::at<1, 2>::gives<1>,
    slicing<0, 1, 2>::at<1, 2>::gives<1>,
    slicing<0, 1, 2, 3>::at<1, 2>::gives<1>,

    slicing<0, 1, 2>::at<0, 3>::gives<0, 1, 2>,
    slicing<0, 1, 2>::at<1, 3>::gives<1, 2>,
    slicing<0, 1, 2>::at<2, 3>::gives<2>,
    slicing<0, 1, 2>::at<3, 3>::gives<>,

    slicing<0, 1, 2, 3, 4, 5>::at<2, 6>::gives<2, 3, 4, 5>,
    slicing<0, 1, 2, 3, 4, 5, 6>::at<2, 6>::gives<2, 3, 4, 5>
{ };


int main() { }
