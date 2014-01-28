/*!
 * @file
 * Contains unit tests for the @ref Comparable typeclass.
 */

#include <boost/mpl11/comparable.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct Archetype;
struct archetype { struct type { using mpl_datatype = Archetype; }; };
struct equal_tag;
struct not_equal_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Comparable<Archetype> {
        template <typename, typename>
        struct equal_impl {
            struct type : true_ { using tag = equal_tag; };
        };

        template <typename, typename>
        struct not_equal_impl {
            struct type : false_ { using tag = not_equal_tag; };
        };
    };
}} // end namespace boost::mpl11

static_assert(std_is_same<
    equal<archetype, archetype>::type::tag,
    equal_tag
>::value, "");

static_assert(std_is_same<
    not_equal<archetype, archetype>::type::tag,
    not_equal_tag
>::value, "");


//////////////////////////////////////////////////////
// Test comparison for foreign and incompatible types
//////////////////////////////////////////////////////
template <bool eq, typename ...x>
struct assert_eq {
    static_assert(eq == equal<x...>::value, "");
};

template <bool eq, typename x, typename y>
struct assert_eq<eq, x, y> {
    static_assert(eq == equal<x, y>::value, "");
    static_assert(!equal<x, y>::value == not_equal<x, y>::value, "");
};

struct x { struct type; };
struct y { struct type; };
struct z { struct type; };

struct tests :
    assert_eq<true,  x, x>,
    assert_eq<false, x, y>,
    assert_eq<true,  x, x, x>,
    assert_eq<false, x, x, y>,
    assert_eq<false, x, y, x>,
    assert_eq<false, y, x, x>,
    assert_eq<false, x, y, z>,

    assert_eq<false, x, archetype>,
    assert_eq<false, archetype, x>,
    assert_eq<false, x, y, archetype>,
    assert_eq<false, x, archetype, y>,
    assert_eq<false, archetype, archetype, x>,
    assert_eq<false, x, archetype, archetype>,

    assert_eq<false, x, archetype, undefined>,
    assert_eq<false, x, y, undefined>
{ };


///////////////////////////
// Test provided defaults
///////////////////////////
using Default = Comparable<typeclass<Comparable>>;
static_assert( Default::equal_impl<x::type, x::type>::value, "");
static_assert(!Default::equal_impl<x::type, y::type>::value, "");
static_assert( Default::not_equal_impl<x::type, y::type>::value, "");
static_assert(!Default::not_equal_impl<x::type, x::type>::value, "");


int main() { }
