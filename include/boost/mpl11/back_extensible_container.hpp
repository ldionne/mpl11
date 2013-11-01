/*!
 * @file
 * Defines `boost::mpl11::BackExtensibleContainer`.
 */

#ifndef BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/fwd/back_extensible_container.hpp>

#include <boost/mpl11/container.hpp>


namespace boost { namespace mpl11 {
    struct BackExtensibleContainer : Container {
        //! This operation must be provided by the user.
        template <typename Seq>
        struct pop_back_impl;

        //! This operation must be provided by the user.
        template <typename Seq, typename T>
        struct push_back_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP
