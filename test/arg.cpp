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
static_assert(is_same<apply<_1, a1>::type, a1>::value, "");
static_assert(is_same<apply<_1, a1, a2>::type, a1>::value, "");
static_assert(is_same<apply<_1, a1, a2, a3>::type, a1>::value, "");

static_assert(is_same<apply<_2, a1, a2>::type, a2>::value, "");
static_assert(is_same<apply<_2, a1, a2, a3>::type, a2>::value, "");
static_assert(is_same<apply<_2, a1, a2, a3, a4>::type, a2>::value, "");

static_assert(is_same<apply<_3, a1, a2, a3>::type, a3>::value, "");
static_assert(is_same<apply<_3, a1, a2, a3, a4>::type, a3>::value, "");
static_assert(is_same<apply<_3, a1, a2, a3, a4, a5>::type, a3>::value, "");

static_assert(is_same<apply<_4, a1, a2, a3, a4>::type, a4>::value, "");
static_assert(is_same<apply<_4, a1, a2, a3, a4, a5>::type, a4>::value, "");
static_assert(is_same<apply<_4, a1, a2, a3, a4, a5, a6>::type, a4>::value, "");


// test arg<> as a lambda placeholder
static_assert(is_same<apply<lambda<_1>, a1, a2>::type, a1>::value, "");
static_assert(is_same<apply<lambda<_1>, a1, a2, a3>::type, a1>::value, "");
static_assert(is_same<apply<lambda<_1>, a1, a2, a3, a4>::type, a1>::value, "");
static_assert(is_same<apply<lambda<f<_1>>, a1, a2>::type, f<a1>::type>::value, "");

static_assert(is_same<apply<lambda<_2>, a1, a2, a3>::type, a2>::value, "");
static_assert(is_same<apply<lambda<_2>, a1, a2, a3, a4>::type, a2>::value, "");
static_assert(is_same<apply<lambda<_2>, a1, a2, a3, a4, a5>::type, a2>::value, "");
static_assert(is_same<apply<lambda<f<_2>>, a1, a2, a3>::type, f<a2>::type>::value, "");

static_assert(is_same<
    apply<lambda<f<_3, f<_4>, f<_1>>>, a1, a2, a3, a4>::type,
    f<a3, f<a4>::type, f<a1>::type>::type
>::value, "");


int main() { }
