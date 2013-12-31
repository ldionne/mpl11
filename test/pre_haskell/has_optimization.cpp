/*!
 * @file
 * Contains unit tests for `boost::mpl11::has_optimization`.
 */

#include <boost/mpl11/has_optimization.hpp>


using namespace boost::mpl11;

static_assert(!has_optimization<
    struct not_optimized, struct some_optimization
>::value, "");


int main() { }
