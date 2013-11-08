/*!
 * @file
 * Contains unit tests for `boost::mpl11::contains`.
 */

#include <boost/mpl11/contains.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;

//! @todo Use an archetype class instead of this.
template <int>
struct t {
    struct mpl_class : Comparable {
        template <typename T, typename U>
        struct equal_impl
            : bool_<detail::is_same<T, U>::value>
        { };
    };
};

template <typename Container>
struct test_one {
    template <typename ..T>
    using container = typename apply<new_<Container>, T...>::type;

    static_assert(!contains<container<>, t<0>>::value, "");

    static_assert( contains<container<t<0>>, t<0>>::value, "");
    static_assert(!contains<container<t<0>>, t<1>>::value, "");

    static_assert( contains<container<t<0>, t<1>>, t<0>>::value, "");
    static_assert( contains<container<t<0>, t<1>>, t<1>>::value, "");
    static_assert(!contains<container<t<0>, t<1>>, t<2>>::value, "");

    static_assert( contains<container<t<0>, t<1>, t<2>>, t<0>>::value, "");
    static_assert( contains<container<t<0>, t<1>, t<2>>, t<1>>::value, "");
    static_assert( contains<container<t<0>, t<1>, t<2>>, t<2>>::value, "");
    static_assert(!contains<container<t<0>, t<1>, t<2>>, t<3>>::value, "");

    static_assert( contains<container<t<0>, t<0>, t<2>>, t<0>>::value, "");
    static_assert( contains<container<t<1>, t<1>, t<2>>, t<1>>::value, "");
    static_assert( contains<container<t<0>, t<2>, t<2>>, t<2>>::value, "");
};

struct test_all
    : test_one<vector<>>
{ };


int main() { }
