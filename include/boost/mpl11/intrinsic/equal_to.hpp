/*!
 * @file
 * Defines `boost::mpl11::intrinsic::equal_to`.
 */

#ifndef BOOST_MPL11_INTRINSIC_EQUAL_TO_HPP
#define BOOST_MPL11_INTRINSIC_EQUAL_TO_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
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
     * Returns whether `T1 == T2 == ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct equal_to BOOST_MPL11_DOXYGEN_ONLY(<T1, T2, Tn...>)
        : detail::tag_dispatched<tag::equal_to, T1, T2, Tn...>
    { };

    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 == T2`.
     *
     *
     * ### Default implementation
     *
     * Equivalent to `identity<bool_<T1::value == T2::value>>` if `T1` and
     * `T2` are `IntegralConstant`s, and to
     * `identity<bool_<std::is_same<T1, T2>::value>>` otherwise.
     */
    template <typename T1, typename T2>
    struct equal_to<T1, T2>
        : detail::tag_dispatched<tag::equal_to, T1, T2>
    { };
} // end namespace intrinsic

template <typename T1, typename T2, typename ...Tn>
struct dispatch<detail::default_<tag::equal_to>, T1, T2, Tn...>
    : intrinsic::and_<
        intrinsic::equal_to<T1, T2>,
        intrinsic::equal_to<T2, Tn...>
    >
{ };

namespace equal_to_detail {
    template <typename Category1, typename T1, typename Category2, typename T2>
    struct equal_to_impl
        : identity<
            bool_<detail::is_same<T1, T2>::value>
        >
    { };

    template <typename T1, typename T2>
    struct equal_to_impl<category::integral_constant, T1,
                         category::integral_constant, T2>
        : identity<
            bool_<T1::value == T2::value>
        >
    { };
} // end namespace equal_to_detail

template <typename T1, typename T2>
struct dispatch<detail::default_<tag::equal_to>, T1, T2>
    : equal_to_detail::equal_to_impl<
        typename detail::best_category_for<
            T1, category::integral_constant
        >::type, T1,
        typename detail::best_category_for<
            T2, category::integral_constant
        >::type, T2
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_EQUAL_TO_HPP
