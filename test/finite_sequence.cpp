/*!
 * @file
 * Contains unit tests for `boost::mpl11::FiniteSequence`.
 */

#include <boost/mpl11/finite_sequence.hpp>

#include <boost/mpl11/length.hpp>
#include <boost/mpl11/unpack.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::is_same;

struct f { template <typename ...> struct apply { struct type; }; };
template <int> struct x;

template <int ...i>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>, vector<x<i>...>
>;

template <int ...i>
struct test_one {
    static_assert(is_same<
        typename FiniteSequence::template unpack_impl<sequence<i...>, f>::type,
        typename f::template apply<x<i>...>::type
    >::value, "");

    static_assert(
        FiniteSequence::template length_impl<sequence<i...>>::value ==
        sizeof...(i)
    , "");
};

struct test_all :
    test_one<>,
    test_one<0>,
    test_one<0, 1>,
    test_one<0, 1, 2>,
    test_one<0, 1, 2, 3>,
    test_one<0, 1, 2, 3, 4>
{ };


int main() { }
