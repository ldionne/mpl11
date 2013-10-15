/*!
 * @file
 * Forward declares `boost::mpl11::prior`.
 */

#ifndef BOOST_MPL11_FWD_PRIOR_HPP
#define BOOST_MPL11_FWD_PRIOR_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct prior; }

    /*!
     * @ingroup intrinsics
     *
     * Returns the previous iterator in the sequence.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - No default implementation is provided.
     */
    template <typename Iterator>
    struct prior
        : dispatch<tag::prior, Iterator>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup intrinsics
     * Returns the previous @ref IntegralConstant.
     */
    template <>
    struct prior<IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_PRIOR_HPP
