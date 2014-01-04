/*!
 * @file
 * Contains unit tests for `boost::mpl11::repeat`.
 */

#include <boost/mpl11/repeat.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/sequence_test.hpp>
#include <boost/mpl11/take.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct X;

// head
static_assert(is_same<head_t<repeat_t<X>>, X>::value, "");

// tail
static_assert(is_same<tail_t<repeat_t<X>>, repeat_t<X>>::value, "");

// is_empty
static_assert(!is_empty<repeat_t<X>>::value, "");

// last
static_assert(is_same<last_t<repeat_t<X>>, X>::value, "");

// init
static_assert(is_same<init_t<repeat_t<X>>, repeat_t<X>>::value, "");

// at
static_assert(is_same<at_c_t<repeat_t<X>, 0>, X>::value, "");
static_assert(is_same<at_c_t<repeat_t<X>, 1>, X>::value, "");
static_assert(is_same<at_c_t<repeat_t<X>, 2>, X>::value, "");


template <unsigned long N, typename T>
struct repeating_n {
    template <typename ...Contents>
    struct is
        : detail::sequence_test<
            take_c_t<N, repeat<T>>,
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
