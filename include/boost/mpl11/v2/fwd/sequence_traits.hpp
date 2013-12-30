/*!
 * @file
 * Forward declares `boost::mpl11::sequence_traits`.
 */

#ifndef BOOST_MPL11_FWD_SEQUENCE_TRAITS_HPP
#define BOOST_MPL11_FWD_SEQUENCE_TRAITS_HPP

namespace boost { namespace mpl11 {
    /*!
     * Traits providing additional information about the given sequence.
     *
     * Specifically, these traits provide optional information that can be
     * used by the library to perform optimizations or to enable features
     * that are only usable with some types of sequences.
     */
    template <typename S>
    struct sequence_traits;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SEQUENCE_TRAITS_HPP
