/*!
 * @file
 * Defines `boost::mpl11::less`.
 */

#ifndef BOOST_MPL11_LESS_HPP
#define BOOST_MPL11_LESS_HPP

#ifdef BOOST_MPL11_DOXYGEN_INVOKED

namespace boost { namespace mpl11 {
    /*!
     * @defgroup ComparisonMetafunctions Comparison Metafunctions
     *
     * Compares several types with a given operator.
     *
     * Comparison metafunctions are standard tag-dispatched metafunctions,
     * whose default implementation share a common pattern described here.
     *
     * The default implementation of a comparison metafunction `F` when
     * invoked with arguments `T1`, `T2`, ...`Tn` is equivalent to
     * `and_<F<T1, T2>, F<T2, Tn...>>`.
     *
     * The default implementation of a comparison metafunction `F`
     * representing an operator `Op` when invoked with arguments `T1` and `T2`
     * is equivalent to `identity<bool_<T1::value Op T2::value>>` if `T1` and
     * `T2` are `IntegralConstant`s, and is not provided otherwise.
     *
     * @warning
     * Differences from the original MPL:
     * - Standard tag dispatching is used with comparison metafunctions.
     * - More than two types can be compared at once.
     */

    /*!
     * @ingroup ComparisonMetafunctions
     * Returns whether `T1 < T2 < ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct less { };
}} // end namespace boost::mpl11

#else // Doxygen not invoked

#   define BOOST_MPL11_OPERATOR_NAME less
#   define BOOST_MPL11_OPERATOR <
#   include <boost/mpl11/detail/generate_comparison_metafunction.hpp>

#endif // BOOST_MPL11_DOXYGEN_INVOKED

#endif // !BOOST_MPL11_LESS_HPP
