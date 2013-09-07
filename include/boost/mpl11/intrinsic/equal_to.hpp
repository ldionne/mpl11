/*!
 * @file
 * Defines `boost::mpl11::intrinsic::equal_to`.
 */

#ifndef BOOST_MPL11_INTRINSIC_EQUAL_TO_HPP
#define BOOST_MPL11_INTRINSIC_EQUAL_TO_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 == T2 == ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct equal_to BOOST_MPL11_DOXYGEN_ONLY(<T1, T2, Tn...>)
        : dispatch<tag::equal_to, T1, T2, Tn...>
    { };

    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 == T2`.
     *
     *
     * ### Semantics and default implementation
     *
     * - If `T1` and `T2` are `IntegralConstant`s, equivalent to
     *   `identity<bool_<T1::value == T2::value>>`.
     * - If `T1` and `T2` are `AssociativeSequence`s, equivalent to checking
     *   whether both sequences have the same keys mapping to the same values.
     * - If `T1` and `T2` are `ForwardSequence`s, equivalent to
     *   `equal<T1, T2>`.
     * - Otherwise, equivalent to
     *   `identity<bool_<std::is_same<T1, T2>::value>>`.
     */
    template <typename T1, typename T2>
    struct equal_to<T1, T2>
        : dispatch<tag::equal_to, T1, T2>
    { };
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/equal_to.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_EQUAL_TO_HPP
