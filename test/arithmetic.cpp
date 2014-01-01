/*!
 * @file
 * Contains unit tests for `boost::mpl11::Arithmetic`.
 */

#include <boost/mpl11/arithmetic.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct mpl_tag; };
struct add_tag;
struct subtract_tag;
struct divide_tag;
struct multiply_tag;
struct modulo_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Arithmetic<archetype::mpl_tag, archetype::mpl_tag> {
        template <typename, typename>
        struct add_impl { using type = add_tag; };

        template <typename, typename>
        struct subtract_impl { using type = subtract_tag; };

        template <typename, typename>
        struct divide_impl { using type = divide_tag; };

        template <typename, typename>
        struct multiply_impl { using type = multiply_tag; };

        template <typename, typename>
        struct modulo_impl { using type = modulo_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<add_t<archetype, archetype>, add_tag>::value, "");
static_assert(is_same<subtract_t<archetype, archetype>, subtract_tag>::value, "");
static_assert(is_same<divide_t<archetype, archetype>, divide_tag>::value, "");
static_assert(is_same<multiply_t<archetype, archetype>, multiply_tag>::value, "");
static_assert(is_same<modulo_t<archetype, archetype>, modulo_tag>::value, "");


int main() { }
