/*!
 * @file
 * Defines `boost::mpl11::negate`.
 */

#ifndef BOOST_MPL11_NEGATE_HPP
#define BOOST_MPL11_NEGATE_HPP

#include <boost/mpl11/fwd/negate.hpp>

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct dispatch<tag::negate, T>
        : apply_wrap<
            dispatch<
                tag::by_category<tag::negate>,
                typename category_of<T>::type
            >,
            T
        >
    { };

    template <>
    struct dispatch<tag::by_category<tag::negate>,
                    category::integral_constant> {
        template <typename I>
        struct apply
            : identity<
                integral_c<decltype(-I::value), -I::value>
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NEGATE_HPP
