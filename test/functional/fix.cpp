/*!
 * @file
 * Contains unit tests for `boost::mpl11::fix`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/integer.hpp>
#include <boost/mpl11/logical.hpp>


using namespace boost::mpl11;

// Factorial using fix<>
template <typename f, typename n>
using fact_impl = if_c<n::type::value == 0,
    ullong<1>,
    mult<n, apply<f, pred<n>>>
>;

template <unsigned long long n>
struct fact_fix {
    static constexpr auto value = fix<lift<fact_impl>>::type::
                                  template apply<ullong<n>>::type::value;
};


// Standard recursive factorial
template <unsigned long long n>
struct fact_rec { static constexpr auto value = n * fact_rec<n - 1>::value; };

template <>
struct fact_rec<0> { static constexpr unsigned long long value = 1; };


// Compare both implementations for a couple of values.
template <unsigned long long from, unsigned long long to>
struct test_fact : test_fact<from + 1, to> {
    static_assert(fact_fix<from>::value == fact_rec<from>::value, "");
};

template <unsigned long long to>
struct test_fact<to, to> { };

struct tests
    : test_fact<0, 15>
{ };


int main() { }
