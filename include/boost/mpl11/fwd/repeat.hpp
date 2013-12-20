/*!
 * @file
 * Forward declares `boost::mpl11::repeat` and `boost::mpl11::repeat_c`.
 */

#ifndef BOOST_MPL11_FWD_REPEAT_HPP
#define BOOST_MPL11_FWD_REPEAT_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     * @ingroup sequences
     *
     * `Sequence` containing `N` (or infinitely many) copies of the
     * given type.
     *
     * If the number of copies of `T` is not specified, `repeat` is an
     * infinite sequence. If it is specified, it must be non-negative or
     * else a static assertion is triggered.
     *
     * Additionally, `repeat` is a `Metafunction` returning a `vector`
     * created with the elements of `repeat`. It should not be used as
     * a `Metafunction` when the sequence is infinite.
     */
    template <typename T, typename N =
        integral_c<detail::std_size_t, static_cast<detail::std_size_t>(-1)>
    >
    struct repeat;

    template <typename T, typename N =
        integral_c<detail::std_size_t, static_cast<detail::std_size_t>(-1)>
    >
    using repeat_t = typename repeat<T, N>::type;

    /*!
     * @ingroup metafunctions
     * @ingroup sequences
     *
     * Alias to `repeat<T, integral_c<std::size_t, N>>`; provided
     * for convenience.
     */
    template <typename T, detail::std_size_t N>
    using repeat_c = repeat<T, integral_c<detail::std_size_t, N>>;

    template <typename T, detail::std_size_t N>
    using repeat_c_t = typename repeat_c<T, N>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_REPEAT_HPP
