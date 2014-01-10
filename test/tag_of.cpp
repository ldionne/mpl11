/*!
 * @file
 * Contains unit tests for `boost::mpl11::tag_of`.
 */

#include <boost/mpl11/tag_of.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct with_nested_tag { struct mpl_tag; };
struct without_nested_tag { };

static_assert(is_same<
    tag_of_t<with_nested_tag>, with_nested_tag::mpl_tag
>::value, "");

static_assert(is_same<
    tag_of_t<without_nested_tag>, foreign_tag
>::value, "");


int main() { }
