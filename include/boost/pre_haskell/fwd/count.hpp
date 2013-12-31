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
     * Returns the number of elements in a `Sequence` that are equal
     * to `Element`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `count_if<%Sequence, partial<quote<equal>, Element>>`.
     */
    template <typename Sequence, typename Element>
    struct count;

    template <typename Sequence, typename Element>
    using count_t = typename count<Sequence, Element>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COUNT_HPP
