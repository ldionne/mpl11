/*!
 * @file
 * Forward declares `boost::mpl11::flip`.
 */

#ifndef BOOST_MPL11_FWD_FLIP_HPP
#define BOOST_MPL11_FWD_FLIP_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * Invokes another metafunction class with its two first arguments
     * in reverse order.
     *
     * Specifically, `apply<flip<F>, A0, A1, A2, ..., An>` is
     * equivalent to `apply<F, A1, A0, A2, ..., An>`.
     */
    template <typename F>
    struct flip;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FLIP_HPP
