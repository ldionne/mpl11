/*!
 * @file
 * Forward declares `boost::mpl11::at` and `boost::mpl::at_c`.
 */

#ifndef BOOST_MPL11_FWD_AT_HPP
#define BOOST_MPL11_FWD_AT_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup RandomAccessSequence
     * @ingroup methods
     *
     * Returns the element of a `RandomAccessSequence` at a given index.
     */
    template <typename S, typename Index>
    struct at;

    template <typename S, typename Index>
    using at_t = typename at<S, Index>::type;

    //! Alias to `at<S, size_t<Index>>`; provided for convenience.
    template <typename S, detail::std_size_t Index>
    using at_c = at<S, size_t<Index>>;

    template <typename S, detail::std_size_t Index>
    using at_c_t = typename at<S, size_t<Index>>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AT_HPP
