/*!
 * @file
 * Contains unit tests for `boost::mpl11::find`.
 */

#include <boost/mpl11/find.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;

//! @todo Use a minimal Comparable element for the tests.
template <int>
struct t {
    struct mpl_class : Comparable {
        template <typename T, typename U>
        struct equal_impl
            : bool_<detail::is_same<T, U>::value>
        { };
    };
};

template <typename Sequence, int I>
using iter_at = typename advance_c<typename begin<Sequence>::type, I>::type;

template <typename Container>
struct test_one {
    template <typename ...T>
    using sequence = typename apply<new_<Container>, T...>::type;

    static_assert(equal<
        typename find<sequence<>, t<0>>::type,
        typename end<sequence<>>::type
    >::value, "");

    static_assert(equal<
        typename find<sequence<t<0>>, t<0>>::type,
        iter_at<sequence<t<0>>, 0>
    >::value, "");
    static_assert(equal<
        typename find<sequence<t<0>>, t<1>>::type,
        typename end<sequence<t<0>>>::type
    >::value, "");

    static_assert(equal<
        typename find<sequence<t<0>, t<1>>, t<0>>::type,
        iter_at<sequence<t<0>, t<1>>, 0>
    >::value, "");
    static_assert(equal<
        typename find<sequence<t<0>, t<1>>, t<1>>::type,
        iter_at<sequence<t<0>, t<1>>, 1>
    >::value, "");
    static_assert(equal<
        typename find<sequence<t<0>, t<1>>, t<2>>::type,
        typename end<sequence<t<0>, t<1>>>::type
    >::value, "");

    static_assert(equal<
        typename find<sequence<t<0>, t<1>, t<2>>, t<0>>::type,
        iter_at<sequence<t<0>, t<1>, t<2>>, 0>
    >::value, "");
    static_assert(equal<
        typename find<sequence<t<0>, t<1>, t<2>>, t<1>>::type,
        iter_at<sequence<t<0>, t<1>, t<2>>, 1>
    >::value, "");
    static_assert(equal<
        typename find<sequence<t<0>, t<1>, t<2>>, t<2>>::type,
        iter_at<sequence<t<0>, t<1>, t<2>>, 2>
    >::value, "");
    static_assert(equal<
        typename find<sequence<t<0>, t<1>, t<2>>, t<3>>::type,
        typename end<sequence<t<0>, t<1>, t<2>>>::type
    >::value, "");

    static_assert(equal<
        typename find<sequence<t<0>, t<1>, t<1>>, t<1>>::type,
        iter_at<sequence<t<0>, t<1>, t<1>>, 1>
    >::value, "");
};

struct test_all
    : test_one<vector<>>
{ };


int main() { }
