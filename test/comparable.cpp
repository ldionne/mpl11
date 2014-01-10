/*!
 * @file
 * Contains unit tests for `boost::mpl11::Comparable`.
 */

#include <boost/mpl11/comparable.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct type { struct mpl_tag; }; };
struct equal_tag;
struct not_equal_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Comparable<archetype::type::mpl_tag, archetype::type::mpl_tag> {
        template <typename, typename>
        struct equal_impl { using type = equal_tag; };

        template <typename, typename>
        struct not_equal_impl { using type = not_equal_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<equal_t<archetype, archetype>, equal_tag>::value, "");
static_assert(is_same<not_equal_t<archetype, archetype>, not_equal_tag>::value, "");


///////////////////////////////////////////////////////////////////
// Test comparison for foreign or incompatible types (aka is_same)
///////////////////////////////////////////////////////////////////
struct x { struct type; };
struct y { struct type; };
static_assert(!equal<x, y>::value, "");
static_assert( equal<x, x>::value, "");
static_assert( not_equal<x, y>::value, "");
static_assert(!not_equal<x, x>::value, "");


///////////////////////////
// Test provided defaults
///////////////////////////
using Default = Comparable<comparable_tag, comparable_tag>;
static_assert( Default::equal_impl<x::type, x::type>::value, "");
static_assert(!Default::equal_impl<x::type, y::type>::value, "");
static_assert( Default::not_equal_impl<x::type, y::type>::value, "");
static_assert(!Default::not_equal_impl<x::type, x::type>::value, "");


int main() { }
