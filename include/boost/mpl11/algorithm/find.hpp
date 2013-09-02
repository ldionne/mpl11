/*!
 * @file
 * Defines `boost::mpl11::algorithm::find`.
 */

#ifndef BOOST_MPL11_ALGORITHM_FIND_HPP
#define BOOST_MPL11_ALGORITHM_FIND_HPP

#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Returns an iterator to the first occurence of a given element in a
     * sequence, or the past-the-end iterator if no such element exists.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `find_if<Sequence, equal_to<Element, _1>>`.
     */
    template <typename Sequence, typename Element>
    struct find
        : detail::tag_dispatched<tag::find, Sequence, Element>
    { };
} // end namespace algorithm

template <typename Sequence, typename Element>
struct dispatch<detail::default_<tag::find>, Sequence, Element>
    : algorithm::find_if<Sequence, intrinsic::equal_to<Element, _1>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_FIND_HPP
