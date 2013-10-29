/*!
 * @file
 * Defines `boost::mpl11::Logical`.
 */

#ifndef BOOST_MPL11_LOGICAL_HPP
#define BOOST_MPL11_LOGICAL_HPP

#include <boost/mpl11/fwd/logical.hpp>

#include <boost/mpl11/if.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    struct Logical {
        //! This operation must be provided by the user.
        template <typename L>
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

#endif // !BOOST_MPL11_LOGICAL_HPP
