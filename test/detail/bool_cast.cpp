/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::bool_cast`.
 */

#include <boost/mpl11/detail/bool_cast.hpp>

#include <boost/mpl11/bool.hpp>


using namespace boost::mpl11;
using detail::bool_cast;

static_assert(bool_cast<true_>::value, "");
static_assert(!bool_cast<false_>::value, "");


int main() { }
