/*!
 * @file
 * Contains unit tests for the @ref Ring typeclass.
 */

#include <boost/mpl11/ring.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct Archetype1 { template <typename> using from = quote<id>; };
struct archetype1 { struct type { using mpl_datatype = Archetype1; }; };

struct Archetype2;
struct archetype2 { struct type { using mpl_datatype = Archetype2; }; };

struct mult_tag;
struct one_tag;

namespace boost { namespace mpl11 {
    template <>
    struct common_datatype<Archetype1, Archetype2> {
        using type = Archetype1;
    };

    template <>
    struct Ring<Archetype1> {
        template <typename, typename>
        struct mult_impl { using type = mult_tag; };

        template <typename ...>
        struct one_impl { using type = one_tag; };
    };
}} // end namespace boost::mpl11

static_assert(std_is_same<
    mult<archetype1, archetype1>::type,
    mult_tag
>::value, "");

static_assert(std_is_same<
    mult<archetype1, archetype2>::type,
    mult_tag
>::value, "");

static_assert(std_is_same<
    mult<archetype2, archetype1>::type,
    mult_tag
>::value, "");


static_assert(std_is_same<
    one<Archetype1>::type,
    one_tag
>::value, "");


int main() { }
