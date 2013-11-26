/*!
 * @file
 * Defines `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_AND_HPP
#define BOOST_MPL11_AND_HPP

#include <boost/mpl11/fwd/and.hpp>

#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename F1, typename F2, typename ...Fn>
    struct and_
        : and_<F1, and_<F2, Fn...>>
    { };

    template <typename F1, typename F2>
    struct and_<F1, F2>
        : class_of<typename F1::type>::type::template and_impl<F1, F2>
    { };

    namespace and_detail {
        template <typename ...T>
        true_ and_impl(T*...);
        false_ and_impl(...);
    }

    template <bool B1, bool B2, bool ...Bn>
    struct and_c
        : false_
    { };

    template <>
    struct and_c<true, true>
        : true_
    { };

    template <bool ...Bn>
    struct and_c<true, true, Bn...>
        : decltype(
            and_detail::and_impl(
                typename detail::conditional<Bn, int*, int>::type{}...
            )
        )
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AND_HPP
