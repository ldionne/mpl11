/*!
 * @file
 * Contains unit tests for `boost::mpl11::find_if`.
 */

#include <boost/mpl11/find_if.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename Sequence, int I>
using iter_at = advance_c_t<begin_t<Sequence>, I>;

struct x; struct y; struct z;

template <typename Container>
struct test_one {
    template <typename ...T>
    using container = apply_t<new_<Container>, vector<T...>>;

    static_assert(equal<
        find_if_t<container<>, always<true_>>,
        end_t<container<>>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x>, always<true_>>,
        iter_at<container<x>, 0>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x, y>, always<true_>>,
        iter_at<container<x, y>, 0>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x, y, z>, always<true_>>,
        iter_at<container<x, y, z>, 0>
    >::value, "");

    static_assert(equal<
        find_if_t<container<>, always<false_>>,
        end_t<container<>>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x>, always<false_>>,
        end_t<container<x>>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x, y>, always<false_>>,
        end_t<container<x, y>>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x, y, z>, always<false_>>,
        end_t<container<x, y, z>>
    >::value, "");

    template <typename T>
    using same_as = partial<quote<is_same>, T>;
    static_assert(equal<
        find_if_t<container<>, same_as<x>>,
        end_t<container<>>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x>, same_as<x>>,
        iter_at<container<x>, 0>
    >::value, "");
    static_assert(equal<
        find_if_t<container<y>, same_as<x>>,
        end_t<container<y>>
    >::value, "");

    static_assert(equal<
        find_if_t<container<x, y>, same_as<x>>,
        iter_at<container<x, y>, 0>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x, y>, same_as<y>>,
        iter_at<container<x, y>, 1>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x, y>, same_as<z>>,
        end_t<container<x, y>>
    >::value, "");

    static_assert(equal<
        find_if_t<container<x, y, z>, same_as<x>>,
        iter_at<container<x, y, z>, 0>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x, y, z>, same_as<y>>,
        iter_at<container<x, y, z>, 1>
    >::value, "");
    static_assert(equal<
        find_if_t<container<x, y, z>, same_as<z>>,
        iter_at<container<x, y, z>, 2>
    >::value, "");
};

struct test_all
    : test_one<vector<>>
{ };


int main() { }
