/*!
 * @file
 * Defines `boost::mpl11::take_while`.
 */

#ifndef BOOST_MPL11_TAKE_WHILE_HPP
#define BOOST_MPL11_TAKE_WHILE_HPP

#include <boost/mpl11/fwd/take_while.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
    template <typename P, typename S>
    struct take_while { using type = take_while; };

    template <typename P, typename S>
    struct tag_of<take_while<P, S>> { using type = sequence_tag; };

    /////////////////////////////////
    // Minimal complete definition
    /////////////////////////////////
    template <typename P, typename S>
    struct head<take_while<P, S>>
        : private BOOST_MPL11_CHECK_USAGE(head<take_while<P, S>>)
    {
        using type = typename head<S>::type;
    };

    template <typename P, typename S>
    struct tail<take_while<P, S>>
        : private BOOST_MPL11_CHECK_USAGE(tail<take_while<P, S>>)
    {
        using type = take_while<P, typename tail<S>::type>;
    };

    namespace take_while_detail {
        template <bool SeqIsEmpty>
        struct is_empty_impl;

        template <>
        struct is_empty_impl<true> {
            template <typename P, typename S>
            using result = true_;
        };

        template <>
        struct is_empty_impl<false> {
            template <typename P, typename S>
            using result = bool_<
                !apply<P, typename head<S>::type>::type::value
            >;
        };
    } // end namespace take_while_detail

    template <typename P, typename S>
    struct is_empty<take_while<P, S>>
        : take_while_detail::is_empty_impl<
            is_empty<S>::value
        >::template result<P, S>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TAKE_WHILE_HPP
