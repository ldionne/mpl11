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
     * `N` must be an `Integral`. The sign of `N` depends on the concept
     * modeled by `Iterator`; see the concept-specific documentation.
     */
    template <typename Iterator, typename N>
    struct advance;

    template <typename Iterator, typename N>
    using advance_t = typename advance<Iterator, N>::type;

    //! @ingroup iterator_intrinsics
    //! Alias to `advance<Iterator, long_<N>>`; provided for convenience.
    template <typename Iterator, long N>
    using advance_c = advance<Iterator, long_<N>>;

    template <typename Iterator, long N>
    using advance_c_t = typename advance_c<Iterator, N>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ADVANCE_HPP
