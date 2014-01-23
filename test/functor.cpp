/*!
 * @file
 * Contains unit tests for the @ref Functor typeclass.
 */

#include <boost/mpl11/functor.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct FunctorArchetype;
struct archetype { struct type { using mpl_datatype = FunctorArchetype; }; };
struct fmap_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Functor<FunctorArchetype> {
        template <typename, typename>
        struct fmap_impl { using type = fmap_tag; };
    };
}} // end namespace boost::mpl11

static_assert(std_is_same<
    fmap<undefined, archetype>::type,
    fmap_tag
>::value, "");


int main() { }
