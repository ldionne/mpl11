/*!
 * @file
 * Defines `boost::mpl11::begin`.
 */

#ifndef BOOST_MPL11_INTRINSIC_BEGIN_HPP
#define BOOST_MPL11_INTRINSIC_BEGIN_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns an iterator pointing to the first element of the sequence.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - If `Sequence` is not a @ref ForwardSequence, `begin<Sequence>::type`
     *   is invalid instead of being the same as `mpl::void_`.
     * - No default implementation is provided.
     */
    template <typename Sequence>
    struct begin
        : dispatch<tag::begin, Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_BEGIN_HPP
