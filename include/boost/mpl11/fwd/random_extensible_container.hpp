/*!
 * @file
 * Forward declares `boost::mpl11::RandomExtensibleContainer`.
 */

#ifndef BOOST_MPL11_FWD_RANDOM_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_FWD_RANDOM_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


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
     * | `C`        | A `RandomExtensibleContainer`
     *
     *
     * ## Valid expressions
     * | Expression                          | Type
     * | ----------                          | ----
     * | `mpl11::insert<C, Pos, T>::type`    | `RandomExtensibleContainer`
     * | `insert_range<C, Pos, R>::type`     | `RandomExtensibleContainer`
     * | `mpl11::erase<C, Pos>::type`        | `RandomExtensibleContainer`
     * | `erase_range<C, First, Last>::type` | `RandomExtensibleContainer`
     */
    struct RandomExtensibleContainer BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_RANDOM_EXTENSIBLE_CONTAINER_HPP
