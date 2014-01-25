/*!
 * @file
 * Contains unit tests for `boost::mpl11::not_`.
 */

#include <boost/mpl11/logical.hpp>


using namespace boost::mpl11;

struct yes { struct type { static constexpr bool value = true; }; };
struct no { struct type { static constexpr bool value = false; }; };
static_assert(!not_<yes>::value, "");
static_assert( not_<no>::value, "");


int main() { }
