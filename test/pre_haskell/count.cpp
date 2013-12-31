/*!
 * @file
 * Contains unit tests for `boost::mpl11::count`.
 */

#include <boost/mpl11/count.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;

//! @todo Use a minimal Comparable element for the tests.
template <int>
struct t {
    struct mpl_class : Comparable {
        template <typename T, typename U>
        struct equal_impl
            : detail::is_same<T, U>
        { };
    };
};

template <typename Container>
struct test_one {
    template <typename ...T>
    using sequence = typename apply<new_<Container>, vector<T...>>::type;

    static_assert(count<sequence<>, t<0>>::value == 0, "");

    static_assert(count<sequence<t<0>>, t<0>>::value == 1, "");
    static_assert(count<sequence<t<1>>, t<0>>::value == 0, "");

    static_assert(count<sequence<t<0>, t<0>>, t<0>>::value == 2, "");
    static_assert(count<sequence<t<0>, t<1>>, t<0>>::value == 1, "");
    static_assert(count<sequence<t<1>, t<0>>, t<0>>::value == 1, "");
    static_assert(count<sequence<t<1>, t<1>>, t<0>>::value == 0, "");

    static_assert(count<sequence<t<0>, t<0>, t<0>>, t<0>>::value == 3, "");
    static_assert(count<sequence<t<0>, t<0>, t<1>>, t<0>>::value == 2, "");
    static_assert(count<sequence<t<0>, t<1>, t<0>>, t<0>>::value == 2, "");
    static_assert(count<sequence<t<0>, t<1>, t<1>>, t<0>>::value == 1, "");
    static_assert(count<sequence<t<1>, t<0>, t<0>>, t<0>>::value == 2, "");
    static_assert(count<sequence<t<1>, t<0>, t<1>>, t<0>>::value == 1, "");
    static_assert(count<sequence<t<1>, t<1>, t<0>>, t<0>>::value == 1, "");
    static_assert(count<sequence<t<1>, t<1>, t<1>>, t<0>>::value == 0, "");
};

struct test_all
    : test_one<vector<>>
{ };


int main() { }
