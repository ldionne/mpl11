/*!
 * @file
 * Contains unit tests for the @ref Group typeclass.
 */

#include <boost/mpl11/group.hpp>

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

struct minus_tag;
struct negate_tag;

namespace boost { namespace mpl11 {
    template <>
    struct common_datatype<Archetype1, Archetype2> {
        using type = Archetype1;
    };

    template <>
    struct Group<Archetype1> {
        template <typename, typename>
        struct minus_impl { using type = minus_tag; };

        template <typename>
        struct negate_impl { using type = negate_tag; };
    };
}} // end namespace boost::mpl11

static_assert(std_is_same<
    minus<archetype1, archetype1>::type,
    minus_tag
>::value, "");

static_assert(std_is_same<
    minus<archetype1, archetype2>::type,
    minus_tag
>::value, "");

static_assert(std_is_same<
    minus<archetype2, archetype1>::type,
    minus_tag
>::value, "");


static_assert(std_is_same<
    negate<archetype1>::type,
    negate_tag
>::value, "");


////////////////////////////////
// Test default implementations
////////////////////////////////
using Default = Group<default_<Integer>>;
static_assert(Default::minus_impl<int_<10>, int_<3>>::value == 10 - 3, "");
static_assert(Default::negate_impl<int_<10>>::value == -10, "");


int main() { }
