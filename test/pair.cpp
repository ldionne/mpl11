/*!
 * @file
 * This file contains unit tests for `boost::mpl11::pair`.
 */

#include <boost/mpl11/pair.hpp>

#include <boost/mpl11/first.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/second.hpp>


using namespace boost::mpl11;

struct First;
struct Second;
using Pair = pair<First, Second>;

static_assert(is_same<first<Pair>::type, First>::value, "");
static_assert(is_same<second<Pair>::type, Second>::value, "");


int main() { }
