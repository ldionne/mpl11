/*!
 * @file
 * Forward declares `boost::mpl11::take`.
 */

#ifndef BOOST_MPL11_FWD_TAKE_HPP
#define BOOST_MPL11_FWD_TAKE_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns a `Sequence` containing the first `N` elements of
     * another sequence.
     *
     * `N` must be a non-negative `StaticConstant` representing the number of
     * elements to keep in the underlying sequence. If `N` is greater than
     * the length of the sequence, all of its elements are kept.
     */
    template <typename N, typename Sequence>
    struct take;

    template <typename N, typename Sequence>
    using take_t = typename take<N, Sequence>::type;

    /*!
     * @ingroup metafunctions
     *
     * Equivalent to `take<size_t<N>, Sequence>`.
     */
    template <detail::std_size_t N, typename Sequence>
    struct take_c;

    template <detail::std_size_t N, typename Sequence>
    using take_c_t = typename take_c<N, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TAKE_HPP
