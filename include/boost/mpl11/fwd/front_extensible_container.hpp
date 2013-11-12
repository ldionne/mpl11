/*!
 * @file
 * Forward declares `boost::mpl11::FrontExtensibleContainer`.
 */

#ifndef BOOST_MPL11_FWD_FRONT_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_FWD_FRONT_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/fwd/container.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `Container` supporting insertion and removal at the beginning.
     *
     *
     * ## Refinement of
     * `Container`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `C`        | A `FrontExtensibleContainer`
     * | `T`        | Any type
     *
     *
     * ## Valid expressions
     * | Expression               | Type
     * | ----------               | ----
     * | `pop_front<C>::type`     | `FrontExtensibleContainer`
     * | `push_front<C, T>::type` | `FrontExtensibleContainer`
     */
    struct FrontExtensibleContainer : Container {
        //! This operation must be provided by the user.
        template <typename Container>
        struct pop_front_impl;

        //! This operation must be provided by the user.
        template <typename Container, typename T>
        struct push_front_impl;

        /*!
         * Uses `push_front` repeatedly on `clear<%Container>::type`
         * to create a new container.
         */
        template <typename Container>
        struct new_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FRONT_EXTENSIBLE_CONTAINER_HPP
