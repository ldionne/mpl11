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
     *
     * @todo Document the left associativity of bitwise operators.
     */

    /*!
     * @ingroup concepts
     *
     * Type implementing C++ bitwise operators.
     */
    struct Bitwise {
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
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITWISE_HPP
