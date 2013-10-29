/*!
 * @file
 * Forward declares `boost::mpl11::advance`.
 */

#ifndef BOOST_MPL11_FWD_ADVANCE_HPP
#define BOOST_MPL11_FWD_ADVANCE_HPP

#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup iterator_intrinsics
     *
     * Moves `Iterator` by the distance `N`.
     *
     *
     * @todo
     * Document the nature of N. Could it be only a `Value` instead of a full
     * `IntegralConstant`?
     *
     * @todo
     * Put the folowing in the concept documentation:
     * For a @ref RandomAccessIterator or a @ref BidirectionalIterator,
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
