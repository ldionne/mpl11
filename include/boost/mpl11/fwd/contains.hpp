/*!
 * @file
 * Forward declares `boost::mpl11::contains`.
 */

#ifndef BOOST_MPL11_FWD_CONTAINS_HPP
#define BOOST_MPL11_FWD_CONTAINS_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns whether a `Sequence` contains one or more elements equal
     * to `Element`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `any_of<%Sequence, lambda<equal<_1, Element>>>`.
     */
    template <typename Sequence, typename Element>
    struct contains;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CONTAINS_HPP