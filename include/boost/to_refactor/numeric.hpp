/*!
 * @file
 * Defines the methods of the @ref Numeric typeclass.
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
            typename tag_of<typename T1::type>::type,
            typename tag_of<typename T2::type>::type
        >::template plus_impl<typename T1::type, typename T2::type>
    { };

    template <typename T1, typename T2, typename ...Tn>
    struct minus
        : detail::strict_variadic_foldl<quote<minus>, T1, T2, Tn...>
    { };

    template <typename T1, typename T2>
    struct minus<T1, T2>
        : Numeric<
            typename tag_of<typename T1::type>::type,
            typename tag_of<typename T2::type>::type
        >::template minus_impl<typename T1::type, typename T2::type>
    { };

    template <typename T1, typename T2, typename ...Tn>
    struct times
        : detail::strict_variadic_foldl<quote<times>, T1, T2, Tn...>
    { };

    template <typename T1, typename T2>
    struct times<T1, T2>
        : Numeric<
            typename tag_of<typename T1::type>::type,
            typename tag_of<typename T2::type>::type
        >::template times_impl<typename T1::type, typename T2::type>
    { };

    template <typename N>
    struct negate
        : Numeric<typename tag_of<typename N::type>::type>::
          template negate_impl<typename N::type>
    { };

    template <typename N>
    struct abs
        : Numeric<typename tag_of<typename N::type>::type>::
          template abs_impl<typename N::type>
    { };

    template <typename N>
    struct sign
        : Numeric<typename tag_of<typename N::type>::type>::
          template sign_impl<typename N::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NUMERIC_HPP
