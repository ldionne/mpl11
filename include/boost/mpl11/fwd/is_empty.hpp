/*!
 * @file
 * Forward declares `boost::mpl11::is_empty`.
 */

#ifndef BOOST_MPL11_FWD_IS_EMPTY_HPP
#define BOOST_MPL11_FWD_IS_EMPTY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns whether a @ref ForwardSequence is empty.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `equal_to<begin<Sequence>::type, end<Sequence>::type>`.
     *
     *
     * @warning
     * This algorithm replaces the `mpl::empty` intrinsic from the
     * original MPL.
     */
    template <typename Sequence>
    struct is_empty;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IS_EMPTY_HPP
