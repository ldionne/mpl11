/*!
 * @file
 * Defines `boost::mpl11::intrinsic::less`.
 */

#ifndef BOOST_MPL11_INTRINSIC_LESS_HPP
#define BOOST_MPL11_INTRINSIC_LESS_HPP

#ifdef BOOST_MPL11_DOXYGEN_INVOKED

namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 < T2 < ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct less { };
}}} // end namespace boost::mpl11::intrinsic

#else // Doxygen not invoked

#   define BOOST_MPL11_OPERATOR_NAME less
#   define BOOST_MPL11_OPERATOR <
#   include <boost/mpl11/detail/generate_comparison_intrinsic.hpp>

#endif // BOOST_MPL11_DOXYGEN_INVOKED

#endif // !BOOST_MPL11_INTRINSIC_LESS_HPP
