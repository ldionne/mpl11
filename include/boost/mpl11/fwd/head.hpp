/*!
 * @file
 * Forward declares `boost::mpl11::head`.
 */

#ifndef BOOST_MPL11_FWD_HEAD_HPP
#define BOOST_MPL11_FWD_HEAD_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the first element of a non-empty `ForwardSequence`.
     *
     * A static assertion is triggered if the sequence is empty.
     */
    template <typename S>
    struct head;

    template <typename S>
    using head_t = typename head<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_HEAD_HPP
