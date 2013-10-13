/*!
 * @file
 * Contains unit tests for the default implementation of `boost::mpl11::not_`.
 */

#include <boost/mpl11/not.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>


using boost::mpl11::not_;
using true_ = boost::mpl11::identity<boost::mpl11::true_>;
using false_ = boost::mpl11::identity<boost::mpl11::false_>;


static_assert(not_<false_>::type::value, "");
static_assert(!not_<true_>::type::value, "");


int main() { }
