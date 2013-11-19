/*!
 * @file
 * Forward declares `boost::mpl11::find`.
 */

#ifndef BOOST_MPL11_FWD_FIND_HPP
#define BOOST_MPL11_FWD_FIND_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns an iterator to the first occurence of a given element in a
     * `Sequence`, or the past-the-end iterator if no such element exists.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `find_if<%Sequence, lambda<equal<Element, _1>>>`.
     */
    template <typename Sequence, typename Element>
    struct find;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FIND_HPP
