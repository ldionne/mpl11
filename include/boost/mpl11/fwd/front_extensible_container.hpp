/*!
 * @file
 * Forward declares `boost::mpl11::FrontExtensibleContainer`.
 */

#ifndef BOOST_MPL11_FWD_FRONT_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_FWD_FRONT_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


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
    struct FrontExtensibleContainer BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FRONT_EXTENSIBLE_CONTAINER_HPP
