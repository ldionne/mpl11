/*!
 * @file
 * Contains unit tests for `boost::mpl11::iterate`.
 */

#include <boost/mpl11/iterate.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/take.hpp>
#include "sequence_test.hpp"


using namespace mpl11_test;
using namespace boost::mpl11;
using detail::is_same;

struct X;
template <typename> struct F { using type = F; };

static_assert(is_same<head_t<iterate_t<quote<F>, X>>, X>::value, "");
static_assert(!is_empty<iterate_t<quote<F>, X>>::value, "");

template <unsigned long N>
struct iterating {
    template <typename ...Values>
    struct is :
        forward_sequence_test<take_c_t<N, iterate_t<quote<F>, X>>, Values...>,
        finite_sequence_test< take_c_t<N, iterate_t<quote<F>, X>>, Values...>
    { };
};

struct tests :
    iterating<1>::is<X>,
    iterating<2>::is<X, F<X>>,
    iterating<3>::is<X, F<X>, F<F<X>>>,
    iterating<4>::is<X, F<X>, F<F<X>>, F<F<F<X>>>>,
    iterating<5>::is<X, F<X>, F<F<X>>, F<F<F<X>>>, F<F<F<F<X>>>>>
{ };


int main() { }
