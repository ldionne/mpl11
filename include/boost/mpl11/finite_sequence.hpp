/*!
 * @file
 * Defines `boost::mpl11::FiniteSequence`.
 */

#ifndef BOOST_MPL11_FINITE_SEQUENCE_HPP
#define BOOST_MPL11_FINITE_SEQUENCE_HPP

#include <boost/mpl11/fwd/finite_sequence.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/forward_sequence.hpp> // for fwd/finite_sequence.hpp
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace finite_sequence_detail {
        struct fill_apply {
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

        struct increment {
            template <typename Size, typename>
            using apply = size_t<Size::value + 1>;
        };
    } // end namespace unpack_detail

    template <typename S, typename F>
    struct FiniteSequence::unpack_impl
        : foldl<S, apply<F>, finite_sequence_detail::fill_apply>::type
    { };

    template <typename S>
    struct FiniteSequence::length_impl
        : foldl<S, size_t<0>, finite_sequence_detail::increment>::type
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FINITE_SEQUENCE_HPP
