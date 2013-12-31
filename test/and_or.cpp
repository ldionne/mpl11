/*!
 * @file
 * Contains unit tests for `boost::mpl11::and_` and `boost::mpl11::or_`.
 */

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/or.hpp>

#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;

template <typename T, typename F>
struct test_one {
    struct invalid;

    // test and_
    static_assert( and_<>::value, "");

    static_assert( and_<T>::value, "");
    static_assert(!and_<F>::value, "");

    static_assert( and_<T, T>::value, "");
    static_assert(!and_<T, F>::value, "");
    static_assert(!and_<F, T>::value, "");
    static_assert(!and_<F, F>::value, "");
    static_assert(!and_<F, invalid>::value, "");

    static_assert( and_<T, T, T>::value, "");
    static_assert(!and_<T, T, F>::value, "");
    static_assert(!and_<T, F, T>::value, "");
    static_assert(!and_<T, F, F>::value, "");
    static_assert(!and_<F, T, T>::value, "");
    static_assert(!and_<F, T, F>::value, "");
    static_assert(!and_<F, F, T>::value, "");
    static_assert(!and_<F, F, F>::value, "");
    static_assert(!and_<T, F, invalid>::value, "");
    static_assert(!and_<F, T, invalid>::value, "");
    static_assert(!and_<F, F, invalid>::value, "");


    // test or_
    static_assert(!or_<>::value, "");

    static_assert( or_<T>::value, "");
    static_assert(!or_<F>::value, "");

    static_assert( or_<T, T>::value, "");
    static_assert( or_<T, F>::value, "");
    static_assert( or_<F, T>::value, "");
    static_assert(!or_<F, F>::value, "");
    static_assert( or_<T, invalid>::value, "");

    static_assert( or_<T, T, T>::value, "");
    static_assert( or_<T, T, F>::value, "");
    static_assert( or_<T, F, T>::value, "");
    static_assert( or_<T, F, F>::value, "");
    static_assert( or_<F, T, T>::value, "");
    static_assert( or_<F, T, F>::value, "");
    static_assert( or_<F, F, T>::value, "");
    static_assert(!or_<F, F, F>::value, "");
    static_assert( or_<T, F, invalid>::value, "");
    static_assert( or_<F, T, invalid>::value, "");
    static_assert( or_<T, T, invalid>::value, "");
};

template <typename T, T v>
struct yes { struct type { static constexpr T value = v; }; };
struct no { struct type { static constexpr bool value = false; }; };

struct tests :
    test_one<yes<bool, true>, no>,
    test_one<yes<int, 1>, no>,
    test_one<yes<int, 2>, no>,

    // test integral_c specialization
    test_one<true_, false_>,
    test_one<int_<2>, false_>,
    test_one<int_<2>, int_<0>>,
    test_one<int_<2>, long_<0>>
{ };


int main() { }
