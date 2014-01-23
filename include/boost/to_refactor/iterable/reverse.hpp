/*!
 * @file
 * Defines `boost::mpl11::reverse`.
 */

#ifndef BOOST_MPL11_ITERABLE_REVERSE_HPP
#define BOOST_MPL11_ITERABLE_REVERSE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/flip.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/cons.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    namespace rules {
        template <typename Iter, typename>
        struct reverse_impl
            : foldl<flip<quote<cons>>, empty_sequence, Iter>
        { };

        template <typename Iter>
        struct reverse_impl<reverse<Iter>> : Iter { };

        template <typename Iter>
        struct head_impl<reverse<Iter>> : last<Iter> { };

        template <typename Iter>
        struct last_impl<reverse<Iter>> : head<Iter> { };

        template <typename Iter>
        struct is_empty_impl<reverse<Iter>> : is_empty<Iter> { };

        template <typename Iter>
        struct length_impl<reverse<Iter>> : length<Iter> { };

        template <typename Iter, typename Index>
        struct at_impl<reverse<Iter>, Index,
            bool_<sequence_traits<typename Iter::type>::has_O1_length>
        >
            : at_c<Iter, length<Iter>::value - Index::type::value - 1>
        { };
    } // end namespace rules

    // template <typename S>
    // struct sequence_traits<reverse<S>> : sequence_traits<typename S::type> {
    //     static constexpr bool has_O1_unpack = false;
    // };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_REVERSE_HPP
