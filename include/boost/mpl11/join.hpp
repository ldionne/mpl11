/*!
 * @file
 * Defines `boost::mpl11::join`.
 */

#ifndef BOOST_MPL11_JOIN_HPP
#define BOOST_MPL11_JOIN_HPP

#include <boost/mpl11/fwd/join.hpp>

#include <boost/mpl11/add.hpp>
#include <boost/mpl11/and.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/compose.hpp>
#include <boost/mpl11/filter.hpp>
#include <boost/mpl11/head.hpp>
#include <boost/mpl11/init.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/last.hpp>
#include <boost/mpl11/length.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/slice.hpp>
#include <boost/mpl11/tail.hpp>
#include <boost/mpl11/unpack.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
    namespace join_detail {
        template <bool>
        struct join_helper;

        template <>
        struct join_helper<true> {
            template <typename S1, typename ...Sn>
            struct head_impl : head<join<Sn...>> { };

            template <typename S1, typename S2>
            struct head_impl<S1, S2> : head<S2> { };

            template <typename S1, typename ...Sn>
            struct tail_impl : tail<join<Sn...>> { };

            template <typename S1, typename S2>
            struct tail_impl<S1, S2> : tail<S2> { };
        };

        template <>
        struct join_helper<false> {
            template <typename S1, typename ...Sn>
            using head_impl = head<S1>;

            template <typename S1, typename ...Sn>
            struct tail_impl {
                using type = join<typename tail<S1>::type, Sn...>;
            };
        };
    } // end namespace join_detail

    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    template <typename S1, typename S2, typename ...Sn>
    struct head<join<S1, S2, Sn...>>
        : join_detail::join_helper<
            is_empty<S1>::value
        >::template head_impl<S1, S2, Sn...>
    { };

    template <typename S1, typename S2, typename ...Sn>
    struct tail<join<S1, S2, Sn...>>
        : join_detail::join_helper<
            is_empty<S1>::value
        >::template tail_impl<S1, S2, Sn...>
    { };

    template <typename ...Sn>
    struct is_empty<join<Sn...>>
        : and_<is_empty<Sn>...>
    { };


    /////////////////////////////////
    // FiniteSequence
    /////////////////////////////////
    template <typename ...Sn>
    struct length<join<Sn...>>
        : add<typename length<Sn>::type...>::type
    { };

    template <typename S1, typename S2, typename ...Sn, typename F>
    struct unpack<join<S1, S2, Sn...>, F>
        : unpack<
            join<S2, Sn...>,
            typename unpack<S1, partial<into<partial>, F>>::type
        >
    { };

    template <typename S1, typename S2, typename F>
    struct unpack<join<S1, S2>, F>
        : unpack<S2, typename unpack<S1, partial<into<partial>, F>>::type>
    { };


    /////////////////////////////////
    // BidirectionalSequence
    /////////////////////////////////
    template <typename ...Sn>
    struct last<join<Sn...>>
        : last<
            typename last<
                filter<compose<quote<not_>, quote<is_empty>>, vector<Sn...>>
            >::type
        >
    { };

    template <typename ...Sn>
    struct init<join<Sn...>> {
    private:
        using NonEmpty = filter<
            compose<quote<not_>, quote<is_empty>>, vector<Sn...>
        >;
        using NewSequences = push_back_t<
            unpack_t<init_t<NonEmpty>, into<vector>>,
            init_t<last_t<NonEmpty>>
        >;

    public:
        using type = unpack_t<
            NewSequences, partial<into<join>, vector<>, vector<>>
        >;
    };


    /////////////////////////////////
    // RandomAccessSequence
    /////////////////////////////////
    namespace join_detail {
        template <detail::std_size_t Index, typename S1, typename ...Sn>
        struct at_impl {
            template <bool = (Index < length<S1>::value), typename Dummy = void>
            struct apply;

            template <typename Dummy>
            struct apply<true, Dummy>
                : at_c<S1, Index>
            { };

            template <typename Dummy>
            struct apply<false, Dummy>
                : at_impl<Index - length<S1>::value, Sn...>::template apply<>
            { };
        };
    } // end namespace join_detail

    template <typename ...Sn, typename Index>
    struct at<join<Sn...>, Index>
        : join_detail::at_impl<Index::value, Sn...>::template apply<>
    { };

    namespace join_detail {
        template <bool, bool>
        struct slice_dispatch;

        template <detail::std_size_t Start, detail::std_size_t Stop, typename S1, typename ...Sn>
        struct slice_impl
            : slice_dispatch<
                (Start <= length<S1>::value),
                (Stop <= length<S1>::value)
            >::template apply<Start, Stop, S1, Sn...>
        { };

        template <>
        struct slice_dispatch<true, true> {
            template <detail::std_size_t Start, detail::std_size_t Stop, typename S1, typename ...Sn>
            struct apply
                : slice_c<S1, Start, Stop>
            { };
        };

        template <>
        struct slice_dispatch<false, false> {
            template <detail::std_size_t Start, detail::std_size_t Stop, typename S1, typename ...Sn>
            struct apply
                : slice_impl<Start - length<S1>::value, Stop - length<S1>::value, Sn...>
            { };
        };

        template <>
        struct slice_dispatch<true, false> {
            template <detail::std_size_t Start, detail::std_size_t Stop, typename S1, typename ...Sn>
            struct apply {
                using type = join<
                    slice_c_t<S1, Start, length<S1>::value>,
                    typename slice_impl<0, Stop - length<S1>::value, Sn...>::type
                >;
            };
        };

        template <detail::std_size_t Start, detail::std_size_t Stop, typename S1>
        struct slice_impl<Start, Stop, S1>
            : slice_c<S1, Start, Stop>
        { };
    } // end namespace join_detail

    template <typename S1, typename S2, typename ...Sn, typename Start, typename Stop>
    struct slice<join<S1, S2, Sn...>, Start, Stop>
        : join_detail::slice_impl<Start::value, Stop::value, S1, S2, Sn...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_JOIN_HPP
