/*!
 * @file
 * Forward declares `boost::mpl11::scanl`.
 */

#ifndef BOOST_MPL11_FWD_SCANL_HPP
#define BOOST_MPL11_FWD_SCANL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * `scanl` is similar to `foldl`, but returns a `Sequence` of successive
     * reduced values from the left.
     */
    template <typename F, typename State, typename Sequence>
    struct scanl;

    template <typename F, typename State, typename Sequence>
    using scanl_t = scanl<F, State, Sequence>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SCANL_HPP
