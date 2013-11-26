/*!
 * @file
 * Defines `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_OR_HPP
#define BOOST_MPL11_OR_HPP

#include <boost/mpl11/fwd/or.hpp>

#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename F1, typename F2, typename ...Fn>
    struct or_
        : or_<F1, or_<F2, Fn...>>
    { };

    template <typename F1, typename F2>
    struct or_<F1, F2>
        : class_of<typename F1::type>::type::template or_impl<F1, F2>
    { };

    namespace or_detail {
        template <typename ...T>
        false_ or_impl(T*...);
        true_ or_impl(...);
    }

    template <bool B1, bool B2, bool ...Bn>
    struct or_c
        : true_
    { };

    template <>
    struct or_c<false, false>
        : false_
    { };

    template <bool ...Bn>
    struct or_c<false, false, Bn...>
        : decltype(
            or_detail::or_impl(
                typename detail::conditional<Bn, int, int*>::type{}...
            )
        )
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OR_HPP
