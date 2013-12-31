/*!
 * @file
 * Defines `boost::mpl11::take`.
 */

#ifndef BOOST_MPL11_TAKE_HPP
#define BOOST_MPL11_TAKE_HPP

#include <boost/mpl11/fwd/take.hpp>

#include <boost/mpl11/bidirectional_sequence.hpp>
#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/drop.hpp>
#include <boost/mpl11/forward_sequence.hpp>
#include <boost/mpl11/fwd/finite_sequence.hpp>
#include <boost/mpl11/integral_c.hpp> // required by the forward declaration
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/min.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    template <typename N, typename Sequence>
    struct head<take<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(head<take<N, Sequence>>)
    {
        using type = head<Sequence>::type;
    };

    template <typename N, typename Sequence>
    struct tail<take<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(tail<take<N, Sequence>>)
    {
        using type = take_c<N::value - 1, typename tail<Sequence>::type>;
    };

    template <typename N, typename Sequence>
    struct is_empty<take<N, Sequence>>
        : or_<bool_<!N::value>, is_empty<Sequence>>
    { };


    /////////////////////////////////
    // BidirectionalSequence
    /////////////////////////////////
    template <typename N, typename Sequence>
    struct last<take<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(last<take<N, Sequence>>)
    {
        using type = typename head<drop_c<N::value - 1, Sequence>>::type;
    };

    template <typename N, typename Sequence>
    struct init<take<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(init<take<N, Sequence>>)
    {
        using type = take_c<N::value - 1, Sequence>;
    };


    /////////////////////////////////
    // FiniteSequence
    /////////////////////////////////
    template <typename N, typename Sequence>
    struct length<take<N, Sequence>>
        : detail::conditional<sequence_traits<Sequence>::is_finite,
            N,
            min<N, length<Sequence>>
        >::type::type
    { };

    template <typename N, typename Sequence, typename F>
    struct unpack<take<N, Sequence>, F>
        : unpack<
            take_c<N::value - N::value/2, drop_c<N::value/2, Sequence>>,
            typename unpack<
                take_c<N::value/2, Sequence>,
                partial<into<partial>, F>
            >::type
        >
    { };


    /////////////////////////////////
    // RandomAccessSequence
    /////////////////////////////////
    template <typename N, typename Sequence, typename Index>
    struct at<take<N, Sequence>, Index>
        : private BOOST_MPL11_CHECK_USAGE(at<take<N, Sequence>, Index>)
    {
        using type = typename at<Sequence, Index>::type;
    };

    template <typename N, typename S, typename Start, typename Stop>
    struct slice<take<N, S>, Start, Stop>
        : private BOOST_MPL11_CHECK_USAGE(slice<take<N, S>, Start, Stop>)
    {
        using type = typename slice<S, Start, Stop>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TAKE_HPP
