/*!
 * @file
 * Contains unit tests for `boost::mpl11::Orderable`.
 */

#include <boost/mpl11/orderable.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct mpl_tag; };
struct less_tag;
struct less_equal_tag;
struct greater_tag;
struct greater_equal_tag;
struct min_tag;
struct max_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Orderable<archetype::mpl_tag, archetype::mpl_tag> {
        template <typename, typename>
        struct less_impl { using type = less_tag; };

        template <typename, typename>
        struct less_equal_impl { using type = less_equal_tag; };

        template <typename, typename>
        struct greater_impl { using type = greater_tag; };

        template <typename, typename>
        struct greater_equal_impl { using type = greater_equal_tag; };

        template <typename, typename>
        struct min_impl { using type = min_tag; };

        template <typename, typename>
        struct max_impl { using type = max_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<less_t<archetype, archetype>, less_tag>::value, "");
static_assert(is_same<less_equal_t<archetype, archetype>, less_equal_tag>::value, "");
static_assert(is_same<greater_t<archetype, archetype>, greater_tag>::value, "");
static_assert(is_same<greater_equal_t<archetype, archetype>, greater_equal_tag>::value, "");
static_assert(is_same<min_t<archetype, archetype>, min_tag>::value, "");
static_assert(is_same<max_t<archetype, archetype>, max_tag>::value, "");


///////////////////////////
// Test provided defaults
///////////////////////////
template <int i> struct x;
namespace boost { namespace mpl11 {
    template <int i, int j>
    struct less_impl<x<i>, x<j>>
        : bool_<(i < j)>
    { };
}}

using Default = Orderable<orderable_tag, orderable_tag>;

// less_equal
template <typename X, typename Y>
using leq = Default::less_equal_impl<X, Y>;
static_assert(leq<x<0>, x<0>>::value, "");
static_assert(leq<x<0>, x<1>>::value, "");
static_assert(leq<x<0>, x<2>>::value, "");

static_assert(!leq<x<1>, x<0>>::value, "");
static_assert( leq<x<1>,  x<1>>::value, "");
static_assert( leq<x<1>,  x<2>>::value, "");

static_assert(!leq<x<2>, x<0>>::value, "");
static_assert(!leq<x<2>, x<1>>::value, "");
static_assert( leq<x<2>,  x<2>>::value, "");

// greater
template <typename X, typename Y>
using gt = Default::greater_impl<X, Y>;
static_assert(!gt<x<0>, x<0>>::value, "");
static_assert( gt<x<1>,  x<0>>::value, "");
static_assert( gt<x<2>,  x<0>>::value, "");

static_assert(!gt<x<0>, x<1>>::value, "");
static_assert(!gt<x<1>, x<1>>::value, "");
static_assert( gt<x<2>,  x<1>>::value, "");

static_assert(!gt<x<0>, x<2>>::value, "");
static_assert(!gt<x<1>, x<2>>::value, "");
static_assert(!gt<x<2>, x<2>>::value, "");

// greater_equal
template <typename X, typename Y>
using geq = Default::greater_equal_impl<X, Y>;
static_assert(geq<x<0>,  x<0>>::value, "");
static_assert(geq<x<1>,  x<0>>::value, "");
static_assert(geq<x<2>,  x<0>>::value, "");

static_assert(!geq<x<0>, x<1>>::value, "");
static_assert( geq<x<1>,  x<1>>::value, "");
static_assert( geq<x<2>,  x<1>>::value, "");

static_assert(!geq<x<0>, x<2>>::value, "");
static_assert(!geq<x<1>, x<2>>::value, "");
static_assert( geq<x<2>,  x<2>>::value, "");

// min
template <typename X, typename Y>
using def_min = typename Default::min_impl<X, Y>::type;
static_assert(is_same<def_min<x<0>, x<0>>, x<0>>::value, "");
static_assert(is_same<def_min<x<0>, x<1>>, x<0>>::value, "");
static_assert(is_same<def_min<x<1>, x<0>>, x<0>>::value, "");

// max
template <typename X, typename Y>
using def_max = typename Default::max_impl<X, Y>::type;
static_assert(is_same<def_max<x<0>, x<0>>, x<0>>::value, "");
static_assert(is_same<def_max<x<0>, x<1>>, x<1>>::value, "");
static_assert(is_same<def_max<x<1>, x<0>>, x<1>>::value, "");


int main() { }
