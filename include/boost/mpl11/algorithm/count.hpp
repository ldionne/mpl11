/*!
 * @file
 * Defines `boost::mpl11::algorithm::count`.
 */

#ifndef BOOST_MPL11_ALGORITHM_COUNT_HPP
#define BOOST_MPL11_ALGORITHM_COUNT_HPP

#include <boost/mpl11/algorithm/count_if.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
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
        : detail::tag_dispatched<tag::count, Sequence, Element>::template
          with_default<
            lazy_always<
                count_if<Sequence, intrinsic::equal_to<Element, _1>>
            >
          >
    { };
}}} // end namespace boost::mpl11::algorithm

#endif // !BOOST_MPL11_ALGORITHM_COUNT_HPP
