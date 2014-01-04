/*!
 * @file
 * Contains unit tests for `boost::mpl11::Sequence`.
 */

#include <boost/mpl11/sequence.hpp>

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
struct last_tag;
struct init_tag;
struct at_c_tag;
struct length_tag;
struct unpack_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Sequence<archetype::mpl_tag> {
        template <typename> struct head_impl
        { using type = head_tag; };

        template <typename> struct tail_impl
        { using type = tail_tag; };

        template <typename> struct is_empty_impl : false_
        { using type = is_empty_tag; };

        template <typename> struct last_impl
        { using type = last_tag; };

        template <typename> struct init_impl
        { using type = init_tag; };

        template <typename, detail::std_size_t> struct at_c_impl
        { using type = at_c_tag; };

        template <typename> struct length_impl
        { using type = length_tag; };

        template <typename, typename>
        struct unpack_impl { using type = unpack_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<head_t<archetype>,             head_tag>::value, "");
static_assert(is_same<tail_t<archetype>,             tail_tag>::value, "");
static_assert(is_same<is_empty_t<archetype>,         is_empty_tag>::value, "");
static_assert(is_same<last_t<archetype>,             last_tag>::value, "");
static_assert(is_same<init_t<archetype>,             init_tag>::value, "");
static_assert(is_same<at_c_t<archetype, 0>,          at_c_tag>::value, "");
static_assert(is_same<length_t<archetype>,           length_tag>::value, "");
static_assert(is_same<unpack_t<archetype, struct x>, unpack_tag>::value, "");


int main() { }
