/*!
 * @file
 * Defines `boost::mpl11::algorithm::sort`.
 */

#ifndef BOOST_MPL11_ALGORITHM_SORT_HPP
#define BOOST_MPL11_ALGORITHM_SORT_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithms
     *
     * Overloaded algorithm for sorting the elements of a sequence.
     */
    template <typename,
              typename = detail::optional,
              typename = detail::optional>
    struct sort;

    /*!
     * @ingroup algorithms
     *
     * Sorts the elements of a sequence according to their strict weak
     * ordering operator.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `sort<Sequence, less<_1, _2>>`.
     */
    template <typename Sequence>
    struct sort<Sequence>
        : dispatch<tag::sort, Sequence>
    { };

    /*!
     * @ingroup algorithms
     *
     * Sorts the elements of a sequence according to a custom
     * ordering relation.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `sort<Sequence, Predicate, clear<Sequence>::type>`.
     */
    template <typename Sequence, typename Predicate>
    struct sort<Sequence, Predicate>
        : dispatch<tag::sort, Sequence, Predicate>
    { };

    /*!
     * @ingroup algorithms
     *
     * @todo Document me
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `copy<sorted<Sequence, Predicate>, Destination>`.
     */
    template <typename Sequence, typename Predicate, typename Destination>
    struct sort BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Predicate, Destination>)
        : dispatch<tag::sort, Sequence, Predicate, Destination>
    { };
}}} // end namespace boost::mpl11::algorithm

#endif // !BOOST_MPL11_ALGORITHM_SORT_HPP
