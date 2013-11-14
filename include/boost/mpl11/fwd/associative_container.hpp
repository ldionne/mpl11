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
     * | ----------                       | ----
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ASSOCIATIVE_CONTAINER_HPP
