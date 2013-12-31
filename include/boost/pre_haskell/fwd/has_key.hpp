/*!
 * @file
 * Forward declares `boost::mpl11::has_key`.
 */

#ifndef BOOST_MPL11_FWD_HAS_KEY_HPP
#define BOOST_MPL11_FWD_HAS_KEY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns whether an `AssociativeSequence` contains one or more
     * elements with key `Key`.
     */
    template <typename Sequence, typename Key>
    struct has_key;

    template <typename Sequence, typename Key>
    using has_key_t = typename has_key<Sequence, Key>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_HAS_KEY_HPP
