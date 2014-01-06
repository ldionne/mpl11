/*!
 * @file
 * Contains unit tests for `boost::mpl11::pair`.
 */

#include <boost/mpl11/pair.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/first.hpp>
#include <boost/mpl11/second.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct First; struct Second;

// first
static_assert(is_same<first<pair<First, Second>>::type, First>::value, "");

// second
static_assert(is_same<second<pair<First, Second>>::type, Second>::value, "");


int main() { }
