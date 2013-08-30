/*!
 * @file
 * Defines `boost::mpl11::erase`.
 */

#ifndef BOOST_MPL11_ERASE_HPP
#define BOOST_MPL11_ERASE_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/copy.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/joint_view.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace erase_detail {
template <typename Sequence, typename First, typename Last,
          bool = is_same<Last, typename end<Sequence>::type>::value>
struct copy_except
    : copy<
        iterator_range<typename begin<Sequence>::type, First>,
        typename clear<Sequence>::type
    >
{ };

template <typename Sequence, typename First, typename Last>
struct copy_except<Sequence, First, Last, false>
    : copy<
        joint_view<
            iterator_range<
                typename begin<Sequence>::type, First
            >,
            iterator_range<
                typename next<Last>::type, typename end<Sequence>::type
            >
        >,
        typename clear<Sequence>::type
    >
{ };

template <typename Sequence, typename First, typename Last>
struct erase_impl
    : copy_except<Sequence, First, Last>
{ };
} // end namespace erase_detail

template <typename Sequence, typename First, typename Last = detail::optional>
struct erase;

/*!
 * Removes several adjacent elements in a sequence starting from an
 * arbitrary position.
 *
 * The default implementation is equivalent to copying the whole sequence
 * except for the content of the range delimited by `[First, Last)`.
 *
 * @warning
 * Differences from the original MPL:
 * - It is possible to erase a range of elements in an associative sequence.
 */
template <typename Sequence, typename First, typename Last>
struct erase BOOST_MPL11_DOXYGEN_ONLY(<Sequence, First, Last>)
    : detail::tag_dispatched<tag::erase, Sequence, First, Last>::template
      with_default<erase_detail::erase_impl<_1, _2, _3>>
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
      with_default<erase<_1, _2, next<_2>>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_HPP
