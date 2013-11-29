/*!
 * @file
 * Contains unit tests for `boost::mpl11::curry`.
 */

#include <boost/mpl11/curry.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct a0; struct a1; struct a2; struct a3;
struct f { template <typename ...> struct apply { struct type; }; };

static_assert(is_same<
    apply_t<curry<f>>,
    apply_t<f>
>::value, "");
static_assert(is_same<
    apply_t<curry<f>, a0>,
    apply_t<f, a0>
>::value, "");
static_assert(is_same<
    apply_t<curry<f>, a0, a1>,
    apply_t<f, a0, a1>
>::value, "");

static_assert(is_same<
    apply_t<curry<f, a0>>,
    apply_t<f, a0>
>::value, "");
static_assert(is_same<
    apply_t<curry<f, a0>, a1>,
    apply_t<f, a0, a1>
>::value, "");
static_assert(is_same<
    apply_t<curry<f, a0>, a1, a2>,
    apply_t<f, a0, a1, a2>
>::value, "");

static_assert(is_same<
    apply_t<curry<f, a0, a1>>,
    apply_t<f, a0, a1>
>::value, "");
static_assert(is_same<
    apply_t<curry<f, a0, a1>, a2>,
    apply_t<f, a0, a1, a2>
>::value, "");
static_assert(is_same<
    apply_t<curry<f, a0, a1>, a2, a3>,
    apply_t<f, a0, a1, a2, a3>
>::value, "");


int main() { }
