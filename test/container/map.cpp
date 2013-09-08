/*!
 * @file
 * Contains unit tests for `boost::mpl11::container::map`.
 */

#include <boost/mpl11/container/map.hpp>

#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/test/associative_sequence.hpp>
#include <boost/mpl11/test/extensible_associative_sequence.hpp>
#include <boost/mpl11/test/instantiate.hpp>


using namespace boost::mpl11;

template <unsigned int> struct key;
template <unsigned int> struct value;

template <unsigned int i>
using make_pair = pair<key<i>, value<i>>;

BOOST_MPL11_INSTANTIATE_TEST(test::extensible_associative_sequence<
    container::map, make_pair
>);

BOOST_MPL11_INSTANTIATE_TEST(test::associative_sequence<
    container::map, make_pair
>);


int main() { }
