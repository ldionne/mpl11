/*!
 * @file
 * Forward declares `boost::mpl11::erase_range`.
 */

#ifndef BOOST_MPL11_FWD_ERASE_RANGE_HPP
#define BOOST_MPL11_FWD_ERASE_RANGE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Removes several adjacent elements in a `RandomExtensibleContainer`,
     * starting from an arbitrary position.
     */
    template <typename Container, typename First, typename Last>
    struct erase_range;

    template <typename Container, typename First, typename Last>
    using erase_range_t = typename erase_range<Container, First, Last>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ERASE_RANGE_HPP
