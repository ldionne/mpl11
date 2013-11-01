/*!
 * @file
 * Defines `boost::mpl11::FrontExtensibleContainer`.
 */

#ifndef BOOST_MPL11_FRONT_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_FRONT_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/fwd/front_extensible_container.hpp>

#include <boost/mpl11/container.hpp>


namespace boost { namespace mpl11 {
    struct FrontExtensibleContainer : Container {
        //! This operation must be provided by the user.
        template <typename Seq>
        struct pop_front_impl;

        //! This operation must be provided by the user.
        template <typename Seq, typename T>
        struct push_front_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FRONT_EXTENSIBLE_CONTAINER_HPP
