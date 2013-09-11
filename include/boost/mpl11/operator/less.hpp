/*!
 * @file
 * Defines `boost::mpl11::less`.
 */

#ifndef BOOST_MPL11_OPERATOR_LESS_HPP
#define BOOST_MPL11_OPERATOR_LESS_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup comparison_operators
     *
     * Returns whether `T1 < T2 < ...Tn`.
     *
     *
     * ### Default implementation
     *
     * When more than two arguments are provided, as described in
     * @ref comparison_operators. Otherwise:
     * - If `T1` and `T2` are @ref IntegralConstant "Integral Constants",
     *   equivalent to `identity<bool_<T1::value < T2::value>>`.
     * - Not provided otherwise.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct less
        : dispatch<tag::less, T1, T2, Tn...>
    { };
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/less.hpp>
#endif

#endif // !BOOST_MPL11_OPERATOR_LESS_HPP
