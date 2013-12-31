/*!
 * @file
 * Forward declares `boost::mpl11::take`.
 */

#ifndef BOOST_MPL11_FWD_TAKE_HPP
#define BOOST_MPL11_FWD_TAKE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     *
     * Sequence containing the first `N` elements of another sequence.
     *
     * `N` must be a non-negative `Integral` representing the number of
     * elements kept in the underlying sequence. If `N` is greater than
     * the length of the sequence, all of its elements are kept.
     *
     * The sequence operations supported by `take` are those supported by
     * the underlying sequence, except that `take` is always a
     * `FiniteSequence`.
     *
     *
     * @todo
     * Use a minimal sequence in the unit test.
     */
    template <typename N, typename Sequence>
    struct take;

    /*!
     * @ingroup datatypes
     *
     * Alias to `take<size_t<N>, Sequence>`; provided for convenience.
     */
    template <detail::std_size_t N, typename Sequence>
    BOOST_MPL11_DOXYGEN_ALIAS(take_c, take<size_t<N>, Sequence>);
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TAKE_HPP
