/*!
 * @file
 * Contains unit tests for `boost::mpl11::empty_base`.
 */

#include <boost/mpl11/empty_base.hpp>

#include <boost/mpl11/detail/is_specialization.hpp>


using namespace boost::mpl11;
using namespace detail;

static_assert(!is_specialization<empty_base>::value, "");

struct not_derived { int i; };
struct derived : empty_base { int i; };
static_assert(sizeof(not_derived) == sizeof(derived),
"Deriving from empty_base should trigger the empty base class optimization.");


int main() { }
