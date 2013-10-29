/*!
 * @file
 * Forward declares `boost::mpl11::size`.
 */

#ifndef BOOST_MPL11_FWD_SIZE_HPP
#define BOOST_MPL11_FWD_SIZE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup iterable_intrinsics
     *
     * Returns the number of elements contained in an `Iterable`.
     *
     * The size of a sequence is a non-negative `IntegralConstant`.
     */
    template <typename I>
    struct size;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SIZE_HPP
