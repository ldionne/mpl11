/*!
 * @file
 * Forward declares `boost::mpl11::bitor_`.
 */

#ifndef BOOST_MPL11_FWD_BITOR_HPP
#define BOOST_MPL11_FWD_BITOR_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup bitwise_operators
     *
     * Returns `T1 | T2 | ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct bitor_;

    template <typename T1, typename T2, typename ...Tn>
    using bitor_t = typename bitor_<T1, T2, Tn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITOR_HPP
