/*!
 * @file
 * Defines `boost::mpl11::scanl`.
 */

#ifndef BOOST_MPL11_SCANL_HPP
#define BOOST_MPL11_SCANL_HPP

#include <boost/mpl11/fwd/scanl.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename State, typename S>
    struct scanl { using type = scanl; };

    template <typename F, typename State, typename S>
    struct tag_of<scanl<F, State, S>> { using type = sequence_tag; };

    template <typename F, typename State, typename S>
    struct sequence_traits<scanl<F, State, S>> : sequence_traits<S> {
        static constexpr bool has_O1_unpack = false;
    };

    /////////////////////////////////
    // Minimal complete definition
    /////////////////////////////////
    template <typename F, typename State, typename S>
    struct head<scanl<F, State, S>> {
        using type = State;
    };

    namespace scanl_detail {
        template <bool IsUnary>
        struct scanl_helper;

        template <>
        struct scanl_helper<true> {
            template <typename F, typename State, typename S>
            using tail_impl = S;

            template <typename F, typename State, typename S>
            using init_impl = S;
        };

        template <>
        struct scanl_helper<false> {
            template <typename F, typename State, typename S>
            using tail_impl = scanl<
                F,
                typename apply<F, State, typename head<S>::type>::type,
                typename tail<S>::type
            >;

            template <typename F, typename State, typename S>
            using init_impl = scanl<F, State, typename init<S>::type>;
        };
    } // end namespace scanl_detail

    template <typename F, typename State, typename S>
    struct tail<scanl<F, State, S>> {
        using type = typename scanl_detail::scanl_helper<
            is_empty<S>::value
        >::template tail_impl<F, State, S>;
    };

    template <typename F, typename State, typename S>
    struct is_empty<scanl<F, State, S>>
        : false_
    { };

    template <typename F, typename State, typename S>
    struct length<scanl<F, State, S>>
        : size_t<length<S>::value + 1>
    { };


    /////////////////////////////////
    // Optimizations
    /////////////////////////////////
    template <typename F, typename State, typename S>
    struct last<scanl<F, State, S>> {
        using type = typename foldl<F, State, S>::type;
    };

    template <typename F, typename State, typename S>
    struct init<scanl<F, State, S>> {
        using type = typename scanl_detail::scanl_helper<
            is_empty<S>::value
        >::template init_impl<F, State, S>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SCANL_HPP
