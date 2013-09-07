/*!
 * @file
 * Defines `boost::mpl11::algorithm::advance`.
 */

#ifndef BOOST_MPL11_ALGORITHM_ADVANCE_HPP
#define BOOST_MPL11_ALGORITHM_ADVANCE_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Moves `Iterator` by the distance `N`.
     *
     * For `RandomAccessIterator`s and `BidirecitonalIterator`s, the distance
     * may be negative. For `ForwardIterator`s, it may not.
     *
     *
     * ### Semantics and default implementation
     *
     * For `ForwardIterator`s, equivalent to using `next` until the requested
     * distance has been traversed.
     *
     * For `RandomAccessIterator`s and `BidirecitonalIterator`s, equivalent
     * to using either `next` or `prior` in the same way as for
     * `ForwardIterator`s, depending on the sign of the distance.
     */
    template <typename Iterator, typename N>
    struct advance
        : dispatch<tag::advance, Iterator, N>
    { };

    //! Convenience alias to `advance<Iterator, long_<N>>`.
    template <typename Iterator, long N>
    using advance_c = advance<Iterator, long_<N>>;
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/advance.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_ADVANCE_HPP
