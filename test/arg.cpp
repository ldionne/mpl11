/*!
 * @file
 * Contains unit tests for `boost::mpl11::arg`.
 */

#include <boost/mpl11/arg.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/lambda.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename ...> struct f { struct type; };
struct a1; struct a2; struct a3; struct a4; struct a5; struct a6;

// test arg<> as a metafunction class
static_assert(is_same<apply_t<_1, a1>, a1>::value, "");
static_assert(is_same<apply_t<_1, a1, a2>, a1>::value, "");
static_assert(is_same<apply_t<_1, a1, a2, a3>, a1>::value, "");

static_assert(is_same<apply_t<_2, a1, a2>, a2>::value, "");
static_assert(is_same<apply_t<_2, a1, a2, a3>, a2>::value, "");
static_assert(is_same<apply_t<_2, a1, a2, a3, a4>, a2>::value, "");

static_assert(is_same<apply_t<_3, a1, a2, a3>, a3>::value, "");
static_assert(is_same<apply_t<_3, a1, a2, a3, a4>, a3>::value, "");
static_assert(is_same<apply_t<_3, a1, a2, a3, a4, a5>, a3>::value, "");

static_assert(is_same<apply_t<_4, a1, a2, a3, a4>, a4>::value, "");
static_assert(is_same<apply_t<_4, a1, a2, a3, a4, a5>, a4>::value, "");
static_assert(is_same<apply_t<_4, a1, a2, a3, a4, a5, a6>, a4>::value, "");


// test _arg<> as a placeholder
static_assert(is_same<apply_t<lambda<_1>, a1, a2>, a1>::value, "");
static_assert(is_same<apply_t<lambda<_1>, a1, a2, a3>, a1>::value, "");
static_assert(is_same<apply_t<lambda<_1>, a1, a2, a3, a4>, a1>::value, "");
static_assert(is_same<apply_t<lambda<f<_1>>, a1, a2>, f<a1>::type>::value, "");

static_assert(is_same<apply_t<lambda<_2>, a1, a2, a3>, a2>::value, "");
static_assert(is_same<apply_t<lambda<_2>, a1, a2, a3, a4>, a2>::value, "");
static_assert(is_same<apply_t<lambda<_2>, a1, a2, a3, a4, a5>, a2>::value, "");
static_assert(is_same<apply_t<lambda<f<_2>>, a1, a2, a3>, f<a2>::type>::value, "");

static_assert(is_same<
    apply_t<lambda<f<_3, f<_4>, f<_1>>>, a1, a2, a3, a4>,
    f<a3, f<a4>::type, f<a1>::type>::type
>::value, "");


int main() { }
