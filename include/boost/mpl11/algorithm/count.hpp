/*!
 * @file
 * Defines `boost::mpl11::algorithm::count`.
 */

#ifndef BOOST_MPL11_ALGORITHM_COUNT_HPP
#define BOOST_MPL11_ALGORITHM_COUNT_HPP

#include <boost/mpl11/dispatch.hpp>
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
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/count.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_COUNT_HPP
