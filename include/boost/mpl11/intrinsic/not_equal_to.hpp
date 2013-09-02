/*!
 * @file
 * Defines `boost::mpl11::intrinsic::not_equal_to`.
 */

#ifndef BOOST_MPL11_INTRINSIC_NOT_EQUAL_TO_HPP
#define BOOST_MPL11_INTRINSIC_NOT_EQUAL_TO_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/not.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
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
    struct not_equal_to
        : detail::tag_dispatched<tag::not_equal_to, T1, T2, Tn...>
    { };

    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 != T2`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `not_<equal_to<T1, T2>>`.
     */
    template <typename T1, typename T2>
    struct not_equal_to<T1, T2>
        : detail::tag_dispatched<tag::not_equal_to, T1, T2>
    { };
} // end namespace intrinsic

template <typename T1, typename T2, typename ...Tn>
struct dispatch<detail::default_<tag::not_equal_to>, T1, T2, Tn...>
    : intrinsic::and_<
        intrinsic::not_equal_to<T1, T2>,
        intrinsic::not_equal_to<T2, Tn...>
    >
{ };

template <typename T1, typename T2>
struct dispatch<detail::default_<tag::not_equal_to>, T1, T2>
    : intrinsic::not_<intrinsic::equal_to<T1, T2>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_NOT_EQUAL_TO_HPP
