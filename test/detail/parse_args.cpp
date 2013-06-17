/*!
 * @file
 * This file contains unit tests for `boost::mpl11::detail::parse_args`.
 */

#include <boost/mpl11/detail/parse_args.hpp>
#include <boost/mpl11/container/map.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/functional/named_argument.hpp>
#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;

template <typename ...Args>
using parsed = typename detail::parse_args<Args...>::type;

struct k0; struct v0;
struct k1; struct v1;


// parse positional arguments only
static_assert(is_same<parsed<>::args, vector<>>::value, "");
static_assert(is_same<parsed<>::kwargs, map<>>::value, "");

static_assert(is_same<parsed<int>::args, vector<int>>::value, "");
static_assert(is_same<parsed<int>::kwargs, map<>>::value, "");

static_assert(is_same<parsed<int, float>::args, vector<int, float>>::value, "");
static_assert(is_same<parsed<int, float>::kwargs, map<>>::value, "");


// parse named arguments only
static_assert(is_same<
    parsed<named_argument<k0, v0>>::args, vector<>
>::value, "");
static_assert(is_same<
    at<parsed<named_argument<k0, v0>>::kwargs, k0>::type, v0
>::value, "");

using Parse2Named = parsed<named_argument<k0, v0>, named_argument<k1, v1>>;
static_assert(is_same<at<Parse2Named::kwargs, k0>::type, v0>::value, "");
static_assert(is_same<at<Parse2Named::kwargs, k1>::type, v1>::value, "");
static_assert(is_same<Parse2Named::args, vector<>>::value, "");


// parse mixed positional and named arguments
static_assert(is_same<
    parsed<int, named_argument<k0, v0>>::args,
    vector<int>
>::value, "");
static_assert(is_same<
    at<parsed<int, named_argument<k0, v0>>::kwargs, k0>::type, v0
>::value, "");

using Parse4Mixed = parsed<int, float, named_argument<k0, v0>, named_argument<k1, v1>>;
static_assert(is_same<Parse4Mixed::args, vector<int, float>>::value, "");
static_assert(is_same<at<Parse4Mixed::kwargs, k0>::type, v0>::value, "");
static_assert(is_same<at<Parse4Mixed::kwargs, k1>::type, v1>::value, "");


int main() { }
