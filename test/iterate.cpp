/*!
 * @file
 * Contains unit tests for `boost::mpl11::iterate`.
 */

#include <boost/mpl11/iterate.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/iterable_test.hpp>
#include <boost/mpl11/iterable/take.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct X;
template <typename> struct F { using type = F; };

// head
static_assert(is_same<head_t<iterate_t<quote<F>, X>>, X>::value, "");

// is_empty
static_assert(!is_empty<iterate_t<quote<F>, X>>::value, "");


template <unsigned long N>
struct iterating_n {
    template <typename ...Values>
    struct is
        : detail::iterable_test<
            take_c_t<N,
                iterate_t<quote<F>, X>
            >,
            Values...
        >
    { };
};

struct tests :
    iterating_n<1>::is<X>,
    iterating_n<2>::is<X, F<X>>,
    iterating_n<3>::is<X, F<X>, F<F<X>>>,
    iterating_n<4>::is<X, F<X>, F<F<X>>, F<F<F<X>>>>,
    iterating_n<5>::is<X, F<X>, F<F<X>>, F<F<F<X>>>, F<F<F<F<X>>>>>
{ };


int main() { }
