/*!
 * @file
 * Forward declares `boost::mpl11::less_equal`.
 */

#ifndef BOOST_MPL11_FWD_LESS_EQUAL_HPP
#define BOOST_MPL11_FWD_LESS_EQUAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup comparison_operators
     *
     * Returns `T1 <= T2 <= ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct less_equal;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LESS_EQUAL_HPP
