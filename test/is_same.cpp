/*!
 * @file
 * This file contains unit tests for `boost::mpl11::is_same`.
 */

#include <boost/mpl11/is_same.hpp>


using boost::mpl11::is_same;

static_assert(is_same<int, int>::value, "");
static_assert(is_same<int, int, int>::value, "");

static_assert(!is_same<int, int, float>::value, "");
static_assert(!is_same<float, int, int>::value, "");
static_assert(!is_same<int, float, int>::value, "");


int main() { }
