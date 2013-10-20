/*!
 * @file
 * Forward declares `boost::mpl11::next`.
 */

#ifndef BOOST_MPL11_FWD_NEXT_HPP
#define BOOST_MPL11_FWD_NEXT_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct next; }

    /*!
     * @ingroup intrinsics
     * Returns the next iterator in the sequence.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - No default implementation is provided.
     */
    template <typename Iterator>
    struct next
        : dispatch<tag::next, Iterator>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup intrinsics
     * Returns the next @ref IntegralConstant.
     */
    template <>
    struct next<IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NEXT_HPP
