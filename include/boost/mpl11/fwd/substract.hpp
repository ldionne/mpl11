/*!
 * @file
 * Forward declares `boost::mpl11::substract`.
 */

#ifndef BOOST_MPL11_FWD_SUBSTRACT_HPP
#define BOOST_MPL11_FWD_SUBSTRACT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns `T1 - T2 - ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct substract;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SUBSTRACT_HPP
