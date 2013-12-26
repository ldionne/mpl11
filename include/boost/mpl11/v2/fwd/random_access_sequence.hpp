/*!
 * @file
 * Forward declares `boost::mpl11::RandomAccessSequence`.
 */

#ifndef BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup RandomAccessSequence RandomAccessSequence
     *
     * Collection of types providing efficient access to elements
     * anywhere in the sequence.
     *
     *
     * ### Refines
     * `ForwardSequence`
     *
     * ### Methods
     * `at`, `slice`
     *
     * ### Minimal complete definition
     * `at` and `slice`.
     */
    template <typename Tag>
    struct RandomAccessSequence;

    /*!
     * @ingroup RandomAccessSequence
     * @ingroup methods
     * @{
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

    /*!
     * Returns the element of a `RandomAccessSequence` at the given index.
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

    //! @}

    /*!
     * @ingroup tags
     *
     * Tag representing the `RandomAccessSequence` typeclass.
     */
    struct random_access_sequence_tag;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP
