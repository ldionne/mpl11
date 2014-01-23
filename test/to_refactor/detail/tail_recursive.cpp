/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::tail_recursive`.
 */

#include <boost/mpl11/detail/tail_recursive.hpp>


using namespace boost::mpl11;
using detail::tail_recursive;

// We don't use `integral_c` here because it is a metafunction and we want
// to catch it if we incorrectly fetch a nested `::type`.
template <unsigned long N>
struct final_result {
    static constexpr unsigned long value = N;
};

template <unsigned long From, unsigned long To, unsigned long Acc>
struct sum_from_to_impl {
    using tail_call = sum_from_to_impl<From + 1, To, Acc + From>;
};

template <unsigned long To, unsigned long Acc>
struct sum_from_to_impl<To, To, Acc> {
    using tail_call = sum_from_to_impl;
    using type = final_result<Acc + To>;
};

template <unsigned long From, unsigned long To>
using sum_from_to = tail_recursive<sum_from_to_impl<From, To, 0>>;

static constexpr unsigned long N = 10000;
static_assert(sum_from_to<0, N>::type::value == (N * (N+1)) / 2, "");


int main() { }
