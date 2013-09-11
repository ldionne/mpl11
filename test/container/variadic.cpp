/*!
 * @file
 * Contains unit tests for `boost::mpl11::container::variadic`.
 */

#include <boost/mpl11/container/variadic.hpp>

#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/test/instantiate.hpp>
#include <boost/mpl11/test/random_access_sequence.hpp>
#include <boost/mpl11/test/random_extensible_sequence.hpp>


using namespace boost::mpl11;

template <typename ...>
struct some_template;

template <typename ...T>
struct make_variadic
    : identity<container::variadic<some_template, T...>>
{ };

BOOST_MPL11_INSTANTIATE_TEST(test::random_extensible_sequence<
    quote<make_variadic>
>);

BOOST_MPL11_INSTANTIATE_TEST(test::random_access_sequence<
    quote<make_variadic>
>);

static_assert(equal_to<
    container::variadic<some_template, int, float, char>::type,
    some_template<int, float, char>
>::type::value, "");


int main() { }
