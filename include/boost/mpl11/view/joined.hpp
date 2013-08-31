/*!
 * @file
 * Defines `boost::mpl11::view::joined`.
 */

#ifndef BOOST_MPL11_VIEW_JOINED_HPP
#define BOOST_MPL11_VIEW_JOINED_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace joined_detail {
    template <typename First1, typename Last1, typename First2>
    struct joined_iterator;

    template <typename OperationTag, typename F1, typename L1, typename F2>
    struct dispatch;

    template <typename F1, typename L1, typename F2>
    struct dispatch<tag::next, F1, L1, F2>
        : identity<
            joined_iterator<typename next<F1>::type, L1, F2>
        >
    { };

    template <typename L1, typename F2>
    struct dispatch<tag::next, L1, L1, F2>
        : identity<
            joined_iterator<L1, L1, typename next<F2>::type>
        >
    { };

    template <typename F1, typename L1, typename F2>
    struct dispatch<tag::deref, F1, L1, F2>
        : deref<F1>
    { };

    template <typename L1, typename F2>
    struct dispatch<tag::deref, L1, L1, F2>
        : deref<F2>
    { };

    template <typename F1, typename L1, typename F2>
    struct dispatch<tag::category_of, F1, L1, F2>
        : identity<category::forward_iterator>
    { };
} // end namespace joined_detail

template <typename OperationTag, typename F1, typename L1, typename L2>
struct dispatch<OperationTag, joined_detail::joined_iterator<F1, L1, L2>>
    : lazy_always<joined_detail::dispatch<OperationTag, F1, L1, L2>>
{ };

namespace view {
    /*!
     * @ingroup Views
     * A view into the sequence of elements formed by concatenating two
     * or more sequences.
     *
     * Regardless of the category of the underlying sequences, `joined`
     * is only a forward sequence.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct joined BOOST_MPL11_DOXYGEN_ONLY({ });
} // end namespace view

template <typename Op, typename S1, typename S2,typename...Sn,typename...Args>
struct dispatch<Op, view::joined<S1, S2, Sn...>, Args...>
    : dispatch<Op, view::joined<S1, view::joined<S2, Sn...>>, Args...>
{ };

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::category_of, view::joined<S1, S2, Sn...>>
    : always<category::forward_sequence>
{ };

template <typename S1, typename S2>
struct dispatch<tag::begin, view::joined<S1, S2>>
    : always<
        joined_detail::joined_iterator<
            typename begin<S1>::type,
            typename end<S1>::type,
            typename begin<S2>::type
        >
    >
{ };

template <typename S1, typename S2>
struct dispatch<tag::end, view::joined<S1, S2>>
    : always<
        joined_detail::joined_iterator<
            typename end<S1>::type,
            typename end<S1>::type,
            typename end<S2>::type
        >
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_JOINED_HPP
