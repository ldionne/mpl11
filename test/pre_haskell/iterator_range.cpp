/*!
 * @file
 * Contains unit tests for `boost::mpl11::iterator_range`.
 */

#include <boost/mpl11/iterator_range.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct First; struct Last;

// begin
static_assert(is_same<begin_t<iterator_range<First, Last>>, First>::value, "");

// end
static_assert(is_same<end_t<iterator_range<First, Last>>, Last>::value, "");


int main() { }
