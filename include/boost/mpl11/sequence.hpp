/*!
 * @file
 * Defines `boost::mpl11::Sequence`.
 */

#ifndef BOOST_MPL11_SEQUENCE_HPP
#define BOOST_MPL11_SEQUENCE_HPP

#include <boost/mpl11/fwd/sequence.hpp>

#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/detail/default_unpack.hpp>
#include <boost/mpl11/detail/lazy_init.hpp>
#include <boost/mpl11/detail/lexicographical_compare.hpp>
#include <boost/mpl11/detail/std_equal.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/sequence_traits.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace detail {
        template <typename S>
        struct check_usage<head<S>> {
            static_assert(!is_empty<S>::value,
            "Invalid usage of `head` on an empty sequence.");
        };

        template <typename S>
        struct check_usage<tail<S>> {
            static_assert(!is_empty<S>::value,
            "Invalid usage of `tail` on an empty sequence.");
        };

        template <typename S>
        struct check_usage<init<S>> {
            static_assert(!is_empty<S>::value,
            "Invalid usage of `init` on an empty sequence.");
        };

        template <typename S>
        struct check_usage<last<S>> {
            static_assert(!is_empty<S>::value,
            "Invalid usage of `last` on an empty sequence.");
        };

        template <typename S, typename Index>
        struct check_usage<at<S, Index>> {
            static_assert(Index::value >= 0,
            "Invalid usage of `at`: `Index` must be non-negative.");
        };

        template <typename S, detail::std_size_t Index>
        struct check_usage<at_c<S, Index>> {
        private:
            using Length = typename conditional<sequence_traits<S>::is_finite,
                length<S>, size_t<Index + 1>
            >::type;

            static_assert(Index < Length::value,
            "Invalid usage of `at_c`: "
            "Accessing a sequence at an out-of-bounds index.");
        };
    } // end namespace detail

    //////////////////////
    // Methods
    //////////////////////
    template <typename S>
    struct head : private BOOST_MPL11_CHECK_USAGE(head<S>) {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template head_impl<S>::type;
    };

    template <typename S>
    struct is_empty
        : Sequence<typename tag_of<S>::type>::
          template is_empty_impl<S>
    { };

    template <typename S>
    struct tail : private BOOST_MPL11_CHECK_USAGE(tail<S>) {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template tail_impl<S>::type;
    };

    template <typename S>
    struct init : private BOOST_MPL11_CHECK_USAGE(init<S>) {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template init_impl<S>::type;
    };

    template <typename S>
    struct last : private BOOST_MPL11_CHECK_USAGE(last<S>) {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template last_impl<S>::type;
    };

    template <typename S, typename Index>
    struct at : private BOOST_MPL11_CHECK_USAGE(at<S, Index>) {
        using type = typename at_c<S, Index::value>::type;
    };

    template <typename S, detail::std_size_t Index>
    struct at_c : private BOOST_MPL11_CHECK_USAGE(at_c<S, Index>) {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template at_c_impl<S, Index>::type;
    };

    template <typename S>
    struct length
        : Sequence<typename tag_of<S>::type>::
          template length_impl<S>
    { };

    template <typename S, typename F>
    struct unpack {
        using type = typename Sequence<typename tag_of<S>::type>::
                     template unpack_impl<S, F>::type;
    };

    //////////////////////
    // Instantiations
    //////////////////////
    template <>
    struct Sequence<sequence_tag> {
        template <typename S>
        using last_impl = typename detail::conditional<
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_HPP
