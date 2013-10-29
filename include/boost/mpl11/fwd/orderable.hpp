/*!
 * @file
 * Forward declares `boost::mpl11::Orderable`.
 */

#ifndef BOOST_MPL11_FWD_ORDERABLE_HPP
#define BOOST_MPL11_FWD_ORDERABLE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup mixins
     *
     * Type possessing a strict weak partial ordering relation.
     *
     *
     * ## Notation
     * | Expression      | Description
     * | ----------      | -----------
     * | `A0`, ..., `An` | Compatible `Orderable`s
     *
     *
     * ## Valid expressions
     * | Expression                          | Type
     * | ----------                          | ----
     * | `mpl11::less<A0, ..., An>`          | Boolean `IntegralConstant`
     * | `mpl11::less_equal<A0, ..., An>`    | Boolean `IntegralConstant`
     * | `mpl11::greater<A0, ..., An>`       | Boolean `IntegralConstant`
     * | `mpl11::greater_equal<A0, ..., An>` | Boolean `IntegralConstant`
     */
    struct Orderable BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ORDERABLE_HPP
