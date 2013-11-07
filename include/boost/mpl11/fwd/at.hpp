/*!
 * @file
 * Forward declares `boost::mpl11::at` and defines `boost::mpl::at_c`.
 */

#ifndef BOOST_MPL11_FWD_AT_HPP
#define BOOST_MPL11_FWD_AT_HPP

#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup sequence_intrinsics
     *
     * General purpose intrinsic for accessing elements in a sequence.
     *
     * ### `AssociativeSequence`: `at<%Sequence, Key, Default = optional>`
     *
     * If `Default` is provided, returns the element associated to `Key` in
     * `%Sequence` or `Default` if so such element exists.
     *
     * If `Default` is not provided, returns the element associated to `Key`
     * in `%Sequence` or triggers a compile-time assertion if so such element
     * exists.
     *
     *
     * ### `RandomAccessSequence`: `at<%Sequence, N>`
     *
     * Returns the `N`th element of `%Sequence` if `N` is in the bounds of
     * the sequence, and triggers a compile-time assertion otherwise.
     *
     *
     * @todo
     * Consider returning a `Logical` from `at<%Sequence, Key>`. Something
     * like a `Maybe` would be neat.
     */
    template <typename SEE_DETAILS>
    struct at { };
#else
    template <
        typename Sequence,
        typename KeyOrIndex,
        typename Default = detail::optional
    >
    struct at;
#endif

    //! @ingroup sequence_intrinsics
    //! Alias to `at<%Sequence, ulong<N>>`; provided for convenience.
    template <typename Sequence, unsigned long N>
    using at_c = at<Sequence, ulong<N>>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AT_HPP
