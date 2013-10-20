/*!
 * @file
 * Defines `boost::mpl11::prior`.
 */

#ifndef BOOST_MPL11_PRIOR_HPP
#define BOOST_MPL11_PRIOR_HPP

#include <boost/mpl11/fwd/prior.hpp>

#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/detail/single_dispatch.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename N>
    struct dispatch<tag::prior, N>
        : detail::single_dispatch<tag::prior, N>::template apply<N>
    { };

    template <>
    struct dispatch<tag::single<tag::prior>, category::integral_constant> {
        template <typename N>
        struct apply
            : identity<
                integral_c<decltype(N::value - 1), N::value - 1>
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PRIOR_HPP
