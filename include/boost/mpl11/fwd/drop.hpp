/*!
 * @file
 * Forward declares `boost::mpl11::drop` and `boost::mpl11::drop_c`.
 */

#ifndef BOOST_MPL11_FWD_DROP_HPP
#define BOOST_MPL11_FWD_DROP_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * `Sequence` containing the suffix of another sequence after
     * the first `N` elements.
     *
     * If `N` is greater than the length of the sequence, `drop` is an empty
     * `Sequence`. Additionally, `drop` is an algorithm returning a new
     * `Container` created with the elements of `drop`. To use `drop` as
     * an algorithm, `%Sequence` must be a `Container`.
     *
     *
     * @note
     * A static assertion is triggered if `N::value < 0`.
     */
    template <typename N, typename Sequence>
    struct drop;

    template <typename N, typename Sequence>
    using drop_t = typename drop<N, Sequence>::type;

    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * Alias to `drop<integral_c<std::size_t, N>, %Sequence>`; provided
     * for convenience.
     */
    template <detail::std_size_t N, typename Sequence>
    using drop_c = drop<integral_c<detail::std_size_t, N>, Sequence>;

    template <detail::std_size_t N, typename Sequence>
    using drop_c_t = typename drop_c<N, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DROP_HPP
