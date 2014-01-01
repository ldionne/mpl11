/*!
 * @file
 * Defines `boost::mpl11::scanl`.
 */

#ifndef BOOST_MPL11_SCANL_HPP
#define BOOST_MPL11_SCANL_HPP

#include <boost/mpl11/fwd/scanl.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename State, typename S>
    struct tag_of<scanl<F, State, S>> {
        using type = random_access_sequence_tag;
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
            using result = empty_sequence;
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

    template <typename F, typename State, typename S, typename Dest>
    struct unpack<scanl<F, State, S>, Dest>
        :
    { };


    /////////////////////////////////
    // BidirectionalSequence
    /////////////////////////////////
    template <typename F, typename State, typename S>
    struct last<scanl<F, State, S>>
        : private BOOST_MPL11_CHECK_USAGE(last<scanl<F, State, S>>)
    {

    };

    template <typename F, typename State, typename S>
    struct init<scanl<F, State, S>>
        : private BOOST_MPL11_CHECK_USAGE(init<scanl<F, State, S>>)
    {
        using type = scanl<F, State, typename init<S>::type>;
    };


    /////////////////////////////////
    // RandomAccessSequence
    /////////////////////////////////
    template <typename F, typename State, typename S, typename Index>
    struct at<scanl<F, State, S>, Index>
        : private BOOST_MPL11_CHECK_USAGE(at<scanl<F, State, S>, Index>)
    {

    };

    template <typename F, typename State, typename S, typename Start, typename Stop>
    struct slice<scanl<F, State, S>, Start, Stop>
        : private BOOST_MPL11_CHECK_USAGE(slice<scanl<F, State, S>, Start, Stop>)
    {

    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SCANL_HPP
