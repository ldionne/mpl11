/*!
 * @file
 * Defines `boost::mpl11::shift_left`.
 */

#ifndef BOOST_MPL11_SHIFT_LEFT_HPP
#define BOOST_MPL11_SHIFT_LEFT_HPP

#include <boost/mpl11/fwd/shift_left.hpp>

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct dispatch<tag::shift_left, T>
        : apply_wrap<
            dispatch<
                tag::by_category<tag::shift_left>,
                typename category_of<T>::type
            >,
            T
        >
    { };

    template <>
    struct dispatch<tag::by_category<tag::shift_left>,
                    category::integral_constant> {
        template <typename I, typename Shift>
        struct apply
            : identity<
                integral_c<
                    decltype(I::value << Shift::value),
                    I::value << Shift::value
                >
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SHIFT_LEFT_HPP
