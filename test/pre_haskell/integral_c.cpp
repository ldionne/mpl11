/*!
 * @file
 * Contains unit tests for `boost::mpl11::integral_c`.
 */

#include <boost/mpl11/integral_c.hpp>

#include <boost/mpl11/add.hpp>
#include <boost/mpl11/and.hpp>
#include <boost/mpl11/bitand.hpp>
#include <boost/mpl11/bitor.hpp>
#include <boost/mpl11/bitxor.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/divide.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/greater.hpp>
#include <boost/mpl11/greater_equal.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/less_equal.hpp>
#include <boost/mpl11/modulo.hpp>
#include <boost/mpl11/multiply.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/not_equal.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/shift_left.hpp>
#include <boost/mpl11/shift_right.hpp>
#include <boost/mpl11/subtract.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename T, T x, T y>
class test_one {
    template <T v>
    struct abs {
        static constexpr T value = v < 0 ? -v : v;
        static_assert(value >= 0, "");
    };

    template <T v>
    struct nonzero {
        static constexpr T value = v == 0 ? v + 1 : v;
    };

#define BOOST_MPL11_CHECK_BINOP(NAME, OPERATOR)                             \
    static_assert(NAME<                                                     \
        integral_c<T, x>, integral_c<T, y>                                  \
    >::type::value == ((x) OPERATOR (y)), "");                              \
/**/

    // Arithmetic
    BOOST_MPL11_CHECK_BINOP(add, +)
    BOOST_MPL11_CHECK_BINOP(subtract, -)
    BOOST_MPL11_CHECK_BINOP(multiply, *)

    static_assert(divide<
        integral_c<T, x>, integral_c<T, nonzero<y>::value>
    >::type::value == x / nonzero<y>::value, "");

    static_assert(modulo<
        integral_c<T, x>, integral_c<T, nonzero<y>::value>
    >::type::value == x % nonzero<y>::value, "");

    // Bitwise
    static_assert(shift_left<
        integral_c<T, abs<x>::value>, integral_c<T, abs<y>::value>
    >::type::value == (abs<x>::value << abs<y>::value), "");

    static_assert(shift_right<
        integral_c<T, x>, integral_c<T, abs<y>::value>
    >::type::value == (x >> abs<y>::value), "");

    BOOST_MPL11_CHECK_BINOP(bitand_, &)
    BOOST_MPL11_CHECK_BINOP(bitor_, |)
    BOOST_MPL11_CHECK_BINOP(bitxor_, ^)

    // Comparable
    BOOST_MPL11_CHECK_BINOP(equal, ==)
    BOOST_MPL11_CHECK_BINOP(not_equal, !=)

    // Orderable
    BOOST_MPL11_CHECK_BINOP(less, <)
    BOOST_MPL11_CHECK_BINOP(less_equal, <=)
    BOOST_MPL11_CHECK_BINOP(greater, >)
    BOOST_MPL11_CHECK_BINOP(greater_equal, >=)

    // Logical
    static_assert(is_same<
        typename and_<
            identity<integral_c<T, x>>, identity<integral_c<T, y>>
        >::type,
        integral_c<T, x ? y : x>
    >::value, "");

    static_assert(is_same<
        typename and_<
            identity<integral_c<T, y>>, identity<integral_c<T, x>>
        >::type,
        integral_c<T, y ? x : y>
    >::value, "");

    static_assert(is_same<
        typename or_<
            identity<integral_c<T, x>>, identity<integral_c<T, y>>
        >::type,
        integral_c<T, x ? x : y>
    >::value, "");

    static_assert(is_same<
        typename or_<
            identity<integral_c<T, y>>, identity<integral_c<T, x>>
        >::type,
        integral_c<T, y ? y : x>
    >::value, "");

    static_assert(not_<identity<integral_c<T, x>>>::value == (!x), "");
    static_assert(not_<identity<integral_c<T, y>>>::value == (!y), "");

    template <T v>
    class nested_stuff {
        using ValueType = typename integral_c<T, v>::value_type;
        static_assert(is_same<ValueType, T>::value, "");

        static_assert(is_same<
            typename integral_c<T, v>::type, integral_c<T, v>
        >::value, "");

        static constexpr ValueType foo = integral_c<T, v>{};
        static_assert(integral_c<T, v>{} == v, "");

        static constexpr ValueType bar = integral_c<T, v>::value;
        static_assert(integral_c<T, v>::value == v, "");
    };
    static_assert(sizeof(nested_stuff<x>), "");
    static_assert(sizeof(nested_stuff<y>), "");
};

template <template <typename T, T, T> class F, typename T, T x, T y>
struct all_signs {
    static_assert(sizeof(F<T, x, y>), "");
    static_assert(sizeof(F<T, -x, y>), "");
    static_assert(sizeof(F<T, x, -y>), "");
    static_assert(sizeof(F<T, -x, -y>), "");
};

template <template <typename T, T, T> class F, typename T, T x, T y>
struct invert_inputs {
    static_assert(sizeof(F<T, x, y>), "");
    static_assert(sizeof(F<T, y, x>), "");
};

template <template <typename T, T, T> class F, typename T>
struct generate_inputs :
    invert_inputs<F, T, 0, 1>, invert_inputs<F, T, 0, 2>,
    invert_inputs<F, T, 0, 3>, invert_inputs<F, T, 0, 4>,

    invert_inputs<F, T, 1, 1>, invert_inputs<F, T, 1, 2>,
    invert_inputs<F, T, 1, 3>, invert_inputs<F, T, 1, 4>,

    invert_inputs<F, T, 2, 1>, invert_inputs<F, T, 2, 2>,
    invert_inputs<F, T, 2, 3>, invert_inputs<F, T, 2, 4>,

    invert_inputs<F, T, 3, 1>, invert_inputs<F, T, 3, 2>,
    invert_inputs<F, T, 3, 3>, invert_inputs<F, T, 3, 4>,

    invert_inputs<F, T, 4, 1>, invert_inputs<F, T, 4, 2>,
    invert_inputs<F, T, 4, 3>, invert_inputs<F, T, 4, 4>,

    invert_inputs<F, T, 5, 1>, invert_inputs<F, T, 5, 2>,
    invert_inputs<F, T, 5, 3>, invert_inputs<F, T, 5, 4>,

    invert_inputs<F, T, 6, 1>, invert_inputs<F, T, 6, 2>,
    invert_inputs<F, T, 6, 3>, invert_inputs<F, T, 6, 4>
{ };

template <typename T, T x, T y>
struct test_unsigned
    : test_one<T, x, y>
{ };

template <typename T, T x, T y>
struct test_signed
    : all_signs<test_one, T, x, y>
{ };

struct instantiate_tests :
    generate_inputs<test_signed, char>,
    generate_inputs<test_signed, short>,
    generate_inputs<test_signed, int>,
    generate_inputs<test_signed, long>,
    generate_inputs<test_signed, long long>,

    generate_inputs<test_unsigned, unsigned char>,
    generate_inputs<test_unsigned, unsigned short>,
    generate_inputs<test_unsigned, unsigned int>,
    generate_inputs<test_unsigned, unsigned long>,
    generate_inputs<test_unsigned, unsigned long long>,

    test_one<bool, true, true>,
    test_one<bool, true, false>,
    test_one<bool, false, true>,
    test_one<bool, false, false>
{ };


int main() { }
