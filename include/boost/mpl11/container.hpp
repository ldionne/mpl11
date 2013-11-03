/*!
 * @file
 * Defines `boost::mpl11::Container`.
 */

#ifndef BOOST_MPL11_CONTAINER_CONTAINER_HPP
#define BOOST_MPL11_CONTAINER_CONTAINER_HPP

#include <boost/mpl11/fwd/container.hpp>

#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
    struct Container : Sequence {
        //! This operation must be provided by the user.
        template <typename Seq>
        struct new_impl;

        //! This operation must be provided by the user.
        template <typename Seq>
        struct clear_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_CONTAINER_HPP
