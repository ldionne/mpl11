/*!
 * @file
 * Forward declares `boost::mpl11::begin`.
 */

#ifndef BOOST_MPL11_FWD_BEGIN_HPP
#define BOOST_MPL11_FWD_BEGIN_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct begin; }

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

#endif // !BOOST_MPL11_FWD_BEGIN_HPP
