/*!
 * @file
 * Defines `boost::mpl11::algorithm::distance`.
 */

#ifndef BOOST_MPL11_ALGORITHM_DISTANCE_HPP
#define BOOST_MPL11_ALGORITHM_DISTANCE_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


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
                bounded_by<First, Last>,
                ulong<0>,
                next<_1>
            >
       @endcode
     */
    template <typename First, typename Last>
    struct distance
        : dispatch<tag::distance, First, Last>
    { };
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/distance.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_DISTANCE_HPP
