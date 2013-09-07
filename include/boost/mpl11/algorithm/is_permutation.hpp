/*!
 * @file
 * Defines `boost::mpl11::algorithm::is_permutation`.
 */

#ifndef BOOST_MPL11_ALGORITHM_IS_PERMUTATION_HPP
#define BOOST_MPL11_ALGORITHM_IS_PERMUTATION_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Overloaded algorithm for determining whether a sequence is a
     * permutation of another.
     */
    template <typename Sequence1,
              typename Sequence2,
              typename Predicate = detail::optional>
    struct is_permutation;

    /*!
     * @ingroup algorithm
     *
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
     * @ingroup algorithm
     *
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
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/is_permutation.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_IS_PERMUTATION_HPP
