/*!
 * @file
 * Contains unit tests for `boost::mpl11::Bitwise`.
 */

#include <boost/mpl11/bitwise.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct mpl_tag; };
struct bitand_tag;
struct bitor_tag;
struct bitxor_tag;
struct shift_left_tag;
struct shift_right_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Bitwise<archetype::mpl_tag, archetype::mpl_tag> {
        template <typename, typename>
        struct bitand_impl { using type = bitand_tag; };

        template <typename, typename>
        struct bitor_impl { using type = bitor_tag; };

        template <typename, typename>
        struct bitxor_impl { using type = bitxor_tag; };

        template <typename, typename>
        struct shift_left_impl { using type = shift_left_tag; };

        template <typename, typename>
        struct shift_right_impl { using type = shift_right_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<bitand_t<archetype, archetype>, bitand_tag>::value, "");
static_assert(is_same<bitor_t<archetype, archetype>, bitor_tag>::value, "");
static_assert(is_same<bitxor_t<archetype, archetype>, bitxor_tag>::value, "");
static_assert(is_same<shift_left_c_t<archetype, 0>, shift_left_tag>::value, "");
static_assert(is_same<shift_right_c_t<archetype, 0>, shift_right_tag>::value, "");


int main() { }
