/*!
 * @file
 * Contains unit tests for `boost::mpl11::compose`.
 */

#include <boost/mpl11/compose.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct f { template <typename> struct apply { struct type; }; };
struct g { template <typename> struct apply { struct type; }; };
struct h { template <typename> struct apply { struct type; }; };
struct i { template <typename ...> struct apply { struct type; }; };

template <typename ...Args>
struct test_one {
    static_assert(is_same<
        apply_t<compose<i>, Args...>,
        apply_t<i, Args...>
    >::value, "");

    static_assert(is_same<
        apply_t<compose<h, i>, Args...>,
        apply_t<h, apply_t<i, Args...>>
    >::value, "");

    static_assert(is_same<
        apply_t<compose<g, h, i>, Args...>,
        apply_t<g, apply_t<h, apply_t<i, Args...>>>
    >::value, "");

    static_assert(is_same<
        apply_t<compose<f, g, h, i>, Args...>,
        apply_t<f, apply_t<g, apply_t<h, apply_t<i, Args...>>>>
    >::value, "");
};

struct w; struct x; struct y; struct z;
struct test_all :
    test_one<>,
    test_one<w>,
    test_one<w, x>,
    test_one<w, x, y>,
    test_one<w, x, y, z>
{ };


int main() { }
