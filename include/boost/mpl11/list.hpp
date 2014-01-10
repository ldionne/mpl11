/*!
 * @file
 * Defines `boost::mpl11::list`.
 */

#ifndef BOOST_MPL11_LIST_HPP
#define BOOST_MPL11_LIST_HPP

#include <boost/mpl11/fwd/list.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/index_sequence.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/detail/variadic_last.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/iterable.hpp>


namespace boost { namespace mpl11 {
    namespace detail {
        template <std_size_t Index, typename Value>
        struct list_index_holder { };

        template <typename Indices, typename ...T>
        struct list_index_based_lookup;

        template <std_size_t ...Indices, typename ...T>
        struct list_index_based_lookup<index_sequence<Indices...>, T...>
            : list_index_holder<Indices, T>...
        { };

        template <std_size_t Index, typename Value>
        Value at_list_index(list_index_holder<Index, Value>*);

        template <typename ...T>
        struct list_impl
            : list_index_based_lookup<
                typename make_index_sequence<sizeof...(T)>::type, T...
            >
        { };

        struct list_tag;
    } // end namespace detail

    template <typename ...T>
    struct list { using type = detail::list_impl<T...>; };

    template <typename ...T>
    struct tag_of<detail::list_impl<T...>> { using type = detail::list_tag; };

    template <typename ...T>
    struct sequence_traits<detail::list_impl<T...>> {
        static constexpr bool has_O1_length = true;
        static constexpr bool has_O1_unpack = true;
        static constexpr bool is_finite = true;
    };

    template <typename Tag>
    struct Comparable<detail::list_tag, Tag>
        : Comparable<iterable_tag, Tag>
    { };

    template <typename Tag>
    struct Orderable<detail::list_tag, Tag>
        : Orderable<iterable_tag, Tag>
    { };

    template <>
    struct Foldable<detail::list_tag>
        : Foldable<iterable_tag>
    { };

    template <>
    struct Functor<detail::list_tag> {
        template <typename, typename> struct fmap_impl;

        template <typename F, typename ...T>
        struct fmap_impl<F, detail::list_impl<T...>> {
            using type = detail::list_impl<apply<F, T>...>;
        };
    };

    template <>
    struct Iterable<detail::list_tag> : Iterable<iterable_tag> {
        template <typename>           struct head_impl;
        template <typename>           struct tail_impl;
        template <typename>           struct is_empty_impl;
        template <typename>           struct length_impl;
        template <typename, typename> struct unpack_impl;
        template <typename>           struct last_impl;
        template <typename, typename> struct at_impl;

        template <typename Head, typename ...Tail>
        struct head_impl<detail::list_impl<Head, Tail...>>
            : Head
        { };

        template <typename Head, typename ...Tail>
        struct tail_impl<detail::list_impl<Head, Tail...>> {
            using type = detail::list_impl<Tail...>;
        };

        template <typename ...T>
        struct is_empty_impl<detail::list_impl<T...>>
            : false_
        { };

        template <typename ...T>
        struct length_impl<detail::list_impl<T...>>
            : size_t<sizeof...(T)>
        { };

        template <typename ...T, typename F>
        struct unpack_impl<detail::list_impl<T...>, F>
            : apply<F, T...>
        { };

        template <typename Head, typename ...Tail>
        struct last_impl<detail::list_impl<Head, Tail...>>
            : detail::variadic_last<Head, Tail...>
        { };

        template <typename ...T, typename Index>
        struct at_impl<detail::list_impl<T...>, Index> {
            using type = typename decltype(
                detail::at_list_index<Index::type::value>(
                    (detail::list_impl<T...>*)nullptr
                )
            )::type;
        };
    };

    template <>
    struct Iterable<detail::list_tag>::is_empty_impl<detail::list_impl<>>
        : true_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LIST_HPP
