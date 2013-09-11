/*!
 * @file
 * Contains unit tests for `boost::mpl11::pair`.
 */

#include <boost/mpl11/pair.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/intrinsic/first.hpp>
#include <boost/mpl11/intrinsic/second.hpp>


using namespace boost::mpl11;

struct First;
struct Second;
using Pair = pair<First, Second>;

static_assert(detail::is_same<
    first<Pair>::type, First
>::value, "");

static_assert(detail::is_same<
    second<Pair>::type, Second
>::value, "");


int main() { }
