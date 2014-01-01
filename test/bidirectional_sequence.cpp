/*!
 * @file
 * Contains unit tests for `boost::mpl11::BidirectionalSequence`.
 */

#include <boost/mpl11/bidirectional_sequence.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/fwd/forward_sequence.hpp>
#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct mpl_tag; };
struct last_tag;
struct init_tag;

namespace boost { namespace mpl11 {
    // Required by check_usage
    template <> struct is_empty<archetype> : false_ { };

    template <>
    struct BidirectionalSequence<archetype::mpl_tag> {
        template <typename> struct last_impl { using type = last_tag; };
        template <typename> struct init_impl { using type = init_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<last_t<archetype>, last_tag>::value, "");
static_assert(is_same<init_t<archetype>, init_tag>::value, "");


int main() { }
