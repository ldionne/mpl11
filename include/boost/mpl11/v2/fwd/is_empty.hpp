/*!
 * @file
 * Forward declares `boost::mpl11::is_empty`.
 */

#ifndef BOOST_MPL11_FWD_IS_EMPTY_HPP
#define BOOST_MPL11_FWD_IS_EMPTY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup ForwardSequence
     * @ingroup methods
     *
     * Boolean `Integral` representing whether the given `ForwardSequence`
     * is empty.
     */
    template <typename S>
    struct is_empty;

    template <typename S>
    using is_empty_t = typename is_empty<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IS_EMPTY_HPP
