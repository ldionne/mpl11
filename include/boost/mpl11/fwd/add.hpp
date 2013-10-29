/*!
 * @file
 * Forward declares `boost::mpl11::add`.
 */

#ifndef BOOST_MPL11_FWD_ADD_HPP
#define BOOST_MPL11_FWD_ADD_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns `T1 + T2 + ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct add;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ADD_HPP
