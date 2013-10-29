/*!
 * @file
 * Defines `boost::mpl11::Arithmetic`.
 */

#ifndef BOOST_MPL11_ARITHMETIC_HPP
#define BOOST_MPL11_ARITHMETIC_HPP

#include <boost/mpl11/fwd/arithmetic.hpp>


namespace boost { namespace mpl11 {
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

#endif // !BOOST_MPL11_ARITHMETIC_HPP
