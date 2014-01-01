/*!
 * @file
 * Contains unit tests for `boost::mpl11::FiniteSequence`.
 */

#include <boost/mpl11/finite_sequence.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct mpl_tag; };
struct length_tag;
struct unpack_tag;

namespace boost { namespace mpl11 {
    template <>
    struct FiniteSequence<archetype::mpl_tag> {
        template <typename> struct length_impl { using type = length_tag; };
        template <typename, typename>
        struct unpack_impl { using type = unpack_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<length_t<archetype>, length_tag>::value, "");
static_assert(is_same<unpack_t<archetype, struct x>, unpack_tag>::value, "");


int main() { }
