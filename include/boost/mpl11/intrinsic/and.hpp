/*!
 * @file
 * Defines `boost::mpl11::intrinsic::and_`.
 */

#ifndef BOOST_MPL11_INTRINSIC_AND_HPP
#define BOOST_MPL11_INTRINSIC_AND_HPP

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
     * Returns the result of short-circuit _logical and_ (`&&`) on the result
     * of its arguments.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct and_
        : dispatch<tag::and_, F1, F2, Fn...>
    { };
} // end namespace intrinsic


template <typename F1, typename F2, typename ...Fn>
struct dispatch<detail::default_<tag::and_>, F1, F2, Fn...>
    : intrinsic::and_<F1, intrinsic::and_<F2, Fn...>>
{ };

template <typename F1, typename F2>
struct dispatch<detail::default_<tag::and_>, F1, F2>
    : identity<
        bool_<if_c<F1::type::value, F2, false_>::type::type::value>
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_AND_HPP
