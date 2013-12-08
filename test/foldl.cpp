/*!
 * @file
 * Contains unit tests for `boost::mpl11::foldl`.
 */

#include <boost/mpl11/foldl.hpp>

#include <boost/mpl11/detail/foldl/normal.hpp>
#include <boost/mpl11/detail/foldl/unpacked.hpp>
#include <boost/mpl11/detail/foldl/unrolled.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

template <int> struct x;

template <int ...i>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>, vector<x<i>...>
>;

template <template <typename ...> class Foldl>
struct test_foldl {
    template <typename ...Args>
    using Foldl_t = typename Foldl<Args...>::type;

    template <int ...i>
    struct test_it_impl {
        static_assert(equal<
            Foldl_t<sequence<i...>, vector<>, quote<push_back>>,
            vector<x<i>...>
        >::value, "");
    };

    struct test_it :
        test_it_impl<>,
        test_it_impl<0>,
        test_it_impl<0, 1>,
        test_it_impl<0, 1, 2>,
        test_it_impl<0, 1, 2, 3>,
        test_it_impl<0, 1, 2, 3, 4>,
        test_it_impl<0, 1, 2, 3, 4, 5>,
        test_it_impl<0, 1, 2, 3, 4, 5, 6>,
        test_it_impl<0, 1, 2, 3, 4, 5, 6, 7>,
        test_it_impl<0, 1, 2, 3, 4, 5, 6, 7, 8>,
        test_it_impl<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>
    { };

    static_assert(sizeof(test_it), "");
};

struct test_all :
    test_foldl<detail::normal_foldl>,
    test_foldl<detail::unpacked_foldl>,
    test_foldl<detail::unrolled_foldl>,
    test_foldl<foldl>
{ };


int main() { }
