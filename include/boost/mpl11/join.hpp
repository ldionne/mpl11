/*!
 * @file
 * Defines `boost::mpl11::join`.
 */

#ifndef BOOST_MPL11_JOIN_HPP
#define BOOST_MPL11_JOIN_HPP

#include <boost/mpl11/fwd/join.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/compose.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/filter.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/id.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/list.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
    //! @internal
    //! After the lazy `join` is created, it never contains  empty sequences.
    //! We make sure to preserve that invariant in the methods below because
    //! it makes the implementation much easier.
    template <typename S1, typename ...Sn>
    struct join<S1, Sn...> {
        using NonEmpty = filter_t<
            compose<quote<not_>, quote<is_empty>>,
            list<S1, Sn...>
        >;

        using type = typename if_c<is_empty<NonEmpty>::value,
            id<empty_sequence>,
            unpack<NonEmpty, into<mpl11::join>>
        >::type::type;
    };

    template <>           struct join<> { using type = empty_sequence; };
    template <typename S> struct join<S> { using type = S; };

    template <typename ...Sn>
    struct tag_of<join<Sn...>> { using type = sequence_tag; };

    template <typename ...Sn>
    struct sequence_traits<join<Sn...>> {
        static constexpr bool has_O1_length = and_<
            bool_<sequence_traits<Sn>::has_O1_length>...
        >::value;

        static constexpr bool has_O1_unpack = and_<
            bool_<sequence_traits<Sn>::has_O1_unpack>...
        >::value;

        static constexpr bool is_finite = and_<
            bool_<sequence_traits<Sn>::is_finite>...
        >::value;
    };

    template <typename S1, typename ...Sn>
    struct head_impl<join<S1, Sn...>> {
        using type = typename head<S1>::type;
    };

    template <typename S1, typename ...Sn>
    struct tail_impl<join<S1, Sn...>> {
        using type = typename join<typename tail<S1>::type, Sn...>::type;
    };

    template <typename ...Sn>
    struct is_empty_impl<join<Sn...>>
        : false_
    { };

    namespace join_detail {
        template <typename X, typename Y>
        using add = integral_c<
            decltype(X::value + Y::value),
            X::value + Y::value
        >;
    }

    //! @todo Use the variadic `add` here when ready.
    template <typename ...Sn>
    struct length_impl<join<Sn...>>
        : foldl<
            quote<join_detail::add>,
            size_t<0>,
            list<typename length<Sn>::type...>
        >::type
    { };

    template <typename S1, typename ...Sn, typename F>
    struct unpack_impl<join<S1, Sn...>, F> {
        using type = typename unpack<
            typename join<Sn...>::type,
            typename unpack<S1, partial<into<partial>, F>>::type
        >::type;
    };

    template <typename ...Sn>
    struct last_impl<join<Sn...>> {
        using type = typename last<
            typename last<list<Sn...>>::type
        >::type;
    };

    namespace join_detail {
        template <detail::std_size_t Index, typename S1, typename ...Sn>
        struct at_impl {
            template <bool = (Index < length<S1>::value), typename = void>
            struct apply;

            template <typename Dummy>
            struct apply<true, Dummy>
                : at_c<S1, Index>
            { };

            template <typename Dummy>
            struct apply<false, Dummy>
                : at_impl<Index - length<S1>::value, Sn...>::
                  template apply<>
            { };
        };
    } // end namespace join_detail

    template <typename ...Sn, detail::std_size_t Index>
    struct at_c_impl<join<Sn...>, Index> {
        using type = typename join_detail::at_impl<Index, Sn...>::
                     template apply<>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_JOIN_HPP
