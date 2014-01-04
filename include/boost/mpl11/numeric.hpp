/*!
 * @file
 * Defines `boost::mpl11::Numeric`.
 */

#ifndef BOOST_MPL11_NUMERIC_HPP
#define BOOST_MPL11_NUMERIC_HPP

#include <boost/mpl11/fwd/numeric.hpp>

#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename M, typename N>
    struct plus_impl
        : Numeric<
            typename tag_of<M>::type, typename tag_of<N>::type
        >::template plus_impl<M, N>
    { };

    template <typename M, typename N>
    struct minus_impl
        : Numeric<
            typename tag_of<M>::type, typename tag_of<N>::type
        >::template minus_impl<M, N>
    { };

    template <typename M, typename N>
    struct times_impl
        : Numeric<
            typename tag_of<M>::type, typename tag_of<N>::type
        >::template times_impl<M, N>
    { };

    template <typename N>
    struct negate_impl
        : Numeric<typename tag_of<N>::type>::template negate_impl<N>
    { };

    template <typename N>
    struct abs_impl
        : Numeric<typename tag_of<N>::type>::template abs_impl<N>
    { };

    template <typename N>
    struct sign_impl
        : Numeric<typename tag_of<N>::type>::template sign_impl<N>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NUMERIC_HPP
