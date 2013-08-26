/*!
 * @file
 * This file contains unit tests for `boost::mpl11::as_placeholder`.
 */

#include <boost/mpl11/as_placeholder.hpp>

#include <boost/mpl11/is_placeholder.hpp>


using namespace boost::mpl11;

struct not_a_placeholder { };
static_assert(!is_placeholder<not_a_placeholder>::value, "");
static_assert(is_placeholder<as_placeholder<not_a_placeholder>>::value, "");


int main() { }
