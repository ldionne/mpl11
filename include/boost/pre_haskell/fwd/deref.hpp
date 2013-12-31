/*!
 * @file
 * Forward declares `boost::mpl11::deref`.
 */

#ifndef BOOST_MPL11_FWD_DEREF_HPP
#define BOOST_MPL11_FWD_DEREF_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup iterator_intrinsics
     *
     * Returns the element pointed to by an iterator.
     */
    template <typename Iterator>
    struct deref;

    template <typename Iterator>
    using deref_t = typename deref<Iterator>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DEREF_HPP
