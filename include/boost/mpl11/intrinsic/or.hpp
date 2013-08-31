/*!
 * @file
 * Defines `boost::mpl11::intrinsic::or_`.
 */

#ifndef BOOST_MPL11_INTRINSIC_OR_HPP
#define BOOST_MPL11_INTRINSIC_OR_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace or_detail {
    template <bool F1, typename F2>
    struct or_impl_helper
        : identity<bool_<F2::type::value>>
    { };

    template <typename F2>
    struct or_impl_helper<true, F2>
        : identity<true_>
    { };

    template <typename F1, typename F2>
    struct or_impl
        : or_impl_helper<F1::type::value, F2>
    { };
} // end namespace or_detail

namespace intrinsic {
    /*!
     * @ingroup logical_intrinsic
     *
     * Returns the result of short-circuit _logical or_ (`||`) on the result
     * of its arguments.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct or_
        : detail::tag_dispatched<tag::or_, F1, F2, Fn...>::template
          with_default<lazy_always<or_<F1, or_<F2, Fn...>>>>
    { };

    template <typename F1, typename F2>
    struct or_<F1, F2>
        : detail::tag_dispatched<tag::or_, F1, F2>::template
          with_default<lazy_always<or_detail::or_impl<F1, F2>>>
    { };
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_OR_HPP
