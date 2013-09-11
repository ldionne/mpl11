/*!
 * @file
 * Defines `boost::mpl11::prior`.
 */

#ifndef BOOST_MPL11_INTRINSIC_PRIOR_HPP
#define BOOST_MPL11_INTRINSIC_PRIOR_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_PRIOR_HPP
