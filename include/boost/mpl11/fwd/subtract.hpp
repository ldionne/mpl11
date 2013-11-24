/*!
 * @file
 * Forward declares `boost::mpl11::subtract`.
 */

#ifndef BOOST_MPL11_FWD_SUBTRACT_HPP
#define BOOST_MPL11_FWD_SUBTRACT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns `T1 - T2 - ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct subtract;

    template <typename T1, typename T2, typename ...Tn>
    using subtract_t = typename subtract<T1, T2, Tn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SUBTRACT_HPP
