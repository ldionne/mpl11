/*!
 * @file
 * Forward declares `boost::mpl11::BackExtensibleContainer`.
 */

#ifndef BOOST_MPL11_FWD_BACK_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_FWD_BACK_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `Container` supporting insertion and removal at the end.
     *
     *
     * ## Refinement of
     * `Container`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `C`        | A `BackExtensibleContainer`
     * | `T`        | Any type
     *
     *
     * ## Valid expressions
     * | Expression              | Type
     * | ----------              | ----
     * | `pop_back<C>::type`     | `BackExtensibleContainer`
     * | `push_back<C, T>::type` | `BackExtensibleContainer`
     */
    struct BackExtensibleContainer BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BACK_EXTENSIBLE_CONTAINER_HPP
