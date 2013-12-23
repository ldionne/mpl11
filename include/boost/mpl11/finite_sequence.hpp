/*!
 * @file
 * Defines `boost::mpl11::FiniteSequence`.
 */

#ifndef BOOST_MPL11_FINITE_SEQUENCE_HPP
#define BOOST_MPL11_FINITE_SEQUENCE_HPP

#include <boost/mpl11/fwd/finite_sequence.hpp>

#include <boost/mpl11/detail/default_unpack.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/forward_sequence.hpp> // for fwd/finite_sequence.hpp
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace finite_sequence_detail {
        struct increment {
            template <typename Size, typename>
            using apply = size_t<Size::value + 1>;
        };
    } // end namespace unpack_detail

    template <typename S, typename F>
    struct FiniteSequence::unpack_impl
        : detail::default_unpack<S, F>
    { };

    template <typename S>
    struct FiniteSequence::length_impl
        : foldl<S, size_t<0>, finite_sequence_detail::increment>::type
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FINITE_SEQUENCE_HPP
