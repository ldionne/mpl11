/*!
 * @file
 * Contains unit tests for `boost::mpl11::class_of`.
 */

#include <boost/mpl11/class_of.hpp>

#include <boost/mpl11/detail/default_class.hpp>
#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct nested_mpl_class { struct mpl_class; };

static_assert(is_same<
    class_of<nested_mpl_class>::type,
    nested_mpl_class::mpl_class
>::value, "");

static_assert(is_same<
    class_of<struct no_nested_mpl_class>::type,
    detail::default_class
>::value, "");


int main() { }
