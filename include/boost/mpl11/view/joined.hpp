/*!
 * @file
 * Defines `boost::mpl11::view::joined`.
 */

#ifndef BOOST_MPL11_VIEW_JOINED_HPP
#define BOOST_MPL11_VIEW_JOINED_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace joined_detail {
    template <typename First1, typename Last1, typename First2>
    struct joined_iterator;

    template <typename Op, typename F1, typename L1, typename F2,
              bool = intrinsic::equal_to<F1, L1>::type::value>
    struct dispatch;

    template <typename F1, typename L1, typename F2>
    struct dispatch<tag::next, F1, L1, F2, false>
        : identity<
            joined_iterator<typename intrinsic::next<F1>::type, L1, F2>
        >
    { };

    template <typename F1, typename L1, typename F2>
    struct dispatch<tag::next, F1, L1, F2, true>
        : identity<
            joined_iterator<F1, L1, typename intrinsic::next<F2>::type>
        >
    { };

    template <typename F1, typename L1, typename F2>
    struct dispatch<tag::deref, F1, L1, F2, false>
        : intrinsic::deref<F1>
    { };

    template <typename F1, typename L1, typename F2>
    struct dispatch<tag::deref, F1, L1, F2, true>
        : intrinsic::deref<F2>
    { };

    template <typename F1, typename L1, typename F2, bool Whatever>
    struct dispatch<tag::category_of, F1, L1, F2, Whatever>
        : identity<category::forward_iterator>
    { };
} // end namespace joined_detail

template <typename OperationTag, typename F1, typename L1, typename L2>
struct dispatch<OperationTag, joined_detail::joined_iterator<F1, L1, L2>>
    : joined_detail::dispatch<OperationTag, F1, L1, L2>
{ };

namespace view {
    /*!
     * @ingroup view
     *
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

template <typename Op, typename S1, typename S2, typename ...Args>
struct dispatch<Op, view::joined<S1, S2>, Args...>
    : dispatch<
        Op,
        view::bounded_by<
            joined_detail::joined_iterator<
                typename intrinsic::begin<S1>::type,
                typename intrinsic::end<S1>::type,
                typename intrinsic::begin<S2>::type
            >,
            joined_detail::joined_iterator<
                typename intrinsic::end<S1>::type,
                typename intrinsic::end<S1>::type,
                typename intrinsic::end<S2>::type
            >
        >,
        Args...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_JOINED_HPP
