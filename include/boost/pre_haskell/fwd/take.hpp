/*!
 * @file
 * Forward declares `boost::mpl11::take` and `boost::mpl11::take_c`.
 */

#ifndef BOOST_MPL11_FWD_TAKE_HPP
#define BOOST_MPL11_FWD_TAKE_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * `Sequence` containing the first `N` elements of another `Sequence`.
     *
     * If `N` is greater than the length of the sequence, `take` contains the
     * all the elements of the sequence. Additionally, `take` is an algorithm
     * returning a new `Container` created with the elements of `take`. To
     * use `take` as an algorithm, `%Sequence` must be a `Container`.
     *
     *
     * @note
     * A static assertion is triggered if `N::value < 0`.
     */
    template <typename N, typename Sequence>
    struct take;

    template <typename N, typename Sequence>
    using take_t = typename take<N, Sequence>::type;

    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * Alias to `take<size_t<N>, %Sequence>`; provided
     * for convenience.
     */
    template <detail::std_size_t N, typename Sequence>
    using take_c = take<size_t<N>, Sequence>;

    template <detail::std_size_t N, typename Sequence>
    using take_c_t = typename take_c<N, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TAKE_HPP
