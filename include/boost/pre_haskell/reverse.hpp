/*!
 * @file
 * Defines `boost::mpl11::reverse`.
 */

#ifndef BOOST_MPL11_REVERSE_HPP
#define BOOST_MPL11_REVERSE_HPP

#include <boost/mpl11/fwd/reverse.hpp>

#include <boost/mpl11/detail/default_unpack.hpp>
#include <boost/mpl11/fwd/at.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/slice.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/head.hpp>
#include <boost/mpl11/init.hpp>
#include <boost/mpl11/last.hpp>
#include <boost/mpl11/length.hpp>
#include <boost/mpl11/tail.hpp>


namespace boost { namespace mpl11 {
    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    template <typename Sequence>
    struct head<reverse<Sequence>>
        : last<Sequence>
    { };

    template <typename Sequence>
    struct tail<reverse<Sequence>> {
        using type = reverse<typename init<Sequence>::type>;
    };

    template <typename Sequence>
    struct is_empty<reverse<Sequence>>
        : is_empty<Sequence>
    { };


    /////////////////////////////////
    // FiniteSequence
    /////////////////////////////////
    template <typename Sequence>
    struct length<reverse<Sequence>>
        : length<Sequence>
    { };

    template <typename Sequence, typename F>
    struct unpack<reverse<Sequence>, F>
        : detail::default_unpack<reverse<Sequence>, F>
    { };


    /////////////////////////////////
    // BidirectionalSequence
    /////////////////////////////////
    template <typename Sequence>
    struct last<reverse<Sequence>>
        : head<Sequence>
    { };

    template <typename Sequence>
    struct init<reverse<Sequence>> {
        using type = reverse<typename tail<Sequence>::type>;
    };


    /////////////////////////////////
    // RandomAccessSequence
    /////////////////////////////////
    template <typename Sequence, typename Index>
    struct at<reverse<Sequence>, Index>
        : at_c<Sequence, length<Sequence>::value - Index::value - 1>
    { };

    template <typename Sequence, typename Start, typename Stop>
    struct slice<reverse<Sequence>, Start, Stop> {
        using type = reverse<
            typename slice_c<
                Sequence,
                length<Sequence>::value - Stop::value,
                length<Sequence>::value - Start::value
            >::type
        >;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_REVERSE_HPP
