/*!
 * @file
 * Defines `boost::mpl11::RandomExtensibleContainer`.
 */

#ifndef BOOST_MPL11_RANDOM_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_RANDOM_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/fwd/random_extensible_container.hpp>

#include <boost/mpl11/back_extensible_container.hpp>
#include <boost/mpl11/front_extensible_container.hpp>


namespace boost { namespace mpl11 {
    struct RandomExtensibleContainer
        : FrontExtensibleContainer, BackExtensibleContainer
    {
        // We have to disambiguate.
        using BackExtensibleContainer::new_impl;

        //! This operation must be provided by the user.
        template <typename Seq, typename Pos, typename Element>
        struct insert_impl;

        //! This operation must be provided by the user.
        template <typename Seq, typename Pos, typename Range>
        struct insert_range_impl;

        //! This operation must be provided by the user.
        template <typename Seq, typename Pos>
        struct erase_impl;

        //! This operation must be provided by the user.
        template <typename Seq, typename First, typename Last>
        struct erase_range_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RANDOM_EXTENSIBLE_CONTAINER_HPP
