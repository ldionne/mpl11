/*!
 * @file
 * Contains unit tests for `boost::mpl11::Bitwise`.
 */

#include <boost/mpl11/bitwise.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct mpl_tag; };
struct bitand_tag;
struct bitor_tag;
struct bitxor_tag;
struct shift_left_c_tag;
struct shift_right_c_tag;
struct compl_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Bitwise<archetype::mpl_tag, archetype::mpl_tag> {
        template <typename, typename>
        struct bitand_impl { using type = bitand_tag; };

        template <typename, typename>
        struct bitor_impl { using type = bitor_tag; };

        template <typename, typename>
        struct bitxor_impl { using type = bitxor_tag; };

        template <typename, detail::std_size_t>
        struct shift_left_c_impl { using type = shift_left_c_tag; };

        template <typename, detail::std_size_t>
        struct shift_right_c_impl { using type = shift_right_c_tag; };

        template <typename>
        struct compl_impl { using type = compl_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<bitand_t<archetype, archetype>, bitand_tag>::value, "");
static_assert(is_same<bitor_t<archetype, archetype>, bitor_tag>::value, "");
static_assert(is_same<bitxor_t<archetype, archetype>, bitxor_tag>::value, "");
static_assert(is_same<shift_left_c_t<archetype, 0>, shift_left_c_tag>::value, "");
static_assert(is_same<shift_right_c_t<archetype, 0>, shift_right_c_tag>::value, "");

static_assert(is_same<shift_right_t<archetype, size_t<0>>, shift_right_c_tag>::value, "");
static_assert(is_same<shift_left_t<archetype, size_t<0>>,  shift_left_c_tag>::value, "");


int main() { }
