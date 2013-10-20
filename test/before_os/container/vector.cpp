/*!
 * @file
 * Contains unit tests for `boost::mpl11::container::vector`.
 */

#include <boost/mpl11/vector.hpp>

#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/test/instantiate.hpp>
#include <boost/mpl11/test/random_access_sequence.hpp>
#include <boost/mpl11/test/random_extensible_sequence.hpp>


using namespace boost::mpl11;

template <typename ...T>
struct make_vector
    : identity<container::vector<T...>>
{ };

BOOST_MPL11_INSTANTIATE_TEST(test::random_extensible_sequence<
    quote<make_vector>
>);

BOOST_MPL11_INSTANTIATE_TEST(test::random_access_sequence<
    quote<make_vector>
>);


int main() { }
