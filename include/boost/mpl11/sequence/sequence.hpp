/*!
 * @file
 * Defines the methods of the @ref Sequence typeclass.
 */

#ifndef BOOST_MPL11_SEQUENCE_SEQUENCE_HPP
#define BOOST_MPL11_SEQUENCE_SEQUENCE_HPP

#include <boost/mpl11/fwd/sequence.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/default_unpack.hpp>
#include <boost/mpl11/detail/lazy_init.hpp>
#include <boost/mpl11/detail/lexicographical_compare.hpp>
#include <boost/mpl11/detail/sequence_map.hpp>
#include <boost/mpl11/detail/std_equal.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/foldable.hpp>
#include <boost/mpl11/functor.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/sequence_traits.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct head_impl {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template head_impl<S>::type;
    };

    template <typename S>
    struct tail_impl {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template tail_impl<S>::type;
    };

    template <typename S>
    struct init_impl {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template init_impl<S>::type;
    };

    template <typename S>
    struct last_impl {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template last_impl<S>::type;
    };

    template <typename S>
    struct is_empty_impl
        : Sequence<typename tag_of<S>::type>::template is_empty_impl<S>
    { };

    template <typename S>
    struct length_impl
        : Sequence<typename tag_of<S>::type>::template length_impl<S>
    { };

    template <typename S, detail::std_size_t Index>
    struct at_c_impl {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template at_c_impl<S, Index>::type;
    };

    template <typename S, typename F>
    struct unpack_impl {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template unpack_impl<S, F>::type;
    };

    template <typename S, typename Index>
    struct at {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
        static_assert(Index::value >= 0,
        "Invalid usage of `at` with a negative index.");
#endif
        using type = typename at_c<S, Index::value>::type;
    };

#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
    template <typename S>
    struct head {
        static_assert(!is_empty<S>::value,
        "Invalid usage of `head` on an empty sequence.");
        using type = typename head_impl<S>::type;
    };

    template <typename S>
    struct tail {
        static_assert(!is_empty<S>::value,
        "Invalid usage of `tail` on an empty sequence.");
        using type = typename tail_impl<S>::type;
    };

    template <typename S>
    struct init {
        static_assert(!is_empty<S>::value,
        "Invalid usage of `init` on an empty sequence.");
        using type = typename init_impl<S>::type;
    };

    template <typename S>
    struct last {
        static_assert(!is_empty<S>::value,
        "Invalid usage of `last` on an empty sequence.");
        using type = typename last_impl<S>::type;
    };

    template <typename S, detail::std_size_t Index>
    struct at_c {
    private:
        using Length = typename if_c<sequence_traits<S>::is_finite,
            length<S>,
            size_t<Index + 1>
        >::type;

        static_assert(Index < Length::value,
        "Invalid usage of `at_c` with an out-of-bounds index.");

    public:
        using type = typename at_c_impl<S, Index>::type;
    };
#endif

    //////////////////////
    // Instantiations
    //////////////////////
    template <>
    struct Sequence<sequence_tag> {
        template <typename S>
        using last_impl = typename if_c<
            is_empty<typename tail<S>::type>::value,
            head<S>,
            last<typename tail<S>::type>
        >::type;

        template <typename S>
        using init_impl = detail::lazy_init<S>;

        template <typename S, detail::std_size_t Index>
        struct at_c_impl {
            using type = typename at_c<
                typename tail<S>::type, Index - 1
            >::type;
        };

        template <typename S>
        struct at_c_impl<S, 0> {
            using type = typename head<S>::type;
        };

    private:
        //! @todo Create a proper `succ` metafunction.
        struct succ {
            template <typename N, typename>
            using apply = size_t<N::value + 1>;
        };

    public:
        //! @todo We uselessly call `head` on each step. Fix this.
        template <typename S>
        using length_impl = typename foldl<succ, size_t<0>, S>::type;

        template <typename S, typename F>
        using unpack_impl = detail::default_unpack<S, F>;
    };

    template <>
    struct Comparable<sequence_tag, sequence_tag>
        : Comparable<comparable_tag>
    {
        template <typename S1, typename S2>
        using equal_impl = detail::std_equal<S1, S2>;
    };

    template <typename Tag>
    struct Comparable<sequence_tag, Tag>
        : detail::flip_Comparable<sequence_tag, Tag>
    { };

    template <>
    struct Orderable<sequence_tag, sequence_tag>
        : Orderable<orderable_tag>
    {
        template <typename S1, typename S2>
        using less_impl = detail::lexicographical_compare<S1, S2>;
    };

    template <typename Tag>
    struct Orderable<sequence_tag, Tag>
        : detail::flip_Orderable<sequence_tag, Tag>
    { };

    template <>
    struct Foldable<sequence_tag> {
        template <
            typename F, typename State, typename S,
            bool = is_empty<S>::value
        >
        struct foldl_impl;

        template <typename F, typename State, typename S>
        struct foldl_impl<F, State, S, true> {
            using type = State;
        };

        template <typename F, typename State, typename S>
        struct foldl_impl<F, State, S, false> {
            using type = typename foldl_impl<
                F,
                typename apply<F, State, typename head<S>::type>::type,
                typename tail<S>::type
            >::type;
        };

        template <
            typename F, typename State, typename S,
            bool = is_empty<S>::value
        >
        struct foldr_impl;

        template <typename F, typename State, typename S>
        struct foldr_impl<F, State, S, true> {
            using type = State;
        };

        template <typename F, typename State, typename S>
        struct foldr_impl<F, State, S, false> {
            using type = typename apply<
                F,
                typename head<S>::type,
                typename foldr_impl<F, State ,typename tail<S>::type>::type
            >::type;
        };

        template <
            typename F, typename State, typename S,
            bool = is_empty<S>::value
        >
        struct lazy_foldr_impl;

        template <typename F, typename State, typename S>
        struct lazy_foldr_impl<F, State, S, true> {
            using type = State;
        };

        template <typename F, typename State, typename S>
        struct lazy_foldr_impl<F, State, S, false> {
            using type = typename apply<
                F,
                typename head<S>::type,
                lazy_foldr_impl<F, State ,typename tail<S>::type>
            >::type;
        };
    };

    template <>
    struct Functor<sequence_tag> {
        template <typename F, typename S>
        struct map_impl {
            using type = detail::sequence_map<F, S>;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_SEQUENCE_HPP
