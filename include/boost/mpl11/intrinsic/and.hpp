/*!
 * @file
 * Defines `boost::mpl11::intrinsic::and_`.
 */

#ifndef BOOST_MPL11_INTRINSIC_AND_HPP
#define BOOST_MPL11_INTRINSIC_AND_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace and_detail {
    template <bool F1, typename F2>
    struct and_impl_helper
        : identity<bool_<F2::type::value>>
    { };

    template <typename F2>
    struct and_impl_helper<false, F2>
        : identity<false_>
    { };

    template <typename F1, typename F2>
    struct and_impl
        : and_impl_helper<F1::type::value, F2>
    { };
} // end namespace and_detail

namespace intrinsic {
    /*!
     * @ingroup logical_intrinsic
     *
     * Returns the result of short-circuit _logical and_ (`&&`) on the result
     * of its arguments.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct and_
        : detail::tag_dispatched<tag::and_, F1, F2, Fn...>::template
          with_default<lazy_always<and_<F1, and_<F2, Fn...>>>>
    { };

    template <typename F1, typename F2>
    struct and_<F1, F2>
        : detail::tag_dispatched<tag::and_, F1, F2>::template
          with_default<lazy_always<and_detail::and_impl<F1, F2>>>
    { };
} // end namespace intrinsic
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_AND_HPP
