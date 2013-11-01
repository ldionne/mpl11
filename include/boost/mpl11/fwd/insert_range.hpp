/*!
 * @file
 * Forward declares `boost::mpl11::insert_range`.
 */

#ifndef BOOST_MPL11_FWD_INSERT_RANGE_HPP
#define BOOST_MPL11_FWD_INSERT_RANGE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Inserts a range of elements at an arbitrary position in a container.
     */
    template <typename Container, typename Position, typename Range>
    struct insert_range;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INSERT_RANGE_HPP
