/*!
 * @file
 * Defines `boost::mpl11::greater`.
 */

#ifndef BOOST_MPL11_OPERATOR_GREATER_HPP
#define BOOST_MPL11_OPERATOR_GREATER_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


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
    struct greater
        : dispatch<tag::greater, T1, T2, Tn...>
    { };
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/greater.hpp>
#endif

#endif // !BOOST_MPL11_OPERATOR_GREATER_HPP
