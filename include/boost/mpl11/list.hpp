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
#include <boost/mpl11/detail/at_index/best.hpp>
#include <boost/mpl11/detail/config.hpp>
#include <boost/mpl11/detail/left_folds/variadic.hpp>
#include <boost/mpl11/detail/right_folds/variadic.hpp>
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
            : detail::at_index::best<n::type::value, xs...>
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

    template <typename f, typename x>
    struct iterate
        : cons<x, iterate<f, typename f::type::template apply<x>>>
    { };

    template <typename x>
    struct repeat
        : cons<x, repeat<x>>
    { };

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

    namespace list_detail {
        template <typename pred>
        struct take_while_op {
            using type = take_while_op;
            template <typename x, typename xs>
            using apply = if_c<
                (bool)pred::type::template apply<x>::type::value,
                cons<x, xs>,
                list<>
            >;
        };

        template <typename pred>
        struct filter_op {
            using type = filter_op;
            template <typename x, typename xs>
            using apply = if_c<
                (bool)pred::type::template apply<x>::type::value,
                cons<x, xs>,
                xs
            >;
        };
    }

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

    template <typename ...xs>
    struct concat
        : foldr<lift<concat>, list<>, list<xs...>>
    { };

    template <typename xs, typename ys>
    struct concat<xs, ys>
        : foldr<lift<cons>, ys, xs>
    { };

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

#ifndef BOOST_MPL11_NO_REWRITE_RULES
    template <typename f, typename state, typename ...xs>
    struct foldl<f, state, list<xs...>>
        : detail::left_folds::variadic<
            f::type::template apply, state, xs...
        >
    { };

    template <typename f, typename state, typename ...xs>
    struct foldr<f, state, list<xs...>>
        : detail::right_folds::variadic<
            f::type::template apply, state, xs...
        >
    { };

    // length/foldr
    //
    // length $ foldr (:) xs ys == length xs + length ys
    template <typename ...xs, typename ys>
    struct length<foldr<lift<cons>, list<xs...>, ys>>
        : size_t<length<ys>::value + sizeof...(xs)>
    { };

    // at/repeat
    template <typename index, typename x>
    struct at<index, repeat<x>> : x { };
#endif // end rewrite rules
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LIST_HPP
