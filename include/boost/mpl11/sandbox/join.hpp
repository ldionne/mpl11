/*!
 * @file
 * Defines `boost::mpl11::join`.
 */

#ifndef BOOST_MPL11_JOIN_HPP
#define BOOST_MPL11_JOIN_HPP

#include <boost/mpl11/fwd/join.hpp>


namespace boost { namespace mpl11 {
namespace join_detail {
    // - have a join iterator taking advantage of O(1) size of a sequence.
    // - take advantage of O(1) unpack in join<>

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
        struct equal_impl<join_iter_impl<F1, L1, N1>, join_iter_impl<F2, L2, N2>>
            : equal<F1, F2>
        { };
    };

    struct join_class final : Sequence {
        template <typename Join> struct begin_impl;
        template <typename Join> struct end_impl;
        template <typename Join> struct size_impl;

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
            : end<back_t<vector<S2, Sn...>>>
        { };

        template <typename S1, typename S2, typename ...Sn>
        struct size_impl<join<S1, S2, Sn...>>
            : add<size<S1>, size<S2>, size<Sn>...>
        { };
    };
} // end namespace join_detail

template <typename Sequence1, typename Sequence2, typename ...SequenceN>
struct join
    : new_<Sequence1, join<Sequence1, Sequence2, SequenceN...>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_JOIN_HPP
