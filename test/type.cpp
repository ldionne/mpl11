/*!
 * @file
 * Contains unit tests for `boost::mpl11::Type`.
 */

#include <boost/mpl11/type.hpp>

#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/not_equal.hpp>


using namespace boost::mpl11;

template <int>
struct t { using mpl_class = Type; };

static_assert( equal<t<0>, t<0>>::value, "");
static_assert(!equal<t<0>, t<1>>::value, "");

static_assert( not_equal<t<0>, t<1>>::value, "");
static_assert(!not_equal<t<0>, t<0>>::value, "");


int main() { }
