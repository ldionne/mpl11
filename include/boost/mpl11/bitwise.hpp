/*!
 * @file
 * Defines `boost::mpl11::Bitwise`.
 */

#ifndef BOOST_MPL11_BITWISE_HPP
#define BOOST_MPL11_BITWISE_HPP

#include <boost/mpl11/fwd/bitwise.hpp>


namespace boost { namespace mpl11 {
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

#endif // !BOOST_MPL11_BITWISE_HPP
