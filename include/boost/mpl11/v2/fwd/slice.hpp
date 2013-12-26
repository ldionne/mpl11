/*!
 * @file
 * Forward declares `boost::mpl11::slice` and `boost::mpl11::slice_c`.
 */

#ifndef BOOST_MPL11_FWD_SLICE_HPP
#define BOOST_MPL11_FWD_SLICE_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup RandomAccessSequence
     * @ingroup methods
     *
     * Returns a subrange of a `RandomAccessSequence`.
     *
     * Specifically, returns a concept-identical sequence containing all
     * the elements of the original sequence at an index in the range
     * delimited by [`Start`, `Stop`).
     *
     * `Start` and `Stop` must both be non-negative `Integral`s, with
     * `Start::value <= Stop::value` and `Stop::value <= `length<S>::value`
     * if `S` is a `FiniteSequence`.
     */
    template <typename S, typename Start, typename Stop>
    struct slice;

    template <typename S, typename Start, typename Stop>
    using slice_t = typename slice<S, Start, Stop>::type;

    //! Alias to `slice<S, size_t<Start>, size_t<Stop>>`; provided
    //! for convenience.
    template <typename S, detail::std_size_t Start, detail::std_size_t Stop>
    using slice_c = slice<S, size_t<Start>, size_t<Stop>>;

    template <typename S, detail::std_size_t Start, detail::std_size_t Stop>
    using slice_c_t = typename slice<S, size_t<Start>, size_t<Stop>>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SLICE_HPP
