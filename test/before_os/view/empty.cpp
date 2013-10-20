/*!
 * @file
 * Contains unit tests for `boost::mpl11::empty_sequence`.
 */

#include <boost/mpl11/empty_sequence.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/is_empty.hpp>


using namespace boost::mpl11;

static_assert(is_empty<empty_sequence>::type::value, "");

static_assert(equal_to<
    begin<empty_sequence>::type,
    end<empty_sequence>::type
>::type::value, "");


int main() { }
