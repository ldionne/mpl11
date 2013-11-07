/*!
 * @file
 * Forward declares `boost::mpl11::front`.
 */

#ifndef BOOST_MPL11_FWD_FRONT_HPP
#define BOOST_MPL11_FWD_FRONT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the first element of a `Sequence`.
     *
     * If there is no such element, i.e. if the sequence is empty, a
     * compile-time assertion is triggered.
     */
    template <typename Sequence>
    struct front;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FRONT_HPP
