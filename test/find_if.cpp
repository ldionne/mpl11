/*!
 * @file
 * Contains unit tests for `boost::mpl11::find_if`.
 */

#include <boost/mpl11/find_if.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename Sequence, int I>
using iter_at = typename advance_c<typename begin<Sequence>::type, I>::type;

struct x; struct y; struct z;

template <typename Container>
struct test_one {
    template <typename ...T>
    using container = typename apply<new_<Container>, T...>::type;

    static_assert(equal<
        typename find_if<container<>, lambda<true_>>::type,
        typename end<container<>>::type
    >::value, "");
    static_assert(equal<
        typename find_if<container<x>, lambda<true_>>::type,
        iter_at<container<x>, 0>
    >::value, "");
    static_assert(equal<
        typename find_if<container<x, y>, lambda<true_>>::type,
        iter_at<container<x, y>, 0>
    >::value, "");
    static_assert(equal<
        typename find_if<container<x, y, z>, lambda<true_>>::type,
        iter_at<container<x, y, z>, 0>
    >::value, "");

    static_assert(equal<
        typename find_if<container<>, lambda<false_>>::type,
        typename end<container<>>::type
    >::value, "");
    static_assert(equal<
        typename find_if<container<x>, lambda<false_>>::type,
        typename end<container<x>>::type
    >::value, "");
    static_assert(equal<
        typename find_if<container<x, y>, lambda<false_>>::type,
        typename end<container<x, y>>::type
    >::value, "");
    static_assert(equal<
        typename find_if<container<x, y, z>, lambda<false_>>::type,
        typename end<container<x, y, z>>::type
    >::value, "");

    template <typename T>
    using same_as = lambda<is_same<T, _1>>;
    static_assert(equal<
        typename find_if<container<>, same_as<x>>::type,
        typename end<container<>>::type
    >::value, "");
    static_assert(equal<
        typename find_if<container<x>, same_as<x>>::type,
        iter_at<container<x>, 0>
    >::value, "");
    static_assert(equal<
        typename find_if<container<y>, same_as<x>>::type,
        typename end<container<y>>::type
    >::value, "");

    static_assert(equal<
        typename find_if<container<x, y>, same_as<x>>::type,
        iter_at<container<x, y>, 0>
    >::value, "");
    static_assert(equal<
        typename find_if<container<x, y>, same_as<y>>::type,
        iter_at<container<x, y>, 1>
    >::value, "");
    static_assert(equal<
        typename find_if<container<x, y>, same_as<z>>::type,
        typename end<container<x, y>>::type
    >::value, "");

    static_assert(equal<
        typename find_if<container<x, y, z>, same_as<x>>::type,
        iter_at<container<x, y, z>, 0>
    >::value, "");
    static_assert(equal<
        typename find_if<container<x, y, z>, same_as<y>>::type,
        iter_at<container<x, y, z>, 1>
    >::value, "");
    static_assert(equal<
        typename find_if<container<x, y, z>, same_as<z>>::type,
        iter_at<container<x, y, z>, 2>
    >::value, "");
};

struct test_all
    : test_one<vector<>>
{ };


int main() { }
