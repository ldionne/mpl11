/*!
 * @file
 * Defines `boost::mpl11::intrinsic::or_`.
 */

#ifndef BOOST_MPL11_INTRINSIC_OR_HPP
#define BOOST_MPL11_INTRINSIC_OR_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    /*!
     * @ingroup logical_intrinsic
     *
     * Returns the result of short-circuit _logical or_ (`||`) on the result
     * of its arguments.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct or_
        : dispatch<tag::or_, F1, F2, Fn...>
    { };

    template <typename F1, typename F2>
    struct or_<F1, F2>
        : dispatch<tag::or_, F1, F2>
    { };
} // end namespace intrinsic

template <typename F1, typename F2, typename ...Fn>
struct dispatch<detail::default_<tag::or_>, F1, F2, Fn...>
    : intrinsic::or_<F1, intrinsic::or_<F2, Fn...>>
{ };

template <typename F1, typename F2>
struct dispatch<detail::default_<tag::or_>, F1, F2>
    : identity<
        bool_<if_c<F1::type::value, true_, F2>::type::type::value>
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_OR_HPP
