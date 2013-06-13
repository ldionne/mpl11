/*!
 * @file
 * This file contains unit tests for `boost::mpl11::pair`.
 */

#include <boost/mpl11/container/pair.hpp>

#include <boost/type_traits/is_same.hpp>


using namespace boost;
using namespace boost::mpl11;

struct a0;
struct a1;

static_assert(is_same<first<pair<a0, a1>>::type, a0>::value, "");
static_assert(is_same<second<pair<a0, a1>>::type, a1>::value, "");


int main() { }
