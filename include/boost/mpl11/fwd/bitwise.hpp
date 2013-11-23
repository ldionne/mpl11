/*!
 * @file
 * Forward declares `boost::mpl11::Bitwise`.
 */

#ifndef BOOST_MPL11_FWD_BITWISE_HPP
#define BOOST_MPL11_FWD_BITWISE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @defgroup bitwise_operators Bitwise operators
     * @ingroup intrinsics
     *
     * Intrinsics representing C++ bitwise operators.
     *
     * Bitwise operators can be passed more than two arguments. Like in
     * standard C++, these operators are left-associative. Therefore, the
     * following are equivalent:
     *
            op<A0, A1, A2, ..., An>
     *
     * and
     *
            op<op<A0, A1>::type, A2, ..., An>
     *
     * where `op` is any bitwise operator.
     */

    /*!
     * @ingroup concepts
     *
     * %Type implementing C++ bitwise operators.
     */
    struct Bitwise {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct shift_left_impl;

        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct shift_right_impl;

        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct bitor_impl;

        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct bitand_impl;

        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct bitxor_impl;
#endif
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITWISE_HPP
