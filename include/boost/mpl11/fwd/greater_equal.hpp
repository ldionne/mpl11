/*!
 * @file
 * Forward declares `boost::mpl11::greater_equal`.
 */

#ifndef BOOST_MPL11_FWD_GREATER_EQUAL_HPP
#define BOOST_MPL11_FWD_GREATER_EQUAL_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct greater_equal; }

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
    struct greater_equal
        : dispatch<tag::greater_equal, T1, T2, Tn...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_GREATER_EQUAL_HPP
