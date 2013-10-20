/*!
 * @file
 * Forward declares `boost::mpl11::end`.
 */

#ifndef BOOST_MPL11_FWD_END_HPP
#define BOOST_MPL11_FWD_END_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct end; }

    /*!
     * @ingroup intrinsics
     *
     * Returns the past-the-end iterator of the sequence.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - If `Sequence` is not a @ref ForwardSequence, `end<Sequence>::type`
     *   is invalid instead of being the same as `mpl::void_`.
     * - There is no default implementation.
     */
    template <typename Sequence>
    struct end
        : dispatch<tag::end, Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_END_HPP
