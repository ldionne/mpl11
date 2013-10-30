/*!
 * @file
 * Forward declares `boost::mpl11::Hashable`.
 */

#ifndef BOOST_MPL11_FWD_HASHABLE_HPP
#define BOOST_MPL11_FWD_HASHABLE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * Type from which it is possible to extract a hash.
     *
     *
     * ## Refinement of
     * `Comparable`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `H`        | A `Hashable`
     *
     *
     * ## Valid expressions
     * | Expression      | Type
     * | ----------      | ----
     * | `hash<H>::type` | Any type
     */
    struct Hashable BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_HASHABLE_HPP
