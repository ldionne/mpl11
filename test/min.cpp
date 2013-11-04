/*!
 * @file
 * Contains unit tests for `boost::mpl11::min`.
 */

#include <boost/mpl11/min.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/orderable.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int i>
struct x {
    static constexpr auto value = i;

    struct mpl_class : Orderable {
        template <typename X, typename Y>
        struct less_impl
            : bool_<(X::value < Y::value)>
        { };
    };
};

static_assert(is_same<
    min<x<0>, x<1>>::type, x<0>
>::value, "");
static_assert(is_same<
    min<x<1>, x<0>>::type, x<0>
>::value, "");

static_assert(is_same<
    min<x<0>, x<1>, x<2>>::type, x<0>
>::value, "");
static_assert(is_same<
    min<x<1>, x<2>, x<0>>::type, x<0>
>::value, "");
static_assert(is_same<
    min<x<2>, x<0>, x<1>>::type, x<0>
>::value, "");

static_assert(is_same<
    min<x<1>, x<2>, x<8>, x<-4>, x<4>, x<7>>::type, x<-4>
>::value, "");


int main() { }
