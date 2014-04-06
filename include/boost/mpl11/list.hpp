/*!
 * @file
 * Defines the @ref List datatype.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_LIST_HPP
#define BOOST_MPL11_LIST_HPP

#include <boost/mpl11/fwd/list.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/config.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/functor.hpp>
#include <boost/mpl11/iterable.hpp>

#include <boost/mpl11/core.hpp>       //
#include <boost/mpl11/foldable.hpp>   //
#include <boost/mpl11/functional.hpp> // required by fwd/list.hpp
#include <boost/mpl11/integer.hpp>    //
#include <boost/mpl11/logical.hpp>    //


namespace boost { namespace mpl11 {
    template <typename ...xs>
    struct list {
        using type = list;
        using mpl_datatype = List;
    };

    template <typename x, typename xs>
    struct cons {
        using type = cons;
        using mpl_datatype = List;
    };

    template <>
    struct Iterable<List> : instantiate<Iterable>::with<List> {
        template <typename>
        struct head_impl;

        template <typename x, typename xs>
        struct head_impl<cons<x, xs>>
            : x
        { };

        template <typename x, typename ...xs>
        struct head_impl<list<x, xs...>>
            : x
        { };


        template <typename>
        struct tail_impl;

        template <typename x, typename xs>
        struct tail_impl<cons<x, xs>>
            : xs
        { };

        template <typename x, typename ...xs>
        struct tail_impl<list<x, xs...>>
            : list<xs...>
        { };


        template <typename n, typename self>
        struct at_impl
            : instantiate<mpl11::Iterable>::with<List>::at_impl<n, self>
        { };

        template <typename n, typename ...xs>
        struct at_impl<n, list<xs...>>
            : arg<n::type::value+1>::type::template apply<xs...>
        { };


        template <typename>
        struct is_empty_impl : false_ { };
    };

    template <>
    struct Iterable<List>::is_empty_impl<list<>> : true_ { };


    template <>
    struct Functor<List> : instantiate<Functor>::with<List> {
        template <typename f, typename xs>
        struct fmap_impl;

        template <typename f, typename ...xs>
        struct fmap_impl<f, list<xs...>> {
            using type = list<typename f::type::template apply<xs>...>;
        };

        template <typename f, typename x, typename xs>
        struct fmap_impl<f, cons<x, xs>> {
            using type = cons<
                typename f::type::template apply<x>,
                fmap<f, xs>
            >;
        };
    };

#if 0
    template <typename Init, typename Last>
    struct head_impl<snoc<Init, Last>>
        : head<Init>
    { };

    template <typename Init, typename Last>
    struct tail_impl<snoc<Init, Last>>
        : snoc<tail<Init>, Last>
    { };

    template <typename>
    using is_empty_impl = false_;

    template <typename Init, typename Last>
    struct length_impl<snoc<Init, Last>>
        : size_t<length<Init>::value + 1>
    { };

    template <typename Init, typename Last, typename F>
    struct unpack_impl<snoc<Init, Last>, F>
        : apply<unpack<Init, partial<into<partial>, F>>, Last>
    { };

    template <typename Init, typename Last>
    struct init_impl<snoc<Init, Last>> : Init { };

    template <typename Init, typename Last>
    struct last_impl<snoc<Init, Last>> : Last { };
#endif

    template <typename f, typename x>
    struct iterate
        : cons<x, iterate<f, typename f::type::template apply<x>>>
    { };

    template <typename x>
    struct repeat
        : cons<x, repeat<x>>
    { };

#if 0
    template <typename T, typename Index>
    struct at_impl<repeat<T>, Index> : T { };

    template <typename T>
    struct last_impl<repeat<T>> : T { };

    template <typename T>
    struct init_impl<repeat<T>> : repeat<T> { };
#endif

    namespace list_detail {
        template <detail::std_size_t n, typename xs,
            bool = n == 0 || is_empty<xs>::value>
        struct take_impl
            : list<>
        { };

        template <detail::std_size_t n, typename xs>
        struct take_impl<n, xs, false>
            : cons<head<xs>, take_impl<n-1, tail<xs>>>
        { };

        template <typename n, typename xs>
        struct take_checks {
            static_assert(n::type::value >= 0,
            "Invalid usage of `take`: "
            "The number of elements to take must be non-negative.");
        };

        template <typename xs, typename from, typename to>
        struct slice_checks {
        private:
            static constexpr auto start = from::type::value;
            static constexpr auto stop = to::type::value;

            static_assert(start >= 0,
            "Invalid usage of `slice`: The start index must be non-negative.");

            static_assert(start <= stop,
            "Invalid usage of `slice`: "
            "The start index must be less-than or equal to the stop index.");

        #if 0
            using Length = if_c<sequence_traits<typename Iter::type>::is_finite,
                length<Iter>,
                Stop_
            >;

            static_assert(Stop <= Length::value,
            "Invalid usage of `slice`: "
            "The stop index is out of the bounds of the iterable.");
        #endif
        };

        template <typename xs>
        struct init_checks {
            static_assert(!is_empty<xs>::value,
            "Invalid usage of `init` on an empty list.");
        };
    } // end namespace list_detail

    template <typename n, typename xs>
    struct take
        : BOOST_MPL11_IF_ASSERTIONS(list_detail::take_checks<n, xs>,)
          list_detail::take_impl<n::type::value, xs>
    { };

    template <typename xs, typename from, typename to>
    struct slice
        : BOOST_MPL11_IF_ASSERTIONS(list_detail::slice_checks<xs, from, to>,)
          take_c<to::type::value - from::type::value, drop<from, xs>>
    { };

    template <typename xs>
    struct init
        : BOOST_MPL11_IF_ASSERTIONS(list_detail::init_checks<xs>,)
          if_c<is_empty<tail<xs>>::value,
            list<>,
            cons<head<xs>, init<tail<xs>>>
        >
    { };

#if 0
    template <typename N1, typename N2, typename Iter>
    struct take_impl<N1, take<N2, Iter>> : take<min<N1, N2>, Iter> { };

    template <typename N, typename Iter>
    struct is_empty_impl<take<N, Iter>>
        : or_<bool_<N::type::value == 0>, is_empty<Iter>>
    { };

    template <typename N, typename Iter>
    struct length_impl<take<N, Iter>,
        bool_<!sequence_traits<typename Iter::type>::is_finite>
    >
        : N
    { };

    template <typename N, typename Iter>
    struct length_impl<take<N, Iter>,
        bool_<sequence_traits<typename Iter::type>::has_O1_length>
    >
        : size_t<(
            N::type::value < length<Iter>::value
                ? N::type::value
                : length<Iter>::value
        )>
    { };

    template <typename N, typename Iter>
    struct init_impl<take<N, Iter>,
        bool_<sequence_traits<typename Iter::type>::has_O1_length>
    >
        : take<pred<length<take<N, Iter>>>, Iter>
    { };

    template <typename N, typename Iter, typename Index>
    struct at_impl<take<N, Iter>, Index> : at<Iter, Index> { };
#endif

    namespace list_detail {
        template <typename pred>
        struct go {
            using type = go;
            template <typename x, typename xs>
            using apply = if_c<pred::type::template apply<x>::type::value,
                cons<x, xs>,
                list<>
            >;
        };
    }

    template <typename pred, typename xs>
    struct take_while
        : foldr<list_detail::go<pred>, list<>, xs>
    { };

#if 0
    template <typename Pred, typename Iter>
    struct is_empty_impl<take_while<Pred, Iter>>
        : or_<is_empty<Iter>, not_<apply<Pred, head<Iter>>>>
    { };
#endif

    template <typename xs>
    struct reverse
        : foldl<flip<lift<cons>>, list<>, xs>
    { };

#if 0
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
#endif

    namespace list_detail {
        template <typename pred>
        struct filter_help {
            using type = filter_help;
            template <typename x, typename xs>
            using apply = if_c<
                (bool)pred::type::template apply<x>::type::value,
                cons<x, xs>,
                xs
            >;
        };
    }

    template <typename pred, typename xs>
    struct filter
        : foldr<list_detail::filter_help<pred>, list<>, xs>
    { };

#if 0
    template <typename Pred1, typename Pred2>
    struct both {
        using type = both;
        template <typename X>
        using apply = and_<
            mpl11::apply<Pred1, X>,
            mpl11::apply<Pred2, X>
        >;
    };

    template <typename Pred, typename Iter>
    struct is_empty_impl<filter<Pred, Iter>> : none<Pred, Iter> { };

    template <typename Pred1, typename Pred2, typename Iter>
    struct filter_impl<Pred1, filter<Pred2, Iter>>
        : filter<filter_detail::both<Pred1, Pred2>, Iter>
    { };
#endif

    template <typename f, typename state, typename xs>
    struct scanl
        : if_c<is_empty<xs>::value,
            list<state>,
            cons<
                state,
                scanl<f, apply<f, state, head<xs>>, tail<xs>>
            >
        >
    { };

#if 0
    template <typename F, typename State, typename Iter>
    struct length_impl<scanl<F, State, Iter>>
        : size_t<length<Iter>::value + 1>
    { };

    template <typename F, typename State, typename Iter>
    struct last_impl<scanl<F, State, Iter>> : foldl<F, State, Iter> { };
#endif

    template <typename f>
    struct zip_with<f>
        : list<>
    { };

    template <typename f, typename xs>
    struct zip_with<f, xs>
        : fmap<f, xs>
    { };

    template <typename f, typename ...lists>
    struct zip_with
        : if_<or_<is_empty<lists>...>,
            list<>,
            cons<
                typename f::type::template apply<head<lists>...>,
                zip_with<f, tail<lists>...>
            >
        >
    { };

#if 0
    template <typename ...Iters>
    struct length_impl<zip<Iters...>>
        // We make it strict because we might get some optimization.
        : min<typename length<Iters>::type...>::type
    { };

    //! @todo
    //! Knowing whether `at_c` is fast for the zipped iterables could
    //! allow us to use this implementation only if it's faster than
    //! iterating to the given index.
    template <typename ...Iters, typename Index>
    struct at_impl<zip<Iters...>, Index>
        : list<at<Iters, Index>...>
    { };
#endif

    template <typename ...xs>
    struct concat
        : foldr<lift<concat>, list<>, list<xs...>>
    { };

    template <typename xs, typename ys>
    struct concat<xs, ys>
        : foldr<lift<cons>, ys, xs>
    { };

#if 0
    // We add strictly because there could be optimizations.
    template <typename ...Iters>
    struct length_impl<join<Iters...>>
        : plus<typename length<Iters>::type...>::type
    { };

    template <typename Iter1, typename ...IterN, typename F>
    struct unpack_impl<join<Iter1, IterN...>, F>
        : unpack<
            join<IterN...>,
            unpack<Iter1, partial<into<partial>, F>>
        >
    { };
#endif

    namespace list_detail {
        template <
            typename pred,
            typename xs,
            typename pivot = head<xs>,
            typename rest = tail<xs>,
            typename IsGreater = partial<pred, pivot>,
            typename IsSmallerEq = compose<lift<not_>, IsGreater>,
            typename SmallerEq = filter<IsSmallerEq, rest>,
            typename Greater = filter<IsGreater, rest>
        >
        using sort_by_impl = concat<
            sort_by<pred, SmallerEq>,
            cons<pivot, sort_by<pred, Greater>>
        >;
    }

    template <typename pred, typename xs>
    struct sort_by
        : if_c<or_<is_empty<xs>, is_empty<tail<xs>>>::value,
            xs,
            list_detail::sort_by_impl<pred, xs>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LIST_HPP
