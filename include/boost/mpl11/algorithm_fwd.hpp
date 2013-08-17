/*!
 * @file
 * This header contains the forward declaration of all the algorithms.
 */

#ifndef BOOST_MPL11_ALGORITHM_FWD_HPP
#define BOOST_MPL11_ALGORITHM_FWD_HPP

namespace boost { namespace mpl11 {
namespace algorithm {
    struct advance;
    struct any_of;
    struct copy;
    struct distance;
    struct foldl;
    struct foldr;
    struct iter_foldl;
    struct iter_foldr;
    struct none_of;
    struct transform;
}

template <typename Iterator, typename N>
struct advance;

template <typename Sequence, typename Pred>
struct any_of;

template <typename Sequence, typename Inserter>
struct copy;

template <typename First, typename Last>
struct distance;

template <typename Sequence, typename State, typename BinaryOp>
struct foldl;

template <typename Sequence, typename State, typename BinaryOp>
struct foldr;

template <typename Sequence, typename State, typename BinaryOp>
struct iter_foldl;

template <typename Sequence, typename State, typename BinaryOp>
struct iter_foldr;

template <typename Sequence, typename Pred>
struct none_of;

template <typename Sequence, typename F, typename Inserter>
struct transform;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_FWD_HPP
