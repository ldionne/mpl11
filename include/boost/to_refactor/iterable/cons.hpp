/*!
 * @file
 * Defines `boost::mpl11::cons`.
 */

#ifndef BOOST_MPL11_ITERABLE_CONS_HPP
#define BOOST_MPL11_ITERABLE_CONS_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/detail/box.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/iterable.hpp>
#include <boost/mpl11/partial.hpp>


namespace boost { namespace mpl11 {
    template <typename Head, typename Tail>
    struct cons { using type = cons; };

    namespace detail { struct cons_tag; }

    template <typename Head, typename Tail>
    struct tag_of<cons<Head, Tail>> { using type = detail::cons_tag; };

    template <typename Head, typename Tail>
    struct sequence_traits<cons<Head, Tail>>
        : sequence_traits<typename Tail::type>
    { };

    template <typename Tag>
    struct Orderable<detail::cons_tag, Tag>
        : Orderable<iterable_tag, Tag>
    { };

    template <typename Tag>
    struct Comparable<detail::cons_tag, Tag>
        : Comparable<iterable_tag, Tag>
    { };

    template <>
    struct Foldable<detail::cons_tag>
        : Foldable<iterable_tag>
    { };

    template <>
    struct Functor<detail::cons_tag>
        : Functor<iterable_tag>
    { };

    template <>
    struct Iterable<detail::cons_tag> : Iterable<iterable_tag> {
        template <typename>           struct head_impl;
        template <typename>           struct tail_impl;
        template <typename>           struct length_impl;
        template <typename, typename> struct unpack_impl;

        template <typename Head, typename Tail>
        struct head_impl<cons<Head, Tail>> : Head { };

        template <typename Head, typename Tail>
        struct tail_impl<cons<Head, Tail>> : Tail { };

        template <typename Cons>
        using is_empty_impl = false_;

        template <typename Head, typename Tail>
        struct length_impl<cons<Head, Tail>>
            : size_t<length<Tail>::value + 1>
        { };

        template <typename Head, typename Tail, typename F>
        struct unpack_impl<cons<Head, Tail>, F>
            : unpack<Tail, partial<detail::box<F>, Head>>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_CONS_HPP
