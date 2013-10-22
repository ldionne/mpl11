/*!
 * @file
 * Forward declares `boost::mpl11::algorithm::find_if`.
 */

#ifndef BOOST_MPL11_ALGORITHM_FIND_IF_FWD_HPP
#define BOOST_MPL11_ALGORITHM_FIND_IF_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct find_if; }

namespace algorithm {
    /*!
     * @ingroup algorithms
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
        : dispatch<tag::find_if, Sequence, Predicate>
    { };
} // end namespace algorithm
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_FIND_IF_FWD_HPP
