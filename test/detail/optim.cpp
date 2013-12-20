/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::optims_of`.
 */

#include <boost/mpl11/detail/optim.hpp>


using namespace boost::mpl11;
using namespace detail;

struct not_optimized;
static_assert(optims_of<not_optimized>::value == optim::none, "");

// Example of what the vector optimizations could look like. This is just
// a small test for the constexpr bitwise operators.
static constexpr optim vector_optims = optim::O1_size | optim::O1_unpack;
static_assert((vector_optims & optim::O1_size) == optim::O1_size, "");
static_assert((vector_optims & optim::O1_unpack) == optim::O1_unpack, "");


int main() { }
