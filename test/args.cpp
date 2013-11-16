/*!
 * @file
 * Contains unit tests for `boost::mpl11::args`.
 */

#include <boost/mpl11/args.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/is_placeholder.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct a0; struct a1; struct a2;
template <typename ...> struct f { struct type; };

// test is_placeholder specialization
static_assert(is_placeholder<args<>>::value, "");

static_assert(is_placeholder<args<0>>::value, "");
static_assert(is_placeholder<args<1>>::value, "");
static_assert(is_placeholder<args<2>>::value, "");

static_assert(is_placeholder<args<0, 1>>::value, "");
static_assert(is_placeholder<args<0, 2>>::value, "");
static_assert(is_placeholder<args<0, 3>>::value, "");

static_assert(is_placeholder<args<1, 1>>::value, "");
static_assert(is_placeholder<args<1, 2>>::value, "");
static_assert(is_placeholder<args<1, 3>>::value, "");

static_assert(is_placeholder<args<2, 2>>::value, "");
static_assert(is_placeholder<args<2, 3>>::value, "");
static_assert(is_placeholder<args<2, 4>>::value, "");


// test args<> as a metafunction class.
static_assert(is_same<
    apply<args<>>::type, vector<>
>::value, "");
static_assert(is_same<
    apply<args<>, a0>::type, vector<a0>
>::value, "");
static_assert(is_same<
    apply<args<>, a0, a1>::type, vector<a0, a1>
>::value, "");
static_assert(is_same<
    apply<args<>, a0, a1, a2>::type, vector<a0, a1, a2>
>::value, "");

static_assert(is_same<
    apply<args<0, 0>>::type, vector<>
>::value, "");
static_assert(is_same<
    apply<args<0, 0>, a0>::type, vector<>
>::value, "");
static_assert(is_same<
    apply<args<1, 3>, a0, a1, a2>::type, vector<a1, a2>
>::value, "");


// test args<> as a lambda placeholder
static_assert(is_same<
    apply<lambda<args<>>, a0, a1, a2>::type,
    vector<a0, a1, a2>
>::value, "");
static_assert(is_same<
    apply<lambda<args<0, 2>>, a0, a1, a2>::type,
    vector<a0, a1>
>::value, "");
static_assert(is_same<
    apply<lambda<f<args<>>>, a0, a1, a2>::type,
    f<a0, a1, a2>::type
>::value, "");
static_assert(is_same<
    apply<lambda<f<args<1, 3>>>, a0, a1, a2>::type,
    f<a1, a2>::type
>::value, "");


int main() { }
