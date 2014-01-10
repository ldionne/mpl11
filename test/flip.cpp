/*!
 * @file
 * Contains unit tests for `boost::mpl11::flip`.
 */

#include <boost/mpl11/flip.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename ...> struct f_ { struct type; }; using f = quote<f_>;
struct a0; struct a1; struct a2; struct a3; struct a4; struct a5;

static_assert(is_same<
    apply_t<flip<f>, a0, a1>,
    apply_t<f, a1, a0>
>::value, "");

static_assert(is_same<
    apply_t<flip<f>, a0, a1, a2>,
    apply_t<f, a1, a0, a2>
>::value, "");

static_assert(is_same<
    apply_t<flip<f>, a0, a1, a2, a3>,
    apply_t<f, a1, a0, a2, a3>
>::value, "");

static_assert(is_same<
    apply_t<flip<f>, a0, a1, a2, a3, a4>,
    apply_t<f, a1, a0, a2, a3, a4>
>::value, "");

static_assert(is_same<
    apply_t<flip<f>, a0, a1, a2, a3, a4, a5>,
    apply_t<f, a1, a0, a2, a3, a4, a5>
>::value, "");


int main() { }
