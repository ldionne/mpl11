/*!
 * @file
 * Defines `boost::mpl11::intrinsic::next`.
 */

#ifndef BOOST_MPL11_INTRINSIC_NEXT_HPP
#define BOOST_MPL11_INTRINSIC_NEXT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
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
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_NEXT_HPP
