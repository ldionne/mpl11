/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::std_equal`.
 */

#include <boost/mpl11/detail/std_equal.hpp>

#include <boost/mpl11/integer.hpp>
#include "../minimal_iterable.hpp"


using namespace boost::mpl11;
using detail::std_equal;

template <int ...xs>
struct compare {
    template <typename Dummy, int ...ys>
    struct with_ {
        static_assert(!std_equal<
            minimal_iterable<int_<xs>...>,
            minimal_iterable<int_<ys>...>
        >::value, "");
    };

    template <int ...ys>
    using with = with_<void, ys...>;


    template <typename Dummy>
    struct with_<Dummy, xs...> {
        static_assert(std_equal<
            minimal_iterable<int_<xs>...>,
            minimal_iterable<int_<xs>...>
        >::value, "");
    };
};

struct tests :
      compare<>::with<>
    , compare<>::with<0>
    , compare<>::with<0, 1>
    , compare<>::with<0, 1, 2>

    , compare<0>::with<>
    , compare<0>::with<0>
    , compare<0>::with<0, 1>
    , compare<0>::with<0, 1, 2>

    , compare<0, 1>::with<>
    , compare<0, 1>::with<0>
    , compare<0, 1>::with<0, 1>
    , compare<0, 1>::with<0, 1, 2>

    , compare<0, 1, 2>::with<>
    , compare<0, 1, 2>::with<0>
    , compare<0, 1, 2>::with<0, 1>
    , compare<0, 1, 2>::with<0, 1, 2>
{ };


int main() { }
