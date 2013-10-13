/*!
 * @file
 * Forward declares `boost::mpl11::advance`.
 */

#ifndef BOOST_MPL11_ALGORITHM_ADVANCE_FWD_HPP
#define BOOST_MPL11_ALGORITHM_ADVANCE_FWD_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/integral_c_fwd.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct advance; }

    /*!
     * @ingroup algorithms
     * Moves `Iterator` by the distance `N`.
     *
     * For @ref RandomAccessIterator "Random Access Iterators" and
     * @ref BidirecitonalIterator "Bidirecitonal Iterators", the distance
     * may be negative. For @ref ForwardIterator "Forward Iterators", it
     * may not.
     *
     *
     * ### Semantics and default implementation
     *
     * For a @ref ForwardIterator, equivalent to using `next` until the
     * requested distance has been traversed.
     *
     * For a @ref RandomAccessIterator or a @ref BidirecitonalIterator,
     * equivalent to using either `next` or `prior` in the same way as
     * for a @ref ForwardIterator, depending on the sign of the distance.
     */
    template <typename Iterator, typename N>
    struct advance
        : dispatch<tag::advance, Iterator, N>
    { };

    //! Equivalent to `advance<Iterator, long_<N>>`; provided for convenience.
    template <typename Iterator, long N>
    struct advance_c
        : advance<Iterator, long_<N>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_ADVANCE_FWD_HPP
