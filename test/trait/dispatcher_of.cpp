/*!
 * @file
 * This file contains unit tests for `boost::mpl11::trait::dispatcher_of`.
 */

#include <boost/mpl11/trait/dispatcher_of.hpp>
#include <boost/mpl11/has_xxx.hpp>

#include <boost/type_traits/is_same.hpp>


BOOST_MPL11_HAS_NESTED_TYPE(has_type, type)

using namespace boost;
using namespace boost::mpl11;

struct no_dispatcher1;
struct no_dispatcher2 { };
struct no_dispatcher3 { struct mpl11; };
struct no_dispatcher4 { struct mpl11 { }; };

struct the_dispatcher;
struct with_dispatcher1 {
    struct mpl11 { using dispatcher = the_dispatcher; };
};

struct with_dispatcher2;
namespace boost { namespace mpl11 { namespace trait {
    template <>
    struct dispatcher_of<with_dispatcher2> {
        using type = the_dispatcher;
    };
}}}

static_assert(!has_type<trait::dispatcher_of<no_dispatcher1>>::value, "");
static_assert(!has_type<trait::dispatcher_of<no_dispatcher2>>::value, "");
static_assert(!has_type<trait::dispatcher_of<no_dispatcher3>>::value, "");
static_assert(!has_type<trait::dispatcher_of<no_dispatcher4>>::value, "");
static_assert(is_same<
    the_dispatcher, trait::dispatcher_of<with_dispatcher1>::type
>::value, "");
static_assert(is_same<
    the_dispatcher, trait::dispatcher_of<with_dispatcher2>::type
>::value, "");


int main() { }
