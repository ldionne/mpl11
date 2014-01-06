/*!
 * @file
 * Defines `boost::mpl11::drop_while`.
 */

#ifndef BOOST_MPL11_DROP_WHILE_HPP
#define BOOST_MPL11_DROP_WHILE_HPP

#include <boost/mpl11/fwd/drop_while.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/id.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
    template <typename P, typename S>
    struct drop_while { using type = drop_while; };

    template <typename P, typename S>
    struct tag_of<drop_while<P, S>> { using type = sequence_tag; };

    template <typename P, typename S>
    struct sequence_traits<drop_while<P, S>> {
        static constexpr bool is_finite = sequence_traits<S>::is_finite;
        static constexpr bool has_O1_length = false;
        static constexpr bool has_O1_unpack = false;
    };

    /////////////////////////////////
    // Minimal complete definition
    /////////////////////////////////
    namespace drop_while_detail {
        template <typename Predicate, typename Sequence,
            bool = is_empty<Sequence>::value>
        struct consume;

        template <typename Predicate, typename Sequence>
        struct consume<Predicate, Sequence, false>
            : if_c<
                apply<Predicate, typename head<Sequence>::type>::type::value,
                consume<Predicate, typename tail<Sequence>::type>,
                id<Sequence>
            >::type
        { };

        template <typename Predicate, typename Sequence>
        struct consume<Predicate, Sequence, true> {
            using type = Sequence;
        };
    } // end namespace drop_while_detail

    template <typename P, typename S>
    struct head_impl<drop_while<P, S>> {
        using type = typename head<
            typename drop_while_detail::consume<P, S>::type
        >::type;
    };

    template <typename P, typename S>
    struct tail_impl<drop_while<P, S>> {
        using type = typename tail<
            typename drop_while_detail::consume<P, S>::type
        >::type;
    };

    template <typename P, typename S>
    struct is_empty_impl<drop_while<P, S>>
        : is_empty<typename drop_while_detail::consume<P, S>::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DROP_WHILE_HPP
