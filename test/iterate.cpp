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

template <typename> struct R { using type = R; };
struct X { struct type; };
template <typename T> struct F { using type = R<typename T::type>; };

// head
static_assert(is_same<head_t<iterate<quote<F>, X>>, X::type>::value, "");

// is_empty
static_assert(!is_empty<iterate<quote<F>, X>>::value, "");


template <unsigned long N>
struct iterating_n {
    template <typename ...Values>
    struct is
        : detail::iterable_test<
            take_c<N, iterate<quote<F>, X>>,
            Values...
        >
    { };
};

struct tests :
    iterating_n<1>::is<X>,
    iterating_n<2>::is<X, R<X::type>>,
    iterating_n<3>::is<X, R<X::type>, R<R<X::type>>>,
    iterating_n<4>::is<X, R<X::type>, R<R<X::type>>, R<R<R<X::type>>>>,
    iterating_n<5>::is<X, R<X::type>, R<R<X::type>>, R<R<R<X::type>>>, R<R<R<R<X::type>>>>>
{ };


int main() { }
