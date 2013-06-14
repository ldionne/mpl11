/*!
 * @file
 * This file contains unit tests for `boost::mpl11::trait::is_placeholder`.
 */

#include <boost/mpl11/trait/is_placeholder.hpp>
#include <boost/mpl11/bool.hpp>


using namespace boost::mpl11;

struct not_a_placeholder1;
struct not_a_placeholder2 { };
struct not_a_placeholder3 { struct mpl11; };
struct not_a_placeholder4 { struct mpl11 { }; };

struct a_placeholder1 { struct mpl11 { struct is_placeholder; }; };

struct a_placeholder2;
namespace boost { namespace mpl11 { namespace trait {
    template <>
    struct is_placeholder<a_placeholder2> : true_ { };
}}}

static_assert(!trait::is_placeholder<not_a_placeholder1>::value, "");
static_assert(!trait::is_placeholder<not_a_placeholder2>::value, "");
static_assert(!trait::is_placeholder<not_a_placeholder3>::value, "");
static_assert(!trait::is_placeholder<not_a_placeholder4>::value, "");
static_assert(trait::is_placeholder<a_placeholder1>::value, "");
static_assert(trait::is_placeholder<a_placeholder2>::value, "");


int main() { }
