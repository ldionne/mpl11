/*!
 * @file
 * Contains unit tests for `boost::mpl11::partial`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct a0; struct a1; struct a2; struct a3;

template <typename f, typename ...x>
using apply_t = typename f::type::template apply<x...>::type;

template <typename F>
struct test_partial {
    static_assert(std_is_same<
        apply_t<partial<F>>,
        apply_t<F>
    >::value, "");
    static_assert(std_is_same<
        apply_t<partial<F>, a0>,
        apply_t<F, a0>
    >::value, "");
    static_assert(std_is_same<
        apply_t<partial<F>, a0, a1>,
        apply_t<F, a0, a1>
    >::value, "");

    static_assert(std_is_same<
        apply_t<partial<F, a0>>,
        apply_t<F, a0>
    >::value, "");
    static_assert(std_is_same<
        apply_t<partial<F, a0>, a1>,
        apply_t<F, a0, a1>
    >::value, "");
    static_assert(std_is_same<
        apply_t<partial<F, a0>, a1, a2>,
        apply_t<F, a0, a1, a2>
    >::value, "");

    static_assert(std_is_same<
        apply_t<partial<F, a0, a1>>,
        apply_t<F, a0, a1>
    >::value, "");
    static_assert(std_is_same<
        apply_t<partial<F, a0, a1>, a2>,
        apply_t<F, a0, a1, a2>
    >::value, "");
    static_assert(std_is_same<
        apply_t<partial<F, a0, a1>, a2, a3>,
        apply_t<F, a0, a1, a2, a3>
    >::value, "");
};

struct f {
    struct mf { template <typename ...> struct apply { struct type; }; };
    using type = mf;
};
template <typename ...> struct g { struct type; };
template <typename ...> struct h;

struct tests :
    test_partial<f>,
    test_partial<quote<g>>, // test quote specialization
    test_partial<into<h>>   // test into specialization
{ };


int main() { }
