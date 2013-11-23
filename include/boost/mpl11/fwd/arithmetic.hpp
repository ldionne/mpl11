/*!
 * @file
 * Forward declares `boost::mpl11::Arithmetic`.
 */

#ifndef BOOST_MPL11_FWD_ARITHMETIC_HPP
#define BOOST_MPL11_FWD_ARITHMETIC_HPP

namespace boost { namespace mpl11 {
    /*!
     * @defgroup arithmetic_operators Arithmetic operators
     * @ingroup intrinsics
     *
     * Intrinsics representing C++ arithmetic operators.
     *
     * Arithmetic operators can be passed more than two arguments. Like in
     * standard C++, these operators are left-associative. Therefore, the
     * following are equivalent:
     *
            op<A0, A1, A2, ..., An>
     *
     * and
     *
            op<op<A0, A1>::type, A2, ..., An>
     *
     * where `op` is any arithmetic operator.
     */

    /*!
     * @ingroup concepts
     *
     * %Type implementing C++ arithmetic operators.
     */
    struct Arithmetic {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct add_impl;

        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct substract_impl;

        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct modulo_impl;

        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct divide_impl;

        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct multiply_impl;
#endif
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARITHMETIC_HPP
