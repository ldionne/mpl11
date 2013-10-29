/*!
 * @file
 * Defines `boost::mpl11::Boolean`.
 */

#ifndef BOOST_MPL11_BOOLEAN_HPP
#define BOOST_MPL11_BOOLEAN_HPP

#include <boost/mpl11/fwd/boolean.hpp>

#include <boost/mpl11/if.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    struct Boolean {
        //! This operation must be provided by the user.
        template <typename B>
        struct not_impl;

        /*!
         * Returns `A::type` if `not_<A>::type` is `true_` and
         * `B::type` otherwise.
         */
        template <typename A, typename B>
        struct and_impl
            : if_<typename not_<A>::type, A, B>::type
        { };

        /*!
         * Returns `B::type` if `not_<A>::type` is `true_` and
         * `A::type` otherwise.
         */
        template <typename A, typename B>
        struct or_impl
            : if_<typename not_<A>::type, B, A>::type
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BOOLEAN_HPP
