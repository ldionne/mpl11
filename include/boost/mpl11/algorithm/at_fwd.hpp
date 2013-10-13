/*!
 * @file
 * Forward declares `boost::mpl11::at` and defines `boost::mpl::at_c`.
 */

#ifndef BOOST_MPL11_ALGORITHM_AT_FWD_HPP
#define BOOST_MPL11_ALGORITHM_AT_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/integral_c_fwd.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct at; }

    /*!
     * @ingroup algorithms
     * Overloaded intrinsic for accessing elements in a sequence.
     */
    template <typename SequenceOrAssociativeSequence,
              typename IndexOrKey,
              typename DefaultOrNothing = detail::optional>
    struct at;

    /*!
     * @ingroup algorithms
     * Returns the element associated to a key in an @ref AssociativeSequence,
     * or a default value if no such element exists and a default is provided.
     *
     *
     * ### Semantics and default implementation
     *
     * When no `Default` is provided, equivalent to `at<Sequence, Key, X>`,
     * where `X` is a type such that a compile-time assertion is triggered
     * if `X` is returned.
     *
     * When a `Default` is provided, let `Iter` be the same as
       @code
            find_if<
                Sequence,
                equal_to<key_of<Sequence, _1>, Key>
            >::type
       @endcode
     * Then, `at` is equivalent to `value_of<Sequence, deref<Iter>::type>` if
       @code
            equal_to<
                Iter, end<Sequence>::type
            >::type::value
       @endcode
     * is `false`, and `identity<Default>` otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered when no `Default` is provided
     *   and `Key` can't be found.
     */
    template <typename Sequence, typename Key, typename Default>
    struct at BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Key, Default>)
        : dispatch<tag::at, Sequence, Key, Default>
    { };

    /*!
     * @ingroup algorithms
     * Returns the `N`th element of a sequence if `N` is in the bounds of the
     * sequence, and triggers a compile-time assertion otherwise.
     *
     *
     * ### Semantics and default implementation
     *
     * Let `Iter` be the same as `advance<begin<Sequence>::type, N>::type`.
     * Then, `at` is equivalent to `deref<Iter>` if
       @code
            equal_to<
                Iter, end<Sequence>::type
            >::type::value
       @endcode
     * and `N::value < 0` are `false`, and a compile-time assertion
     * is triggered otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered if `N` is out of the bounds of
     *   `Sequence`.
     */
    template <typename Sequence, typename N>
    struct at<Sequence, N>
        : dispatch<tag::at, Sequence, N>
    { };

    //! Alias to `at<Sequence, ulong<N>>`; provided for convenience.
    template <typename Sequence, unsigned long N>
    using at_c = at<Sequence, ulong<N>>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_AT_FWD_HPP
