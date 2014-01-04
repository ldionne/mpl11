/*!
 * @file
 * Contains unit tests for `boost::mpl11::Integral`.
 */

#include <boost/mpl11/integral.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct mpl_tag; };
struct quot_tag;
struct rem_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Integral<archetype::mpl_tag, archetype::mpl_tag> {
        template <typename, typename>
        struct quot_impl { using type = quot_tag; };

        template <typename, typename>
        struct rem_impl { using type = rem_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<quot_t<archetype, archetype>, quot_tag>::value, "");
static_assert(is_same<rem_t<archetype, archetype>, rem_tag>::value, "");


int main() { }
