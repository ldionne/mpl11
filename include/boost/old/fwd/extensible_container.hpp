/*!
 * @file
 * Forward declares `boost::mpl11::ExtensibleContainer`.
 */

#ifndef BOOST_MPL11_FWD_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_FWD_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/fwd/back_extensible_container.hpp>
#include <boost/mpl11/fwd/front_extensible_container.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `Container` supporting insertion and removal at any position.
     *
     *
     * ## Refinement of
     * `BackExtensibleContainer`, `FrontExtensibleContainer`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `C`        | An `ExtensibleContainer`
     *
     *
     * ## Valid expressions
     * | Expression                          | Type
     * | ----------                          | ----
     * | `insert<C, Pos, T>::type`           | `ExtensibleContainer`
     * | `insert_range<C, Pos, R>::type`     | `ExtensibleContainer`
     * | `erase<C, Pos>::type`               | `ExtensibleContainer`
     * | `erase_range<C, First, Last>::type` | `ExtensibleContainer`
     */
    struct ExtensibleContainer
        : FrontExtensibleContainer, BackExtensibleContainer
    {
        // We have to disambiguate.
        using BackExtensibleContainer::new_impl;

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        //! This operation must be provided by the user.
        template <typename Container, typename Position, typename Element>
        struct insert_impl;

        //! This operation must be provided by the user.
        template <typename Container, typename Position, typename Range>
        struct insert_range_impl;

        //! This operation must be provided by the user.
        template <typename Container, typename Position>
        struct erase_impl;

        //! This operation must be provided by the user.
        template <typename Container, typename First, typename Last>
        struct erase_range_impl;
#endif
    };

    /*!
     * @ingroup container_intrinsics
     *
     * Inserts a range of elements at an arbitrary position in an
     * `ExtensibleContainer`.
     */
    template <typename Container, typename Position, typename Range>
    struct insert_range;

    template <typename Container, typename Position, typename Range>
    using insert_range_t = typename insert_range<
        Container, Position, Range
    >::type;

    /*!
     * @ingroup container_intrinsics
     *
     * Removes several adjacent elements in an `ExtensibleContainer`,
     * starting from an arbitrary position.
     */
    template <typename Container, typename First, typename Last>
    struct erase_range;

    template <typename Container, typename First, typename Last>
    using erase_range_t = typename erase_range<Container, First, Last>::type;

    /*!
     * @ingroup container_intrinsics
     *
     * Removes an element at a position in an `ExtensibleContainer`.
     */
    template <typename Container, typename Position>
    struct erase;

    template <typename Container, typename Position>
    using erase_t = typename erase<Container, Position>::type;

    /*!
     * @ingroup container_intrinsics
     *
     * Inserts an element at an arbitrary position in an `ExtensibleContainer`.
     */
    template <typename Container, typename Position, typename Element>
    struct insert;

    template <typename Container, typename Position, typename Element>
    using insert_t = typename insert<Container, Position, Element>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_EXTENSIBLE_CONTAINER_HPP
