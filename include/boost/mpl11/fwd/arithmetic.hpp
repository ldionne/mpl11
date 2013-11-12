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
     *
     * @todo Document the left associativity of arithmetic operators.
     */

    /*!
     * @ingroup concepts
     *
     * Type implementing C++ arithmetic operators.
     */
    struct Arithmetic {
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
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARITHMETIC_HPP
