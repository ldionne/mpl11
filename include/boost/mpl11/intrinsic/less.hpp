/*!
 * @file
 * Defines `boost::mpl11::intrinsic::less`.
 */

#ifndef BOOST_MPL11_INTRINSIC_LESS_HPP
#define BOOST_MPL11_INTRINSIC_LESS_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 < T2 < ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct less BOOST_MPL11_DOXYGEN_ONLY(<T1, T2, Tn...>)
        : dispatch<tag::less, T1, T2, Tn...>
    { };

    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 < T2`.
     *
     *
     * ### Default implementation
     *
     * Equivalent to `identity<bool_<T1::value < T2::value>>` if `T1`
     * and `T2` are `IntegralConstant`s, and not provided otherwise.
     */
    template <typename T1, typename T2>
    struct less<T1, T2>
        : dispatch<tag::less, T1, T2>
    { };
} // end namespace intrinsic

template <typename T1, typename T2, typename ...Tn>
struct dispatch<detail::default_<tag::less>, T1, T2, Tn...>
    : intrinsic::and_<
        intrinsic::less<T1, T2>,
        intrinsic::less<T2, Tn...>
    >
{ };

namespace less_detail {
    template <typename Category1, typename T1, typename Category2, typename T2>
    struct less_impl;

    template <typename T1, typename T2>
    struct less_impl<category::integral_constant, T1,
                     category::integral_constant, T2>
        : identity<
            bool_<T1::value < T2::value>
        >
    { };
} // end namespace less_detail

template <typename T1, typename T2>
struct dispatch<detail::default_<tag::less>, T1, T2>
    : less_detail::less_impl<
        typename detail::best_category_for<
            T1, category::integral_constant
        >::type, T1,
        typename detail::best_category_for<
            T2, category::integral_constant
        >::type, T2
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_LESS_HPP
