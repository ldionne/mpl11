/*!
 * @file
 * Contains unit tests for the @ref Comparable typeclass.
 */

#include <boost/mpl11/comparable.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/integer.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct Archetype1 { template <typename> using from = quote<id>; };
struct archetype1 { struct type { using mpl_datatype = Archetype1; }; };

struct Archetype2;
struct archetype2 { struct type { using mpl_datatype = Archetype2; }; };

struct equal_tag;
struct not_equal_tag;

namespace boost { namespace mpl11 {
    template <>
    struct common_datatype<Archetype1, Archetype2> {
        using type = Archetype1;
    };

    template <>
    struct Comparable<Archetype1> {
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

template <typename x, typename y>
struct dispatch_with {
    static_assert(std_is_same<
        typename equal<x, y>::type::tag,
        equal_tag
    >::value, "");

    static_assert(std_is_same<
        typename not_equal<x, y>::type::tag,
        not_equal_tag
    >::value, "");
};

struct dispatch_tests :
    dispatch_with<archetype1, archetype1>,
    dispatch_with<archetype1, archetype2>,
    dispatch_with<archetype2, archetype1>
{ };


///////////////////////////
// Test provided defaults
///////////////////////////
using Default = Comparable<default_<Integer>>;
static_assert( Default::equal_impl<int_<0>, int_<0>>::value, "");
static_assert(!Default::equal_impl<int_<0>, int_<1>>::value, "");
static_assert( Default::not_equal_impl<int_<0>, int_<1>>::value, "");
static_assert(!Default::not_equal_impl<int_<0>, int_<0>>::value, "");


int main() { }
