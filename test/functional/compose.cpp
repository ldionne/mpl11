/*!
 * @file
 * Contains unit tests for `boost::mpl11::compose`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

template <template <typename ...> class f>
struct call {
    struct mf {
        template <typename ...x>
        struct apply { using type = f<typename x::type...>; };
    };
    using type = mf;
};

template <typename ...> struct f;
template <typename ...> struct g;
template <typename ...> struct h;
template <typename ...> struct i;

template <typename ...x>
struct test_compose;

template <typename x, typename ...xs>
struct test_compose<x, xs...> {
    template <template <typename ...> class ...fs>
    using compose = typename boost::mpl11::compose<call<fs>...>::type::
                    template apply<box<x>, box<xs>...>::type;

    static_assert(std_is_same<
        compose<i>,
        i<x, xs...>
    >::value, "");

    static_assert(std_is_same<
        compose<h, i>,
        h<i<x>, xs...>
    >::value, "");

    static_assert(std_is_same<
        compose<g, h, i>,
        g<h<i<x>>, xs...>
    >::value, "");

    static_assert(std_is_same<
        compose<f, g, h, i>,
        f<g<h<i<x>>>, xs...>
    >::value, "");
};

template <>
struct test_compose<> {
    template <template <typename ...> class ...fs>
    using compose = typename boost::mpl11::compose<call<fs>...>::type::
                    template apply<>::type;

    static_assert(std_is_same<
        compose<i>,
        i<>
    >::value, "");

    static_assert(std_is_same<
        compose<h, i>,
        h<i<>>
    >::value, "");

    static_assert(std_is_same<
        compose<g, h, i>,
        g<h<i<>>>
    >::value, "");

    static_assert(std_is_same<
        compose<f, g, h, i>,
        f<g<h<i<>>>>
    >::value, "");
};

struct w; struct x; struct y; struct z;
struct tests :
    test_compose<>,
    test_compose<w>,
    test_compose<w, x>,
    test_compose<w, x, y>,
    test_compose<w, x, y, z>
{ };


int main() { }
