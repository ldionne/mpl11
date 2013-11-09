/*!
 * @file
 * Forward declares `boost::mpl11::count_if`.
 */

#ifndef BOOST_MPL11_FWD_COUNT_IF_HPP
#define BOOST_MPL11_FWD_COUNT_IF_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns the number of elements in a `Sequence` satisfying `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `foldl<Sequence, ulong<0>, Count>`, where `Count` is
     * a @ref MetafunctionClass incrementing the counter if `Predicate`
     * is satisfied for that element.
     */
    template <typename Sequence, typename Predicate>
    struct count_if;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COUNT_IF_HPP
