/*!
 * @file
 * Defines `boost::mpl11::detail::test_integral_constant`.
 */

#ifndef BOOST_MPL11_DETAIL_TEST_INTEGRAL_CONSTANT_HPP
#define BOOST_MPL11_DETAIL_TEST_INTEGRAL_CONSTANT_HPP

#include <boost/mpl11/add.hpp>
#include <boost/mpl11/bitand.hpp>
#include <boost/mpl11/bitor.hpp>
#include <boost/mpl11/bitxor.hpp>
#include <boost/mpl11/detail/bool_cast.hpp>
#include <boost/mpl11/detail/test_boolean.hpp>
#include <boost/mpl11/detail/test_value.hpp>
#include <boost/mpl11/divide.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/greater.hpp>
#include <boost/mpl11/greater_equal.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/less_equal.hpp>
#include <boost/mpl11/modulo.hpp>
#include <boost/mpl11/multiply.hpp>
#include <boost/mpl11/not_equal.hpp>
#include <boost/mpl11/shift_left.hpp>
#include <boost/mpl11/shift_right.hpp>
#include <boost/mpl11/substract.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Generic unit test for `IntegralConstant`s.
     */
    template <template <typename T, T v> class integral_constant>
    class test_integral_constant {
        template <typename T>
        struct test_one {

#define BOOST_MPL11_CHECK_ARITHMETIC(NAME, OPERATOR, I, J)                  \
    static_assert(NAME<                                                     \
        integral_constant<T, (I)>, integral_constant<T, (J)>                \
    >::type::value == ((I) OPERATOR (J)), "");                              \
/**/

#define BOOST_MPL11_CHECK_COMPARISON(NAME, OPERATOR, I, J)                  \
    static_assert(bool_cast<typename NAME<                                  \
        integral_constant<T, (I)>, integral_constant<T, (J)>                \
    >::type>::value == ((I) OPERATOR (J)), "");                             \
/**/

#define BOOST_MPL11_CHECK_BINOP_IMPL(NAME, OPERATOR, STATIC_ASSERT)         \
    STATIC_ASSERT(NAME, OPERATOR, 0, 1)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 0, 2)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 0, 3)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 0, 4)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 1, 1)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 1, 2)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 1, 3)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 1, 4)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 2, 1)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 2, 2)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 2, 3)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 2, 4)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 3, 1)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 3, 2)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 3, 3)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 3, 4)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 4, 1)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 4, 2)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 4, 3)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 4, 4)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 5, 1)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 5, 2)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 5, 3)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 5, 4)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 6, 1)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 6, 2)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 6, 3)                                     \
    STATIC_ASSERT(NAME, OPERATOR, 6, 4)                                     \
/**/

#define BOOST_MPL11_CHECK_BINOP(NAME, OPERATOR) \
    BOOST_MPL11_CHECK_BINOP_IMPL(NAME, OPERATOR, BOOST_MPL11_CHECK_ARITHMETIC)

            // Arithmetic
            BOOST_MPL11_CHECK_BINOP(add, +)
            BOOST_MPL11_CHECK_BINOP(substract, -)
            BOOST_MPL11_CHECK_BINOP(multiply, *)
            BOOST_MPL11_CHECK_BINOP(divide, /)
            BOOST_MPL11_CHECK_BINOP(modulo, %)

            // Bitwise
            BOOST_MPL11_CHECK_BINOP(shift_left, <<)
            BOOST_MPL11_CHECK_BINOP(shift_right, >>)
            BOOST_MPL11_CHECK_BINOP(bitand_, &)
            BOOST_MPL11_CHECK_BINOP(bitor_, |)
            BOOST_MPL11_CHECK_BINOP(bitxor_, ^)

#undef BOOST_MPL11_CHECK_BINOP
#define BOOST_MPL11_CHECK_BINOP(NAME, OPERATOR) \
    BOOST_MPL11_CHECK_BINOP_IMPL(NAME, OPERATOR, BOOST_MPL11_CHECK_COMPARISON)

            // Comparable
            BOOST_MPL11_CHECK_BINOP(equal, ==)
            BOOST_MPL11_CHECK_BINOP(not_equal, !=)

            // Orderable
            BOOST_MPL11_CHECK_BINOP(less, <)
            BOOST_MPL11_CHECK_BINOP(less_equal, <=)
            BOOST_MPL11_CHECK_BINOP(greater, >)
            BOOST_MPL11_CHECK_BINOP(greater_equal, >=)

#undef BOOST_MPL11_CHECK_BINOP
#undef BOOST_MPL11_CHECK_BINOP_IMPL
#undef BOOST_MPL11_CHECK_COMPARISON
#undef BOOST_MPL11_CHECK_ARITHMETIC

            // Boolean
            struct check_boolean :
                test_boolean<integral_constant<T, 1>, integral_constant<T, 0>>,
                test_boolean<integral_constant<T, 2>, integral_constant<T, 0>>,
                test_boolean<integral_constant<T, 3>, integral_constant<T, 0>>
            { };
            static_assert(sizeof(check_boolean), "");

            // Value
            struct check_value :
                test_value<integral_constant<T, 0>>,
                test_value<integral_constant<T, 1>>,
                test_value<integral_constant<T, 2>>
            { };
            static_assert(sizeof(check_value), "");
        };

        struct instantiate :
            test_one<char>,
            test_one<short>,
            test_one<int>,
            test_one<long>,
            test_one<long long>,

            test_one<unsigned char>,
            test_one<unsigned short>,
            test_one<unsigned int>,
            test_one<unsigned long>,
            test_one<unsigned long long>
        { };

        // Instantiate the tests.
        static_assert(sizeof(instantiate), "");
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_INTEGRAL_CONSTANT_HPP
