/*!
 * @file
 * Forward declares `boost::mpl11::divide`.
 */

#ifndef BOOST_MPL11_FWD_DIVIDE_HPP
#define BOOST_MPL11_FWD_DIVIDE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns `T1 / T2 / ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct divide;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DIVIDE_HPP
