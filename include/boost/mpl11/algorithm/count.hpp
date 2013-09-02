/*!
 * @file
 * Defines `boost::mpl11::algorithm::count`.
 */

#ifndef BOOST_MPL11_ALGORITHM_COUNT_HPP
#define BOOST_MPL11_ALGORITHM_COUNT_HPP

#include <boost/mpl11/algorithm/count_if.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Returns the number of elements in `Sequence` that are identical
     * to `Element`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `count_if<Sequence, equal_to<Element, _1>>`.
     */
    template <typename Sequence, typename Element>
    struct count
        : dispatch<tag::count, Sequence, Element>
    { };
} // end namespace algorithm

template <typename Sequence, typename Element>
struct dispatch<detail::default_<tag::count>, Sequence, Element>
    : algorithm::count_if<Sequence, intrinsic::equal_to<Element, _1>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_COUNT_HPP
