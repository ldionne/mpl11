/*!
 * @file
 * Contains unit tests for `boost::mpl11::container::map`.
 */

#include <boost/mpl11/container/map.hpp>

#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/test/associative_sequence.hpp>
#include <boost/mpl11/test/extensible_associative_sequence.hpp>
#include <boost/mpl11/test/instantiate.hpp>


using namespace boost::mpl11;

template <typename Unique> struct key;
template <typename Unique> struct value;

template <typename ...Pairs>
struct make_map
    : identity<container::map<Pairs...>>
{ };

BOOST_MPL11_INSTANTIATE_TEST(test::extensible_associative_sequence<
    quote<make_map>, pair<key<_1>, value<_1>>
>);

BOOST_MPL11_INSTANTIATE_TEST(test::associative_sequence<
    quote<make_map>, pair<key<_1>, value<_1>>
>);


int main() { }
