/*!
 * @file
 * Defines `boost::mpl11::next`.
 */

#ifndef BOOST_MPL11_NEXT_HPP
#define BOOST_MPL11_NEXT_HPP

#include <boost/mpl11/fwd/next.hpp>

#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace next_detail {
        template <typename Category, typename N>
        struct next_impl;

        template <typename N>
        struct next_impl<category::integral_constant, N>
            : identity<
                integral_c<decltype(N::value + 1), N::value + 1>
            >
        { };
    } // end namespace next_detail

    template <typename N>
    struct dispatch<tag::next, N>
        : next_detail::next_impl<
            typename detail::best_category_for<N,
                category::integral_constant
            >::type,
            N
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NEXT_HPP
