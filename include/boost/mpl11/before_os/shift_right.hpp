/*!
 * @file
 * Defines `boost::mpl11::shift_right`.
 */

#ifndef BOOST_MPL11_SHIFT_RIGHT_HPP
#define BOOST_MPL11_SHIFT_RIGHT_HPP

#include <boost/mpl11/fwd/shift_right.hpp>

#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/detail/single_dispatch.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename T, typename Shift>
    struct dispatch<tag::shift_right, T, Shift>
        : detail::single_dispatch<tag::shift_right, T>::
            template apply<T, Shift>
    { };

    template <>
    struct dispatch<tag::single<tag::shift_right>, category::integral_constant>
    {
        template <typename I, typename Shift>
        struct apply
            : identity<
                integral_c<
                    decltype(I::value >> Shift::value),
                    I::value >> Shift::value
                >
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SHIFT_RIGHT_HPP
