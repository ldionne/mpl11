/*!
 * @file
 * Contains unit tests for `boost::mpl11::partial`.
 */

#include <boost/mpl11/partial.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct a0; struct a1; struct a2; struct a3;
struct f { template <typename ...> struct apply { struct type; }; };
template <typename ...> struct g { struct type; };
template <typename ...> struct h;

template <typename F>
struct test_partial {
    static_assert(is_same<
        apply_t<partial<F>>,
        apply_t<F>
    >::value, "");
    static_assert(is_same<
        apply_t<partial<F>, a0>,
        apply_t<F, a0>
    >::value, "");
    static_assert(is_same<
        apply_t<partial<F>, a0, a1>,
        apply_t<F, a0, a1>
    >::value, "");

    static_assert(is_same<
        apply_t<partial<F, a0>>,
        apply_t<F, a0>
    >::value, "");
    static_assert(is_same<
        apply_t<partial<F, a0>, a1>,
        apply_t<F, a0, a1>
    >::value, "");
    static_assert(is_same<
        apply_t<partial<F, a0>, a1, a2>,
        apply_t<F, a0, a1, a2>
    >::value, "");

    static_assert(is_same<
        apply_t<partial<F, a0, a1>>,
        apply_t<F, a0, a1>
    >::value, "");
    static_assert(is_same<
        apply_t<partial<F, a0, a1>, a2>,
        apply_t<F, a0, a1, a2>
    >::value, "");
    static_assert(is_same<
        apply_t<partial<F, a0, a1>, a2, a3>,
        apply_t<F, a0, a1, a2, a3>
    >::value, "");
};

struct test_all :
    test_partial<f>,
    test_partial<quote<g>>, // test quote specialization
    test_partial<into<h>>   // test into specialization
{ };


int main() { }
