/*!
 * @file
 * Forward declares `boost::mpl11::Container`.
 */

#ifndef BOOST_MPL11_FWD_CONTAINER_HPP
#define BOOST_MPL11_FWD_CONTAINER_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


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
     * | Expression       | Type
     * | ----------       | ----
     * | `new_<C>`        | @ref MetafunctionClass
     * | `clear<C>::type` | `Container`
     *
     *
     * @todo
     * Change the name of most *_impl metafunctions from Seq
     * to something better.
     */
    struct Container BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CONTAINER_HPP
