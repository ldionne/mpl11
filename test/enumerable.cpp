/*!
 * @file
 * Contains unit tests for the @ref Enumerable typeclass.
 */

#include <boost/mpl11/enumerable.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct Archetype;
struct archetype { struct type { using mpl_datatype = Archetype; }; };
struct succ_tag;
struct pred_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Enumerable<Archetype> {
        template <typename>
        struct succ_impl { using type = succ_tag; };

        template <typename>
        struct pred_impl { using type = pred_tag; };
    };
}} // end namespace boost::mpl11

static_assert(std_is_same<
    succ<archetype>::type,
    succ_tag
>::value, "");

static_assert(std_is_same<
    pred<archetype>::type,
    pred_tag
>::value, "");


int main() { }
