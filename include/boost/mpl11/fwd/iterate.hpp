/*!
 * @file
 * Forward declares `boost::mpl11::iterate`.
 */

#ifndef BOOST_MPL11_FWD_ITERATE_HPP
#define BOOST_MPL11_FWD_ITERATE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     *
     * Infinite `ForwardSequence` containing repeated applications of a
     * metafunction class to an initial argument.
     */
    template <typename F, typename X>
    struct iterate;

    template <typename F, typename X>
    using iterate_t = iterate<F, X>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ITERATE_HPP
