/*!
 * @file
 * Contains unit tests for `boost::mpl11::and_c`.
 */

#include <boost/mpl11/and.hpp>


using namespace boost::mpl11;

static_assert( and_c<true, true>::value, "");
static_assert(!and_c<true, false>::value, "");
static_assert(!and_c<false, true>::value, "");
static_assert(!and_c<false, false>::value, "");

static_assert( and_c<true, true, true>::value, "");
static_assert(!and_c<true, true, false>::value, "");
static_assert(!and_c<true, false, true>::value, "");
static_assert(!and_c<true, false, false>::value, "");
static_assert(!and_c<false, true, true>::value, "");
static_assert(!and_c<false, true, false>::value, "");
static_assert(!and_c<false, false, true>::value, "");
static_assert(!and_c<false, false, false>::value, "");


int main() { }
