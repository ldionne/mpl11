/*!
 * @file
 * Defines `boost::mpl11::scanl`.
 */

#ifndef BOOST_MPL11_SCANL_HPP
#define BOOST_MPL11_SCANL_HPP

#include <boost/mpl11/fwd/scanl.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/bidirectional_sequence.hpp>
#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/drop.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/forward_sequence.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/take.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename State, typename S>
    struct tag_of<scanl<F, State, S>> {
        using type = random_access_sequence_tag;
    };

    template <typename F, typename State, typename S>
    struct sequence_traits<scanl<F, State, S>> : sequence_traits<S> {
        static constexpr bool has_O1_unpack = false;
    };

    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    template <typename F, typename State, typename S>
    struct head<scanl<F, State, S>>
        : private BOOST_MPL11_CHECK_USAGE(head<scanl<F, State, S>>)
    {
        using type = State;
    };

    namespace scanl_detail {
        template <bool IsEmpty>
        struct tail_impl {
            template <typename F, typename State, typename S>
            using result = empty_sequence_t;
        };

        template <>
        struct tail_impl<false> {
            template <typename F, typename State, typename S>
            using result = scanl<
                F,
                typename apply<F, State, typename head<S>::type>::type,
                typename tail<S>::type
            >;
        };
    } // end namespace scanl_detail

    template <typename F, typename State, typename S>
    struct tail<scanl<F, State, S>>
        : private BOOST_MPL11_CHECK_USAGE(tail<scanl<F, State, S>>)
    {
        using type = typename scanl_detail::tail_impl<
            is_empty<S>::value
        >::template result<F, State, S>;
    };

    template <typename F, typename State, typename S>
    struct is_empty<scanl<F, State, S>>
        : false_
    { };


    /////////////////////////////////
    // FiniteSequence
    /////////////////////////////////
    template <typename F, typename State, typename S>
    struct length<scanl<F, State, S>>
        : size_t<length<S>::value + 1>
    { };

    namespace scanl_detail {
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

        template <typename S, typename Dest>
        using unpack_impl = typename foldl<fill_apply, apply<Dest>, S>::type;
    } // end namespace scanl_detail

    //! @todo Use a better algorithm here.
    template <typename F, typename State, typename S, typename Dest>
    struct unpack<scanl<F, State, S>, Dest>
        : scanl_detail::unpack_impl<scanl<F, State, S>, Dest>
    { };


    /////////////////////////////////
    // BidirectionalSequence
    /////////////////////////////////
    template <typename F, typename State, typename S>
    struct last<scanl<F, State, S>>
        : private BOOST_MPL11_CHECK_USAGE(last<scanl<F, State, S>>)
    {
        using type = typename foldl<F, State, S>::type;
    };

    namespace scanl_detail {
        template <bool SeqIsEmpty>
        struct init_impl;

        template <>
        struct init_impl<true> {
            template <typename F, typename State, typename S>
            using result = empty_sequence_t;
        };

        template <>
        struct init_impl<false> {
            template <typename F, typename State, typename S>
            using result = scanl<F, State, typename init<S>::type>;
        };
    } // end namespace scanl_detail

    template <typename F, typename State, typename S>
    struct init<scanl<F, State, S>>
        : private BOOST_MPL11_CHECK_USAGE(init<scanl<F, State, S>>)
    {
        using type = typename scanl_detail::init_impl<
            is_empty<S>::value
        >::template result<F, State, S>;
    };


    /////////////////////////////////
    // RandomAccessSequence
    /////////////////////////////////
    template <typename F, typename State, typename S, typename Index>
    struct at<scanl<F, State, S>, Index>
        : private BOOST_MPL11_CHECK_USAGE(at<scanl<F, State, S>, Index>)
    {
        using type = typename head<
            typename drop<Index, scanl<F, State, S>>::type
        >::type;
    };

    template <typename F, typename State, typename S, typename Start, typename Stop>
    struct slice<scanl<F, State, S>, Start, Stop>
        : private BOOST_MPL11_CHECK_USAGE(slice<scanl<F, State, S>, Start, Stop>)
    {
        using type = typename take_c<
            Stop::value - Start::value,
            typename drop_c<Start::value, scanl<F, State, S>>::type
        >::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SCANL_HPP
