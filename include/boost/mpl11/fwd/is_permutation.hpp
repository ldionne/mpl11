/*!
 * @file
 * Forward declares `boost::mpl11::is_permutation`.
 */

#ifndef BOOST_MPL11_FWD_IS_PERMUTATION_HPP
#define BOOST_MPL11_FWD_IS_PERMUTATION_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct is_permutation; }

    /*!
     * @ingroup algorithms
     * Overloaded algorithm for determining whether a sequence is a
     * permutation of another.
     */
    template <typename Sequence1,
              typename Sequence2,
              typename Predicate = detail::optional>
    struct is_permutation;

    /*!
     * @ingroup algorithms
     * Returns whether a sequence is a permutation of another sequence,
     * using a custom predicate to determine the equality of two elements.
     *
     *
     * ### Semantics and default implementation
     *
     * The default implementation returns whether both sequences have the
     * same number of elements and whether each element appear the same
     * number of times in each sequence.
     */
    template <typename Sequence1, typename Sequence2, typename Predicate>
    struct is_permutation
    BOOST_MPL11_DOXYGEN_ONLY(<Sequence1, Sequence2, Predicate>)
        : dispatch<tag::is_permutation, Sequence1, Sequence2, Predicate>
    { };

    /*!
     * @ingroup algorithms
     * Returns whether a sequence is a permutation of another sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `is_permutation<Sequence1, Sequence2, equal_to<_1, _2>>`.
     */
    template <typename Sequence1, typename Sequence2>
    struct is_permutation<Sequence1, Sequence2>
        : dispatch<tag::is_permutation, Sequence1, Sequence2>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IS_PERMUTATION_HPP
