/*!
 * @file
 * Contains unit tests for `boost::mpl11::integral_c`.
 */

#include <boost/mpl11/integral_c.hpp>

#include <boost/mpl11/detail/test/instantiate.hpp>
#include <boost/mpl11/detail/test/integral_constant.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;

template <typename T, typename N>
struct make_integral_c
    : identity<
        integral_c<T, N::value>
    >
{ };

BOOST_MPL11_INSTANTIATE_TEST(detail::test::integral_constant<
    quote<make_integral_c>
>);


int main() { }
