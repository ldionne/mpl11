/*!
 * @file
 * Defines `boost::mpl11::next`.
 */

#ifndef BOOST_MPL11_NEXT_HPP
#define BOOST_MPL11_NEXT_HPP

#include <boost/mpl11/fwd/next.hpp>

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename N>
    struct dispatch<tag::next, N>
        : apply_wrap<
            dispatch<
                tag::by_category<tag::next>,
                typename category_of<N>::type
            >,
            N
        >
    { };

    template <>
    struct dispatch<tag::by_category<tag::next>, category::integral_constant> {
        template <typename N>
        struct apply
            : identity<
                integral_c<decltype(N::value + 1), N::value + 1>
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NEXT_HPP
