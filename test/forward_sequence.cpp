/*!
 * @file
 * Contains unit tests for `boost::mpl11::ForwardSequence`.
 */

#include <boost/mpl11/forward_sequence.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct mpl_tag; };
struct head_tag;
struct tail_tag;
struct is_empty_tag;

namespace boost { namespace mpl11 {
    template <>
    struct ForwardSequence<archetype::mpl_tag> {
        template <typename> struct head_impl { using type = head_tag; };
        template <typename> struct tail_impl { using type = tail_tag; };
        template <typename>
        struct is_empty_impl : false_ { using type = is_empty_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<head_t<archetype>, head_tag>::value, "");
static_assert(is_same<tail_t<archetype>, tail_tag>::value, "");
static_assert(is_same<is_empty_t<archetype>, is_empty_tag>::value, "");


int main() { }
