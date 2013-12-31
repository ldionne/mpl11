/*!
 * @file
 * Contains unit tests for `boost::mpl11::Logical`.
 */

#include <boost/mpl11/logical.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>


using namespace boost::mpl11;

template <int>
struct True {
    struct mpl_class : Logical {
        template <typename> struct not_impl : bool_<false> { };
    };
};

template <int>
struct False {
    struct mpl_class : Logical {
        template <typename> struct not_impl : bool_<true> { };
    };
};

// Logical operators expect metafunctions
template <int i> struct f { using type = False<i>; };
template <int i> struct t { using type = True<i>; };

// To make the syntax lighter below.
template <typename TestedExpression, typename Expected>
using is_same = detail::is_same<TestedExpression, typename Expected::type>;

struct short_circuit;

// not_
static_assert(!not_<t<0>>::value, "");
static_assert(not_<f<0>>::value, "");


// and_ (2 args)
static_assert(is_same<and_<t<0>, t<1>>::type, t<1>>::value, "");
static_assert(is_same<and_<t<0>, f<1>>::type, f<1>>::value, "");
static_assert(is_same<and_<f<0>, t<1>>::type, f<0>>::value, "");
static_assert(is_same<and_<f<0>, f<1>>::type, f<0>>::value, "");

static_assert(is_same<and_<f<0>, short_circuit>::type, f<0>>::value, "");


// and_ (3 args)
static_assert(is_same<and_<t<0>, t<1>, t<2>>::type, t<2>>::value, "");
static_assert(is_same<and_<t<0>, t<1>, f<2>>::type, f<2>>::value, "");
static_assert(is_same<and_<t<0>, f<1>, t<2>>::type, f<1>>::value, "");
static_assert(is_same<and_<t<0>, f<1>, f<2>>::type, f<1>>::value, "");

static_assert(is_same<and_<f<0>, t<1>, t<2>>::type, f<0>>::value, "");
static_assert(is_same<and_<f<0>, t<1>, f<2>>::type, f<0>>::value, "");
static_assert(is_same<and_<f<0>, f<1>, t<2>>::type, f<0>>::value, "");
static_assert(is_same<and_<f<0>, f<1>, f<2>>::type, f<0>>::value, "");

static_assert(is_same<and_<t<0>, f<1>, short_circuit>::type, f<1>>::value, "");
static_assert(is_same<and_<f<0>, t<1>, short_circuit>::type, f<0>>::value, "");
static_assert(is_same<and_<f<0>, f<1>, short_circuit>::type, f<0>>::value, "");


// or_ (2 args)
static_assert(is_same<or_<t<0>, t<1>>::type, t<0>>::value, "");
static_assert(is_same<or_<t<0>, f<1>>::type, t<0>>::value, "");
static_assert(is_same<or_<f<0>, t<1>>::type, t<1>>::value, "");
static_assert(is_same<or_<f<0>, f<1>>::type, f<1>>::value, "");

static_assert(is_same<or_<t<0>, short_circuit>::type, t<0>>::value, "");


// or_ (3 args)
static_assert(is_same<or_<t<0>, t<1>, t<2>>::type, t<0>>::value, "");
static_assert(is_same<or_<t<0>, t<1>, f<2>>::type, t<0>>::value, "");
static_assert(is_same<or_<t<0>, f<1>, t<2>>::type, t<0>>::value, "");
static_assert(is_same<or_<t<0>, f<1>, f<2>>::type, t<0>>::value, "");

static_assert(is_same<or_<f<0>, t<1>, t<2>>::type, t<1>>::value, "");
static_assert(is_same<or_<f<0>, t<1>, f<2>>::type, t<1>>::value, "");
static_assert(is_same<or_<f<0>, f<1>, t<2>>::type, t<2>>::value, "");
static_assert(is_same<or_<f<0>, f<1>, f<2>>::type, f<2>>::value, "");

static_assert(is_same<or_<f<0>, t<1>, short_circuit>::type, t<1>>::value, "");
static_assert(is_same<or_<t<0>, f<1>, short_circuit>::type, t<0>>::value, "");
static_assert(is_same<or_<t<0>, t<1>, short_circuit>::type, t<0>>::value, "");


int main() { }
