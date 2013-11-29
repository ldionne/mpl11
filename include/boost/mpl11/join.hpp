/*!
 * @file
 * Defines `boost::mpl11::join`.
 */

#ifndef BOOST_MPL11_JOIN_HPP
#define BOOST_MPL11_JOIN_HPP

#include <boost/mpl11/fwd/join.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/curry.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
namespace join_detail {
    template <typename First, typename Last, typename Next>
    struct join_iter_impl;

    template <typename First, typename Last, typename Next>
    using join_iterator = typename detail::conditional<
        equal<First, Last>::value,
        Next,
        identity<join_iter_impl<First, Last, Next>>
    >::type::type;

    struct join_iterator_class final : ForwardIterator {
        template <typename Iterator> struct deref_impl;
        template <typename Iterator> struct next_impl;

        template <typename First, typename Last, typename Next>
        struct deref_impl<join_iter_impl<First, Last, Next>>
            : deref<First>
        { };

        template <typename First, typename Last, typename Next>
        struct next_impl<join_iter_impl<First, Last, Next>> {
            using type = join_iterator<next_t<First>, Last, Next>;
        };

        template <typename Self, typename Other>
        struct equal_impl
            : false_
        { };

        template <
            typename F1, typename L1, typename N1,
            typename F2, typename L2, typename N2>
        struct equal_impl<
            join_iter_impl<F1, L1, N1>,
            join_iter_impl<F2, L2, N2>
        >
            : equal<F1, F2>
        { };
    };

    struct join_class final : Sequence {
        template <typename Join> struct begin_impl;
        template <typename Join> struct end_impl;

        template <typename S1, typename S2, typename S3, typename ...Sn>
        struct begin_impl<join<S1, S2, S3, Sn...>> {
            using type = join_iterator<
                begin_t<S1>, end_t<S1>, begin_impl<join<S2, S3, Sn...>>
            >;
        };

        template <typename S1, typename S2>
        struct begin_impl<join<S1, S2>> {
            using type = join_iterator<
                begin_t<S1>, end_t<S1>, begin<S2>
            >;
        };

        template <typename S1, typename S2, typename ...Sn>
        struct end_impl<join<S1, S2, Sn...>>
            : end<apply_t<arg<sizeof...(Sn)>, S2, Sn...>>
        { };
    };
} // end namespace join_detail

template <typename First, typename Last, typename Next, typename Default>
struct class_of<join_detail::join_iter_impl<First, Last, Next>, Default> {
    using type = join_detail::join_iterator_class;
};

template <typename S1, typename S2, typename ...Sn, typename Default>
struct class_of<join<S1, S2, Sn...>, Default> {
    using type = join_detail::join_class;
};

template <typename S1, typename S2, typename ...Sn>
struct join
    : apply<new_<S1>, join<S1, S2, Sn...>>
{ };

template <typename S1, typename S2, typename S3, typename ...Sn, typename F>
struct unpack<join<S1, S2, S3, Sn...>, F>
    : unpack<
        join<S2, S3, Sn...>,
        unpack_t<S1, curry<into<curry>, F>>
    >
{ };

template <typename S1, typename S2, typename F>
struct unpack<join<S1, S2>, F>
    : unpack<S2, unpack_t<S1, curry<into<curry>, F>>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_JOIN_HPP
