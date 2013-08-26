/*!
 * @file
 * Defines `boost::mpl11::erase`.
 */

#ifndef BOOST_MPL11_ERASE_HPP
#define BOOST_MPL11_ERASE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 {
namespace erase_detail {
template <typename Sequence, typename First, typename Last, typename Insert,
          bool = is_same<Last, typename end<Sequence>::type>::value>
struct copy_except
    : copy<
        joint_view<
            iterator_range<
                typename begin<Sequence>::type, First
            >,
            iterator_range<
                typename next<Last>::type, typename end<Sequence>::type
            >
        >,
        inserter<typename clear<Sequence>::type, Insert>
    >
{ };

template <typename Sequence, typename First, typename Last, typename Insert>
struct copy_except<Sequence, First, Last, Insert, true>
    : copy<
        iterator_range<typename begin<Sequence>::type, First>,
        inserter<typename clear<Sequence>::type, Insert>
    >
{ };

template <typename Category, typename Sequence, typename First, typename Last>
struct erase_impl;

template <typename Sequence, typename First, typename Last>
struct erase_impl<tag::extensible, Sequence, First, Last>
    // what do we do for these?
{ };

template <typename Sequence, typename First, typename Last>
struct erase_impl<tag::associative_extensible, Sequence, First, Last>
    : copy_except<
        Sequence, First, Last, insert<_1, _2>
    >
{ };

template <typename Sequence, typename First, typename Last>
struct erase_impl<tag::front_extensible, Sequence, First, Last>
    : reverse_copy_except< // reversible algorithms: how to?
        Sequence, First, Last, push_front<_1, _2>
    >
{ };

template <typename Sequence, typename First, typename Last>
struct erase_impl<tag::back_extensible, Sequence, First, Last>
    : copy_except<
        Sequence, First, Last, push_back<_1, _2>
    >
{ };
#error finish implementing me
} // end namespace erase_detail

namespace tag { struct erase; }

template <typename Sequence, typename First, typename ...Last>
struct erase {
    static_assert(detail::always_false<Sequence, First, Last...>::value,
    "Too many arguments to `erase`. "
    "Usage is `erase<Sequence, First[, Last]>`.");

    struct type;
};

/*!
 * Removes several adjacent elements in a sequence starting from an
 * arbitrary position.
 *
 * The default implementation is equivalent to copying the whole sequence
 * except for the content of the range delimited by `[First, Last)`. When
 * copying, `Sequence` is first `clear`ed and then each element is inserted
 * using either `push_back`, `push_front` or `insert`, depending on the
 * extensibility category of `Sequence`.
 *
 * @warning
 * Differences from the original MPL:
 * - It is possible to erase a range of elements in an associative sequence.
 */
template <typename Sequence, typename First, typename Last>
struct erase<Sequence, First, Last>
    : detail::tag_dispatched<tag::erase, Sequence, First, Last>::template
      with_default<
        erase_detail::erase_impl<extensibility_category_of<_2>, _2, _3, _4>
      >
{ };

/*!
 * Removes an element at a position in a sequence.
 *
 * The default implementation is equivalent to
 * `erase<Sequence, Position, next<Position>::type>`.
 *
 * @warning
 * Differences from the original MPL:
 * - The default implementation is the same for associative sequences and
 *   other sequences.
 */
template <typename Sequence, typename Position>
struct erase<Sequence, Position>
    : detail::tag_dispatched<tag::erase, Sequence, Position>::template
      with_default<erase<_2, _3, next<_3>>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_HPP
