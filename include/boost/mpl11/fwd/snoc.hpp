/*!
 * @file
 * Forward declares `boost::mpl11::snoc`.
 */

#ifndef BOOST_MPL11_FWD_SNOC_HPP
#define BOOST_MPL11_FWD_SNOC_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Appends an element to a `Sequence`.
     *
     *
     * @todo
     * If the sequence is infinite, `snoc` could be `id`.
     */
    template <typename Sequence, typename Element>
    struct snoc;

    template <typename Sequence, typename Element>
    using snoc_t = typename snoc<Sequence, Element>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SNOC_HPP
