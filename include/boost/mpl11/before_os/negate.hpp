/*!
 * @file
 * Defines `boost::mpl11::negate`.
 */

#ifndef BOOST_MPL11_NEGATE_HPP
#define BOOST_MPL11_NEGATE_HPP

#include <boost/mpl11/fwd/negate.hpp>

#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/detail/single_dispatch.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct dispatch<tag::negate, T>
        : detail::single_dispatch<tag::negate, T>::template apply<T>
    { };

    template <>
    struct dispatch<tag::single<tag::negate>, category::integral_constant> {
        template <typename I>
        struct apply
            : identity<
                integral_c<decltype(-I::value), -I::value>
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NEGATE_HPP
