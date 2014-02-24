/*!
 * @file
 * Defines the @ref Iterable typeclass.
 */

#ifndef BOOST_MPL11_ITERABLE_HPP
#define BOOST_MPL11_ITERABLE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/foldable.hpp>
#include <boost/mpl11/functional.hpp> //
#include <boost/mpl11/integer.hpp>    // required by fwd/iterable.hpp
#include <boost/mpl11/logical.hpp>    //


namespace boost { namespace mpl11 {
namespace iterable_detail {
    template <detail::std_size_t n, typename iter,
        bool = n == 0 || is_empty<iter>::value>
    struct drop_impl;

    template <detail::std_size_t n, typename iter>
    struct drop_impl<n, iter, true> : iter { };

    template <detail::std_size_t n, typename iter>
    struct drop_impl<n, iter, false>
        : drop_impl<n-1, tail<iter>>
    { };


    template <typename pred, typename iter, bool = is_empty<iter>::value>
    struct drop_while_impl1;

    template <typename pred, typename iter,
        bool = pred::type::template apply<head<iter>>::type::value>
    struct drop_while_impl2;

    template <typename pred, typename iter>
    struct drop_while_impl1<pred, iter, false>
        : drop_while_impl2<pred, iter>
    { };

    template <typename pred, typename iter>
    struct drop_while_impl1<pred, iter, true> : iter { };

    template <typename pred, typename iter>
    struct drop_while_impl2<pred, iter, true>
        : drop_while_impl1<pred, tail<iter>>
    { };

    template <typename pred, typename iter>
    struct drop_while_impl2<pred, iter, false> : iter { };
} // end namespace iterable_detail

template <typename pred, typename iter>
struct drop_while : iterable_detail::drop_while_impl1<pred, iter> { };

#if 0
    template <typename N, typename Iter, typename>
    struct drop_impl
        : if_<or_<bool_<N::type::value == 0>, is_empty<Iter>>,
            Iter,
            drop<pred<N>, tail<Iter>>
        >
    { };

    template <typename N1, typename N2, typename Iter>
    struct drop_impl<N1, drop<N2, Iter>> : drop<plus<N1, N2>, Iter> { };

    template <typename N, typename Iter>
    struct head_impl<drop<N, Iter>> : at<Iter, N> { };

    template <typename N, typename Iter>
    struct is_empty_impl<drop<N, Iter>
        , bool_<sequence_traits<typename Iter::type>::has_O1_length>
    >
        : bool_<(N::type::value >= length<Iter>::value)>
    { };

    template <typename N, typename Iter>
    struct length_impl<drop<N, Iter>>
        : size_t<(
            N::type::value < length<Iter>::value
                ? length<Iter>::value - N::type::value
                : 0
        )>
    { };

    template <typename N, typename Iter>
    struct last_impl<drop<N, Iter>> : last<Iter> { };

    template <typename N, typename Iter, typename Index>
    struct at_impl<drop<N, Iter>, Index> : at<Iter, plus<N, Index>> { };

    template <typename Pred, typename Iter>
    struct is_empty_impl<drop_until<Pred, Iter>> : none<Pred, Iter> { };

    template <typename Pred, typename Iter>
    struct is_empty_impl<drop_while<Pred, Iter>> : all<Pred, Iter> { };
#endif

namespace detail {
    namespace impls {
        template <typename iter>
        struct head
            : Iterable<typename datatype<typename iter::type>::type>::
              template head_impl<iter>
        { };

        template <typename iter>
        struct tail
            : Iterable<typename datatype<typename iter::type>::type>::
              template tail_impl<iter>
        { };

        template <typename n, typename iter>
        struct drop
            : iterable_detail::drop_impl<n::type::value, iter>
        { };

        template <typename iter>
        struct last :
            Iterable<typename datatype<typename iter::type>::type>::
            template last_impl<iter>
        { };

        template <typename index, typename iter>
        struct at :
            Iterable<typename datatype<typename iter::type>::type>::
            template at_impl<index, iter>
        { };
    }

    namespace checked_ns {
        template <typename iter>
        struct head {
            static_assert(!is_empty<iter>::value,
            "Invalid usage of `head` on an empty iterable.");
            using type = typename rules::head<iter>::type;
        };

        template <typename iter>
        struct tail {
            static_assert(!is_empty<iter>::value,
            "Invalid usage of `tail` on an empty iterable.");
            using type = typename rules::tail<iter>::type;
        };

        template <typename n, typename iter>
        struct drop {
            static_assert(n::type::value >= 0,
            "Invalid usage of `drop`: "
            "The number of elements to drop must be non-negative.");
            using type = typename rules::drop<n, iter>::type;
        };

        template <typename iter>
        struct last {
            static_assert(!is_empty<iter>::value,
            "Invalid usage of `last` on an empty iterable.");
            using type = typename rules::last<iter>::type;
        };

        template <typename index, typename iter>
        struct at {
        private:
            static_assert(index::type::value >= 0,
            "Invalid usage of `at` with a negative index.");

        #if 0
            using Length = if_c<sequence_traits<typename Iter::type>::is_finite,
                length<Iter>,
                size_t<index::type::value + 1>
            >;

            static_assert(index::type::value < Length::value,
            "Invalid usage of `at` with an out-of-bounds index.");
        #endif

        public:
            using type = typename rules::at<index, iter>::type;
        };
    }
} // end namespace detail

template <typename iter>
struct is_empty :
    Iterable<typename datatype<typename iter::type>::type>::
    template is_empty_impl<iter>
{ };

template <typename iter>
struct length :
    Iterable<typename datatype<typename iter::type>::type>::
    template length_impl<iter>
{ };

template <typename Datatype>
struct Iterable : false_ { };

struct default_Iterable : true_ {
    template <typename xs, bool = is_empty<tail<xs>>::value>
    struct last_impl : head<xs> { };

    template <typename xs>
    struct last_impl<xs, false>
        : last_impl<tail<xs>>
    { };


    template <typename index, typename xs, bool = index::type::value == 0>
    struct at_impl
        : head<xs>
    { };

    template <typename index, typename xs>
    struct at_impl<index, xs, false>
        : at_impl<size_t<index::type::value - 1>, tail<xs>>
    { };


    template <typename xs, detail::std_size_t acc = 0,
        bool = is_empty<xs>::value>
    struct length_impl : size_t<acc> { };

    template <typename xs, detail::std_size_t acc>
    struct length_impl<xs, acc, false>
        : length_impl<tail<xs>, acc+1>
    { };
};

template <typename X, typename Y>
struct Comparable<X, Y, bool_<Iterable<X>::value && Iterable<Y>::value>>
    : Comparable<default_<void>>
{
    template <typename xs, typename ys,
        bool xs_done = is_empty<xs>::value,
        bool ys_done = is_empty<ys>::value>
    struct equal_impl
        : bool_<xs_done && ys_done>
    { };

    template <typename xs, typename ys>
    struct equal_impl<xs, ys, false, false>
        : and_<
            equal<head<xs>, head<ys>>,
            equal_impl<tail<xs>, tail<ys>>
        >
    { };
};

template <typename Datatype>
struct Foldable<Datatype, typename Iterable<Datatype>::type> {
    template <typename f, typename state, typename iter>
    struct foldl_impl
        : if_<is_empty<iter>,
            state,
            foldl_impl<f, apply<f, state, head<iter>>, tail<iter>>
        >
    { };

    template <typename f, typename state, typename iter>
    struct foldr_impl
        : if_<is_empty<iter>,
            state,
            apply<f, head<iter>, foldr_impl<f, state, tail<iter>>>
        >
    { };
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_HPP
