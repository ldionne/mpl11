/*!
 * @file
 * Defines `boost::mpl11::unpack`.
 */

#ifndef BOOST_MPL11_UNPACK_HPP
#define BOOST_MPL11_UNPACK_HPP

#include <boost/mpl11/fwd/unpack.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/foldl.hpp>


namespace boost { namespace mpl11 {
    namespace unpack_detail {
        struct variadic_push_back {
            template <typename Variadic, typename X>
            struct apply;

            template <
                template <typename ...> class Variadic, typename ...T,
                typename X
            >
            struct apply<Variadic<T...>, X> {
                using type = Variadic<T..., X>;
            };
        };
    } // end namespace unpack_detail

    template <typename Seq, typename F>
    struct unpack
        : foldl<
            Seq, apply<F>, unpack_detail::variadic_push_back
        >::type
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_UNPACK_HPP
