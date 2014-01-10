/*!
 * @file
 * Contains unit tests for the @ref Functor typeclass.
 */

#include <boost/mpl11/functor.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct type { struct mpl_tag; }; };
struct fmap_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Functor<archetype::type::mpl_tag> {
        template <typename, typename>
        struct fmap_impl { using type = fmap_tag; };
    };
}} // end namespace boost::mpl11

struct F { struct type; };
static_assert(is_same<fmap_t<F, archetype>, fmap_tag>::value, "");


int main() { }
