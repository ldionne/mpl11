/*!
 * @file
 * Defines `boost::mpl11::detail::lazy_init`.
 */

#ifndef BOOST_MPL11_DETAIL_LAZY_INIT_HPP
#define BOOST_MPL11_DETAIL_LAZY_INIT_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns a lazy iterable implementing the default behavior
     * of the `init` method.
     *
     *
     * @invariant
     * `Iter` is never empty.
     */
    template <typename Iter>
    struct lazy_init;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/detail/box.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/iterable.hpp>


namespace boost { namespace mpl11 {
    namespace detail {
        template <typename Iter>
        struct lazy_init { using type = lazy_init; };

        struct lazy_init_tag;
    } // end namespace detail

    template <typename Iter>
    struct tag_of<detail::lazy_init<Iter>> {
        using type = detail::lazy_init_tag;
    };

    template <typename Iter>
    struct sequence_traits<detail::lazy_init<Iter>>
        : sequence_traits<typename Iter::type>
    {
        static constexpr bool has_O1_unpack = false;
    };

    template <typename Tag>
    struct Comparable<detail::lazy_init_tag, Tag>
        : Comparable<iterable_tag, Tag>
    { };

    template <typename Tag>
    struct Orderable<detail::lazy_init_tag, Tag>
        : Orderable<iterable_tag, Tag>
    { };

    template <>
    struct Functor<detail::lazy_init_tag>
        : Functor<iterable_tag>
    { };

    template <>
    struct Foldable<detail::lazy_init_tag>
        : Foldable<iterable_tag>
    { };

    template <>
    struct Iterable<detail::lazy_init_tag> : Iterable<iterable_tag> {
        template <typename>           struct head_impl;
        template <typename>           struct tail_impl;
        template <typename>           struct is_empty_impl;
        template <typename>           struct length_impl;
        template <typename, typename> struct at_impl;

        template <typename Iter>
        struct head_impl<detail::lazy_init<Iter>>
            : head<Iter>
        { };

        template <typename Iter>
        struct tail_impl<detail::lazy_init<Iter>>
            : detail::lazy_init<tail<Iter>>
        { };

        template <typename Iter>
        struct is_empty_impl<detail::lazy_init<Iter>>
            : is_empty<tail<Iter>>
        { };

        template <typename Iter>
        struct length_impl<detail::lazy_init<Iter>>
            : size_t<length<Iter>::value - 1>
        { };

        template <typename Iter, typename Index>
        struct at_impl<detail::lazy_init<Iter>, Index>
            : at<Iter, detail::box<Index>>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_LAZY_INIT_HPP
