/*!
 * @file
 * Forward declares `boost::mpl11::distance`.
 */

#ifndef BOOST_MPL11_ALGORITHM_DISTANCE_FWD_HPP
#define BOOST_MPL11_ALGORITHM_DISTANCE_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct distance; }

    /*!
     * @ingroup algorithms
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_DISTANCE_FWD_HPP
