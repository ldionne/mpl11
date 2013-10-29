/*!
 * @file
 * Forward declares `boost::mpl11::count`.
 */

#ifndef BOOST_MPL11_FWD_COUNT_HPP
#define BOOST_MPL11_FWD_COUNT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns the number of elements in `Sequence` that are identical
     * to `Element`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `count_if<Sequence, equal_to<Element, _1>>`.
     */
    template <typename Sequence, typename Element>
    struct count;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COUNT_HPP
