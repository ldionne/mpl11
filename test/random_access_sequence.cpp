/*!
 * @file
 * Contains unit tests for `boost::mpl11::RandomAccessSequence`.
 */

#include <boost/mpl11/random_access_sequence.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct mpl_tag; };
struct at_tag;
struct slice_tag;

namespace boost { namespace mpl11 {
    template <>
    struct RandomAccessSequence<archetype::mpl_tag> {
        template <typename, typename> struct at_impl { using type = at_tag; };
        template <typename, typename, typename>
        struct slice_impl { using type = slice_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<at_c_t<archetype, 0>, at_tag>::value, "");
static_assert(is_same<slice_c_t<archetype, 0, 0>, slice_tag>::value, "");


int main() { }
