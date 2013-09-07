/*!
 * @file
 * Defines `boost::mpl11::intrinsic::greater`.
 */

#ifndef BOOST_MPL11_INTRINSIC_GREATER_HPP
#define BOOST_MPL11_INTRINSIC_GREATER_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 > T2 > ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct greater
        : dispatch<tag::greater, T1, T2, Tn...>
    { };

    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 > T2`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `less<T2, T1>`.
     */
    template <typename T1, typename T2>
    struct greater<T1, T2>
        : dispatch<tag::greater, T1, T2>
    { };
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/greater.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_GREATER_HPP
