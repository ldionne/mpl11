/*!
 * @file
 * Contains unit tests for `boost::mpl11::cast`.
 */

#include <boost/mpl11/core.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct X;
struct x { struct type; };

template <typename> struct make_y { struct type; };
struct Y { template <typename> using from = quote<make_y>; };

static_assert(std_is_same<
    cast<X, X>::type::apply<x>::type,
    x::type
>::value, "");

static_assert(std_is_same<
    cast<X, Y>::type::apply<x>::type,
    make_y<x>::type
>::value, "");


int main() { }
