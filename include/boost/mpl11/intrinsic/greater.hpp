/*!
 * @file
 * Defines `boost::mpl11::intrinsic::greater`.
 */

#ifndef BOOST_MPL11_INTRINSIC_GREATER_HPP
#define BOOST_MPL11_INTRINSIC_GREATER_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/intrinsic/less.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 > T2 > ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct greater
        : detail::tag_dispatched<tag::greater, T1, T2, Tn...>
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
        : detail::tag_dispatched<tag::greater, T1, T2>
    { };
} // end namespace intrinsic

template <typename T1, typename T2, typename ...Tn>
struct dispatch<detail::default_<tag::greater>, T1, T2, Tn...>
    : intrinsic::and_<
        intrinsic::greater<T1, T2>,
        intrinsic::greater<T2, Tn...>
    >
{ };

template <typename T1, typename T2>
struct dispatch<detail::default_<tag::greater>, T1, T2>
    : intrinsic::less<T2, T1>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_GREATER_HPP
