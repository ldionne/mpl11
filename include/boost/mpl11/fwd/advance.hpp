/*!
 * @file
 * Forward declares `boost::mpl11::advance`.
 */

#ifndef BOOST_MPL11_FWD_ADVANCE_HPP
#define BOOST_MPL11_FWD_ADVANCE_HPP

#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Moves `Iterator` by the distance `N`.
     *
     * @internal
     * @todo Put the specific behaviors doc in the class implementing it.
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
    struct advance;

    //! Alias to `advance<Iterator, long_<N>>`; provided for convenience.
    template <typename Iterator, long N>
    using advance_c = advance<Iterator, long_<N>>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ADVANCE_HPP
