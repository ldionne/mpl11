/*!
 * @file
 * Defines `boost::mpl11::greater`.
 */

#ifndef BOOST_MPL11_GREATER_HPP
#define BOOST_MPL11_GREATER_HPP

#ifdef BOOST_MPL11_DOXYGEN_INVOKED

namespace boost { namespace mpl11 {
    /*!
     * @ingroup ComparisonMetafunctions
     * Returns whether `T1 > T2 > ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct greater { };
}} // end namespace boost::mpl11

#else // Doxygen not invoked

#   define BOOST_MPL11_OPERATOR_NAME greater
#   define BOOST_MPL11_OPERATOR >
#   include <boost/mpl11/detail/generate_comparison_metafunction.hpp>

#endif // BOOST_MPL11_DOXYGEN_INVOKED

#endif // !BOOST_MPL11_GREATER_HPP
