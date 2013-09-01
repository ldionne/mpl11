/*!
 * @file
 * Defines `boost::mpl11::algorithm::find_if`.
 */

#ifndef BOOST_MPL11_ALGORITHM_FIND_IF_HPP
#define BOOST_MPL11_ALGORITHM_FIND_IF_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace find_if_detail {
    template <typename First, typename Last, typename Predicate>
    struct find_if_impl;

    template <typename First, typename Last, typename Predicate>
    struct lazy_next_step
        : find_if_impl<
            typename intrinsic::next<First>::type, Last, Predicate
        >
    { };

    template <typename First, typename Last, typename Predicate>
    struct find_if_impl
        : if_<apply_wrap<Predicate, typename intrinsic::deref<First>::type>,
            identity<First>,
            lazy_next_step<First, Last, Predicate>
        >::type
    { };

    template <typename Last, typename Predicate>
    struct find_if_impl<Last, Last, Predicate>
        : identity<Last>
    { };
} // end namespace find_if_detail

namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Returns an iterator to the first element satisfying a given predicate
     * in a sequence, or the past-the-end iterator if no such element exists.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to returning the first iterator `It` in the range
     * [`begin<Sequence>::type`, `end<Sequence>::type`) such that
     * `apply<Predicate, deref<It>::type>::type::value` is `true`.
     * If no such iterator exists, `end<Sequence>::type` is returned
     * instead.
     */
    template <typename Sequence, typename Predicate>
    struct find_if
        : detail::tag_dispatched<tag::find_if, Sequence, Predicate>::template
          with_default<
            lazy_always<
                find_if_detail::find_if_impl<
                    typename intrinsic::begin<Sequence>::type,
                    typename intrinsic::end<Sequence>::type,
                    typename lambda<Predicate>::type
                >
            >
          >
    { };
} // end namespace algorithm
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_FIND_IF_HPP
