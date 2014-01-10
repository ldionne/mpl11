/*!
 * @file
 * Defines `boost::mpl11::Numeric`.
 */

#ifndef BOOST_MPL11_NUMERIC_HPP
#define BOOST_MPL11_NUMERIC_HPP

#include <boost/mpl11/fwd/numeric.hpp>

#include <boost/mpl11/detail/strict_variadic_foldl.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename T1, typename T2, typename ...Tn>
    struct plus
        : detail::strict_variadic_foldl<quote<plus>, T1, T2, Tn...>
    { };

    template <typename T1, typename T2>
    struct plus<T1, T2>
        : Numeric<
            typename tag_of<T1>::type, typename tag_of<T2>::type
        >::template plus_impl<T1, T2>
    { };

    template <typename T1, typename T2, typename ...Tn>
    struct minus
        : detail::strict_variadic_foldl<quote<minus>, T1, T2, Tn...>
    { };

    template <typename T1, typename T2>
    struct minus<T1, T2>
        : Numeric<
            typename tag_of<T1>::type, typename tag_of<T2>::type
        >::template minus_impl<T1, T2>
    { };

    template <typename T1, typename T2, typename ...Tn>
    struct times
        : detail::strict_variadic_foldl<quote<times>, T1, T2, Tn...>
    { };

    template <typename T1, typename T2>
    struct times<T1, T2>
        : Numeric<
            typename tag_of<T1>::type, typename tag_of<T2>::type
        >::template times_impl<T1, T2>
    { };

    template <typename N>
    struct negate
        : Numeric<typename tag_of<N>::type>::template negate_impl<N>
    { };

    template <typename N>
    struct abs
        : Numeric<typename tag_of<N>::type>::template abs_impl<N>
    { };

    template <typename N>
    struct sign
        : Numeric<typename tag_of<N>::type>::template sign_impl<N>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NUMERIC_HPP
