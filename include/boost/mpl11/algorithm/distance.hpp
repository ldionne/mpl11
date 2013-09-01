/*!
 * @file
 * Defines `boost::mpl11::algorithm::distance`.
 */

#ifndef BOOST_MPL11_ALGORITHM_DISTANCE_HPP
#define BOOST_MPL11_ALGORITHM_DISTANCE_HPP

#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Returns the distance between `First` and `Last` iterators.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            foldl<
                view::bounded_by<First, Last>,
                ulong<0>,
                next<_1>
            >
       @endcode
     */
    template <typename First, typename Last>
    struct distance
        : detail::tag_dispatched<tag::distance, First, Last>::template
          with_default<
            lazy_always<
                foldl<
                    view::bounded_by<First, Last>,
                    ulong<0>,
                    quote<intrinsic::next>
                >
            >
          >
    { };
}}} // end namespace boost::mpl11::algorithm

#endif // !BOOST_MPL11_ALGORITHM_DISTANCE_HPP
