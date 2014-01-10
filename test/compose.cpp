/*!
 * @file
 * Contains unit tests for `boost::mpl11::compose`.
 */

#include <boost/mpl11/compose.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename>     struct f_called;
template <typename>     struct g_called;
template <typename>     struct h_called;
template <typename ...> struct i_called;

// We make these metafunction classes strict because otherwise there is
// nothing to test; we need to actually apply the composition to know
// whether there's a bug in it!
struct f {
    using type = f;
    template <typename X>
    struct apply {
        using type = f_called<typename X::type>;
    };
};

struct g {
    using type = g;
    template <typename X>
    struct apply {
        using type = g_called<typename X::type>;
    };
};

struct h {
    using type = h;
    template <typename X>
    struct apply {
        using type = h_called<typename X::type>;
    };
};

struct i {
    using type = i;
    template <typename ...X>
    struct apply {
        using type = i_called<typename X::type...>;
    };
};

template <typename ...Args>
struct test_one {
    static_assert(is_same<
        apply_t<compose<i>, Args...>,
        i_called<typename Args::type...>
    >::value, "");

    static_assert(is_same<
        apply_t<compose<h, i>, Args...>,
        h_called<i_called<typename Args::type...>>
    >::value, "");

    static_assert(is_same<
        apply_t<compose<g, h, i>, Args...>,
        g_called<h_called<i_called<typename Args::type...>>>
    >::value, "");

    static_assert(is_same<
        apply_t<compose<f, g, h, i>, Args...>,
        f_called<g_called<h_called<i_called<typename Args::type...>>>>
    >::value, "");
};

struct w { struct type; };
struct x { struct type; };
struct y { struct type; };
struct z { struct type; };
struct test_all :
    test_one<>,
    test_one<w>,
    test_one<w, x>,
    test_one<w, x, y>,
    test_one<w, x, y, z>
{ };


int main() { }
