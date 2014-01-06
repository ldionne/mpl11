/*!
 * @file
 * Forward declares `boost::mpl11::Container`.
 */

#ifndef BOOST_MPL11_FWD_CONTAINER_HPP
#define BOOST_MPL11_FWD_CONTAINER_HPP

#include <boost/mpl11/fwd/sequence.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @defgroup containers Containers
     * @ingroup sequences
     *
     * Mutable sequences.
     */

    /*!
     * @defgroup container_intrinsics Container intrinsics
     * @ingroup sequence_intrinsics
     *
     * Intrinsics forming the essential interface of containers.
     */

    /*!
     * @ingroup concepts
     *
     * `Sequence` supporting basic mutation.
     *
     *
     * ## Refinement of
     * `Sequence`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `C`        | A `Container`
     *
     *
     * ## Valid expressions
     * | Expression       | %Type
     * | ----------       | -----
     * | `new_<C>`        | `MetafunctionClass`
     * | `clear<C>::type` | `Container`
     */
    struct Container : Sequence {

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        //! This operation must be provided by the user.
        template <typename Container>
        struct new_impl;

        //! This operation must be provided by the user.
        template <typename Container>
        struct clear_impl;
#endif

    };

    /*!
     * @ingroup container_intrinsics
     *
     * Erases all the elements of a `Container`.
     */
    template <typename Container>
    struct clear;

    template <typename Container>
    using clear_t = typename clear<Container>::type;

    /*!
     * @ingroup metafunction_classes
     * @ingroup container_intrinsics
     *
     * `MetafunctionClass` creating a `Container` from the `Sequence`
     * passed to it.
     */
    template <typename Container>
    struct new_;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CONTAINER_HPP
