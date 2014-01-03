/*!
 * @file
 * Forward declares `boost::mpl11::drop`.
 */

#ifndef BOOST_MPL11_FWD_DROP_HPP
#define BOOST_MPL11_FWD_DROP_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns a sequence containing the suffix of another sequence after
     * the first `N` elements.
     *
     * `N` must be a non-negative `Integral` representing the number of
     * elements to be dropped from the underlying sequence. If `N` is greater
     * than the length of the sequence, the returned sequence is empty.
     */
    template <typename N, typename Sequence>
    struct drop;

    template <typename N, typename Sequence>
    using drop_t = typename drop<N, Sequence>::type;

    /*!
     * @ingroup metafunctions
     *
     * Equivalent to `drop<size_t<N>, Sequence>`.
     */
    template <detail::std_size_t N, typename Sequence>
    struct drop_c;

    template <detail::std_size_t N, typename Sequence>
    using drop_c_t = typename drop_c<N, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DROP_HPP
