/*!
 * @file
 * Forward declares `boost::mpl11::less_equal`.
 */

#ifndef BOOST_MPL11_OPERATOR_LESS_EQUAL_FWD_HPP
#define BOOST_MPL11_OPERATOR_LESS_EQUAL_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct less_equal; }

    /*!
     * @ingroup comparison_operators
     *
     * Returns whether `T1 <= T2 <= ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * When more than two arguments are provided, as described in
     * @ref comparison_operators. Otherwise, equivalent to
     * `not_<less<T2, T1>>`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct less_equal
        : dispatch<tag::less_equal, T1, T2, Tn...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OPERATOR_LESS_EQUAL_FWD_HPP
