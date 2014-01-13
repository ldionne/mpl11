/*!
 * @file
 * Contains unit tests for `boost::mpl11::repeat`.
 */

#include <boost/mpl11/iterable/repeat.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/iterable_test.hpp>
#include <boost/mpl11/iterable/take.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct X { struct type; };

// head
static_assert(is_same<head_t<repeat<X>>, X::type>::value, "");

// is_empty
static_assert(!is_empty<repeat<X>>::value, "");

// last
static_assert(is_same<last_t<repeat<X>>, X::type>::value, "");

// at
static_assert(is_same<at_c_t<repeat<X>, 0>, X::type>::value, "");
static_assert(is_same<at_c_t<repeat<X>, 1>, X::type>::value, "");
static_assert(is_same<at_c_t<repeat<X>, 2>, X::type>::value, "");


template <unsigned long N, typename T>
struct repeating_n {
    template <typename ...Contents>
    struct is
        : detail::iterable_test<
            take_c<N, repeat<T>>,
            Contents...
        >
    { };
};

struct finite_tests :
    repeating_n<0, X>::is<>,
    repeating_n<1, X>::is<X>,
    repeating_n<2, X>::is<X, X>,
    repeating_n<3, X>::is<X, X, X>,
    repeating_n<4, X>::is<X, X, X, X>,
    repeating_n<5, X>::is<X, X, X, X, X>
{ };


int main() { }
