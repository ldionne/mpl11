/*!
 * @file
 * Defines `boost::mpl11::detail::lazy_fmap`.
 */

#ifndef BOOST_MPL11_DETAIL_LAZY_FMAP_HPP
#define BOOST_MPL11_DETAIL_LAZY_FMAP_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Lazy iterable mapping a metafunction class over an iterable.
     */
    template <typename F, typename Iter>
    struct lazy_fmap;
}}}


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/box.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/iterable/iterable.hpp>


namespace boost { namespace mpl11 {
    namespace detail {
        template <typename F, typename Iter>
        struct lazy_fmap { using type = lazy_fmap; };

        struct lazy_fmap_tag;
    } // end namespace detail

    template <typename F, typename Iter>
    struct tag_of<detail::lazy_fmap<F, Iter>> {
        using type = detail::lazy_fmap_tag;
    };

    template <typename F, typename Iter>
    struct sequence_traits<detail::lazy_fmap<F, Iter>>
        : sequence_traits<typename Iter::type>
    { };

    template <typename Tag>
    struct Comparable<detail::lazy_fmap_tag, Tag>
        : Comparable<iterable_tag, Tag>
    { };

    template <typename Tag>
    struct Orderable<detail::lazy_fmap_tag, Tag>
        : Orderable<iterable_tag, Tag>
    { };

    template <>
    struct Functor<detail::lazy_fmap_tag>
        : Functor<iterable_tag>
    { };

    template <>
    struct Foldable<detail::lazy_fmap_tag>
        : Foldable<iterable_tag>
    { };

    namespace lazy_fmap_detail {
        template <typename F, typename Dest>
        struct fast_map {
            using type = fast_map;
            template <typename ...Args>
            using apply = mpl11::apply<Dest, mpl11::apply<F, Args>...>;
        };
    }

    template <>
    struct Iterable<detail::lazy_fmap_tag> : Iterable<iterable_tag> {
        template <typename>           struct head_impl;
        template <typename>           struct last_impl;
        template <typename>           struct tail_impl;
        template <typename>           struct is_empty_impl;
        template <typename>           struct length_impl;
        template <typename, typename> struct at_impl;
        template <typename, typename> struct unpack_impl;

        template <typename F, typename Iter>
        struct head_impl<detail::lazy_fmap<F, Iter>>
            : apply<F, head<Iter>>
        { };

        template <typename F, typename Iter>
        struct last_impl<detail::lazy_fmap<F, Iter>>
            : apply<F, last<Iter>>
        { };

        template <typename F, typename Iter>
        struct tail_impl<detail::lazy_fmap<F, Iter>>
            : detail::lazy_fmap<F, tail<Iter>>
        { };

        template <typename F, typename Iter>
        struct is_empty_impl<detail::lazy_fmap<F, Iter>>
            : is_empty<Iter>
        { };

        template <typename F, typename Iter>
        struct length_impl<detail::lazy_fmap<F, Iter>>
            : length<Iter>
        { };

        template <typename F, typename Iter, typename Index>
        struct at_impl<detail::lazy_fmap<F, Iter>, Index>
            : apply<F, at<Iter, detail::box<Index>>>
        { };

        template <typename F, typename Iter, typename Dest>
        struct unpack_impl<detail::lazy_fmap<F, Iter>, Dest>
            : unpack<Iter, lazy_fmap_detail::fast_map<F, detail::box<Dest>>>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_LAZY_FMAP_HPP
