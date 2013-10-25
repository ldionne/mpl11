/*!
 * @file
 * Forward declares `boost::mpl11::greater_equal`.
 */

#ifndef BOOST_MPL11_FWD_GREATER_EQUAL_HPP
#define BOOST_MPL11_FWD_GREATER_EQUAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup comparison_operators
     *
     * Returns whether `T1 >= T2 >= ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * When more than two arguments are provided, as described in
     * @ref comparison_operators. Otherwise, equivalent to
     * `not_<less<T1, T2>>`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct greater_equal;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_GREATER_EQUAL_HPP
