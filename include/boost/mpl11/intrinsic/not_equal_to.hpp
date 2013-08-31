/*!
 * @file
 * Defines `boost::mpl11::intrinsic::not_equal_to`.
 */

#ifndef BOOST_MPL11_INTRINSIC_NOT_EQUAL_TO_HPP
#define BOOST_MPL11_INTRINSIC_NOT_EQUAL_TO_HPP

#ifdef BOOST_MPL11_DOXYGEN_INVOKED

namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 != T2 != ...Tn`.
     *
     *
     * @warning
     * Using this intrinsic with several arguments can be confusing. It
     * does not check whether `T1`, `T2`, ...`Tn` are all different, but
     * whether they are different from left to right.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct not_equal_to { };
}}} // end namespace boost::mpl11::intrinsic

#else // Doxygen not invoked

#   define BOOST_MPL11_OPERATOR_NAME not_equal_to
#   define BOOST_MPL11_OPERATOR !=
#   include <boost/mpl11/detail/generate_comparison_intrinsic.hpp>

#endif // BOOST_MPL11_DOXYGEN_INVOKED

#endif // !BOOST_MPL11_INTRINSIC_NOT_EQUAL_TO_HPP
