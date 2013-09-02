/*!
 * @file
 * Defines `boost::mpl11::intrinsic::prior`.
 */

#ifndef BOOST_MPL11_INTRINSIC_PRIOR_HPP
#define BOOST_MPL11_INTRINSIC_PRIOR_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
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
        : detail::tag_dispatched<tag::prior, Iterator>
    { };
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_PRIOR_HPP
