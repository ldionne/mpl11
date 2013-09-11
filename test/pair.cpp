/*!
 * @file
 * Contains unit tests for `boost::mpl11::pair`.
 */

#include <boost/mpl11/pair.hpp>

#include <boost/mpl11/intrinsic/first.hpp>
#include <boost/mpl11/intrinsic/second.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


using namespace boost::mpl11;

struct First;
struct Second;
using Pair = pair<First, Second>;

static_assert(equal_to<
    first<Pair>::type, First
>::type::value, "");

static_assert(equal_to<
    second<Pair>::type, Second
>::type::value, "");


int main() { }
