/*!
 * @file
 * Forward declares `boost::mpl11::greater`.
 */

#ifndef BOOST_MPL11_FWD_GREATER_HPP
#define BOOST_MPL11_FWD_GREATER_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup comparison_operators
     *
     * Returns whether `T1 > T2 > ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * When more than two arguments are provided, as described in
     * @ref comparison_operators. Otherwise, equivalent to `less<T2, T1>`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct greater;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_GREATER_HPP
