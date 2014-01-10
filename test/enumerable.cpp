/*!
 * @file
 * Contains unit tests for `boost::mpl11::Enumerable`.
 */

#include <boost/mpl11/enumerable.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct type { struct mpl_tag; }; };
struct succ_tag;
struct pred_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Enumerable<archetype::type::mpl_tag> {
        template <typename>
        struct succ_impl { using type = succ_tag; };

        template <typename>
        struct pred_impl { using type = pred_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<succ_t<archetype>, succ_tag>::value, "");
static_assert(is_same<pred_t<archetype>, pred_tag>::value, "");


int main() { }
