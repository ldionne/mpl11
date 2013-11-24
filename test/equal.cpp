/*!
 * @file
 * Contains unit tests for `boost::mpl11::equal`.
 */

#include <boost/mpl11/equal.hpp>


using namespace boost::mpl11;

template <int> struct no_mpl_class;

static_assert( equal<no_mpl_class<0>, no_mpl_class<0>>::value, "");
static_assert(!equal<no_mpl_class<0>, no_mpl_class<1>>::value, "");
static_assert(!equal<no_mpl_class<0>, no_mpl_class<2>>::value, "");


int main() { }
