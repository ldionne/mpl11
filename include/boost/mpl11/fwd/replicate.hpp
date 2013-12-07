/*!
 * @file
 * Forward declares `boost::mpl11::replicate` and `boost::mpl11::replicate_c`.
 */

#ifndef BOOST_MPL11_FWD_REPLICATE_HPP
#define BOOST_MPL11_FWD_REPLICATE_HPP

#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     * @ingroup sequences
     *
     * `Sequence` containing `N` copies of the given type.
     *
     * Additionally, `mpl11::replicate` is a `Metafunction` returning a
     * `mpl11::vector` created with the elements of `mpl11::replicate`.
     *
     *
     * @note
     * If `N::value < 0`, a static assertion is triggered.
     */
    template <typename N, typename T>
    struct replicate;

    template <typename N, typename T>
    using replicate_t = typename replicate<N, T>::type;

    /*!
     * @ingroup metafunctions
     * @ingroup sequences
     *
     * Alias to `replicate<ulonglong<N>, T>`; provided for convenience.
     */
    template <unsigned long long N, typename T>
    using replicate_c = replicate<ulonglong<N>, T>;

    template <unsigned long long N, typename T>
    using replicate_c_t = typename replicate_c<N, T>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_REPLICATE_HPP
