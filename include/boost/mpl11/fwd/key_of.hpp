/*!
 * @file
 * Forward declares `boost::mpl11::key_of`.
 */

#ifndef BOOST_MPL11_FWD_KEY_OF_HPP
#define BOOST_MPL11_FWD_KEY_OF_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the key that _would_ be used for an element
     * in an `AssociativeSequence`.
     */
    template <typename Seq, typename Element>
    struct key_of;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_KEY_OF_HPP
