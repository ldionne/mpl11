/*!
 * @file
 * Forward declares `boost::mpl11::AssociativeContainer`.
 */

#ifndef BOOST_MPL11_FWD_ASSOCIATIVE_CONTAINER_HPP
#define BOOST_MPL11_FWD_ASSOCIATIVE_CONTAINER_HPP

#include <boost/mpl11/fwd/container.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `Container` supporting insertion and removal of elements based on keys.
     *
     *
     * ## Refinement of
     * `Container`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `C`        | An `AssociativeContainer`
     * | `Element`  | An element of `C`
     * | `Elements` | A `Sequence` of elements of `C`
     * | `Key`      | Any type
     * | `Keys`     | A `Sequence` of arbitrary types
     *
     *
     * ## Valid expressions
     * | Expression                       | %Type
     * | ----------                       | -----
     * | `insert_key<C, Element>::type`   | `AssociativeContainer`
     * | `insert_keys<C, Elements>::type` | `AssociativeContainer`
     * | `erase_key<C, Key>::type`        | `AssociativeContainer`
     * | `erase_keys<C, Keys>::type`      | `AssociativeContainer`
     *
     *
     * @todo
     * Write unit test for operations with defaults.
     */
    struct AssociativeContainer : Container {

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        //! This operation must be provided by the user.
        template <typename Container, typename Element>
        struct insert_key_impl;

        //! This operation must be provided by the user.
        template <typename Container, typename Key>
        struct erase_key_impl;
#endif

        //! Inserts each element using `insert_key`.
        template <typename Container, typename Elements>
        struct insert_keys_impl;

        //! Erases each key using `erase_key`.
        template <typename Container, typename Keys>
        struct erase_keys_impl;
    };

    /*!
     * @ingroup container_intrinsics
     *
     * Removes the given `Key` from an `AssociativeContainer`.
     */
    template <typename Container, typename Key>
    struct erase_key;

    template <typename Container, typename Key>
    using erase_key_t = typename erase_key<Container, Key>::type;

    /*!
     * @ingroup container_intrinsics
     *
     * Removes a `Sequence` of keys from an `AssociativeContainer`.
     */
    template <typename Container, typename Keys>
    struct erase_keys;

    template <typename Container, typename Keys>
    using erase_keys_t = typename erase_keys<Container, Keys>::type;

    /*!
     * @ingroup container_intrinsics
     *
     * Inserts an element in an `AssociativeContainer`.
     */
    template <typename Container, typename Element>
    struct insert_key;

    template <typename Container, typename Element>
    using insert_key_t = typename insert_key<Container, Element>::type;

    /*!
     * @ingroup container_intrinsics
     *
     * Inserts a `Sequence` of elements in an `AssociativeContainer`.
     */
    template <typename Container, typename Elements>
    struct insert_keys;

    template <typename Container, typename Elements>
    using insert_keys_t = typename insert_keys<Container, Elements>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ASSOCIATIVE_CONTAINER_HPP
