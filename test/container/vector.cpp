/*!
 * @file
 * Contains unit tests for `boost::mpl11::container::vector`.
 */

#include <boost/mpl11/container/vector.hpp>

#include <boost/mpl11/test/back_extensible_sequence.hpp>
#include <boost/mpl11/test/front_extensible_sequence.hpp>
#include <boost/mpl11/test/instantiate.hpp>
#include <boost/mpl11/test/random_access_sequence.hpp>


using namespace boost::mpl11;

BOOST_MPL11_INSTANTIATE_TEST(test::front_extensible_sequence<
    container::vector
>);

BOOST_MPL11_INSTANTIATE_TEST(test::back_extensible_sequence<
    container::vector
>);

BOOST_MPL11_INSTANTIATE_TEST(test::random_access_sequence<
    container::vector
>);


int main() { }
