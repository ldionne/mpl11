/*!
 * @file
 * Contains unit tests for `boost::mpl11::transform`.
 */

#include <boost/mpl11/transform.hpp>

#include <boost/mpl11/detail/sequence_test.hpp>


using namespace boost::mpl11;

struct f { template <typename> struct apply { struct type; }; };
template <int> struct x;

template <int ...Seq>
struct test_transform
    : detail::sequence_test<
        transform_t<f, detail::minimal_sequence<x<Seq>...>>,
        typename f::template apply<x<Seq>>::type...
    >
{ };

struct tests :
    test_transform<>,
    test_transform<0>,
    test_transform<0, 1>,
    test_transform<0, 1, 2>,
    test_transform<0, 1, 2, 3>,
    test_transform<0, 1, 2, 3, 4>,
    test_transform<0, 1, 2, 3, 4, 5>
{ };


int main() { }
