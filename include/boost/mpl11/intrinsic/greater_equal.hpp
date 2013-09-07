/*!
 * @file
 * Defines `boost::mpl11::intrinsic::greater_equal`.
 */

#ifndef BOOST_MPL11_INTRINSIC_GREATER_EQUAL_HPP
#define BOOST_MPL11_INTRINSIC_GREATER_EQUAL_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 >= T2 >= ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct greater_equal
        : dispatch<tag::greater_equal, T1, T2, Tn...>
    { };

    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 >= T2`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `not_<less<T1, T2>>`.
     */
    template <typename T1, typename T2>
    struct greater_equal<T1, T2>
        : dispatch<tag::greater_equal, T1, T2>
    { };
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/greater_equal.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_GREATER_EQUAL_HPP
