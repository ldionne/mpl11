/*!
 * @file
 * Contains unit tests for `boost::mpl11::Numeric`.
 */

#include <boost/mpl11/numeric.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct type { struct mpl_tag; }; };
struct plus_tag;
struct minus_tag;
struct times_tag;
struct negate_tag;
struct abs_tag;
struct sign_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Numeric<archetype::type::mpl_tag, archetype::type::mpl_tag> {
        template <typename, typename>
        struct plus_impl { using type = plus_tag; };

        template <typename, typename>
        struct minus_impl { using type = minus_tag; };

        template <typename, typename>
        struct times_impl { using type = times_tag; };

        template <typename>
        struct negate_impl { using type = negate_tag; };

        template <typename>
        struct abs_impl { using type = abs_tag; };

        template <typename>
        struct sign_impl { using type = sign_tag; };
    };
}} // end namespace boost::mpl11

static_assert(is_same<plus_t<archetype, archetype>, plus_tag>::value, "");
static_assert(is_same<minus_t<archetype, archetype>, minus_tag>::value, "");
static_assert(is_same<times_t<archetype, archetype>, times_tag>::value, "");
static_assert(is_same<negate_t<archetype>, negate_tag>::value, "");
static_assert(is_same<abs_t<archetype>, abs_tag>::value, "");
static_assert(is_same<sign_t<archetype>, sign_tag>::value, "");


int main() { }
