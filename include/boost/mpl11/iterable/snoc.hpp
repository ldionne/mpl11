/*!
 * @file
 * Defines `boost::mpl11::snoc`.
 */

#ifndef BOOST_MPL11_ITERABLE_SNOC_HPP
#define BOOST_MPL11_ITERABLE_SNOC_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/box.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/iterable/iterable.hpp>
#include <boost/mpl11/list.hpp>
#include <boost/mpl11/partial.hpp>


namespace boost { namespace mpl11 {
    namespace detail { struct snoc_tag; }

    template <typename Init, typename Last>
    struct snoc
        : if_<is_empty<Init>,
            list<Last>

        , else_<
            detail::box<snoc<Init, Last>>
        >>
    { using mpl_tag = detail::snoc_tag; };

    template <typename Tag>
    struct Comparable<detail::snoc_tag, Tag>
        : Comparable<iterable_tag, Tag>
    { };

    template <typename Tag>
    struct Orderable<detail::snoc_tag, Tag>
        : Orderable<iterable_tag, Tag>
    { };

    template <>
    struct Functor<detail::snoc_tag>
        : Functor<iterable_tag>
    { };

    template <>
    struct Foldable<detail::snoc_tag>
        : Foldable<iterable_tag>
    { };

    template <>
    struct Iterable<detail::snoc_tag> : Iterable<iterable_tag> {
        template <typename>            struct head_impl;
        template <typename>            struct tail_impl;
        template <typename>            struct length_impl;
        template <typename>            struct last_impl;
        template <typename>            struct init_impl;
        template <typename, typename > struct unpack_impl;

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
    };

    template <typename Init, typename Last>
    struct sequence_traits<snoc<Init, Last>>
        : sequence_traits<typename Init::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_SNOC_HPP
