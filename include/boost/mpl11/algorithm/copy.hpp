/*!
 * @file
 * Defines `boost::mpl11::algorithm::copy`.
 */

#ifndef BOOST_MPL11_ALGORITHM_COPY_HPP
#define BOOST_MPL11_ALGORITHM_COPY_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithms
     *
     * Overloaded algorithm for copying elements from a sequence to another.
     */
    template <typename, typename = detail::optional>
    struct copy;

    /*!
     * @ingroup algorithms
     *
     * Copies the content of a sequence from a sequence to another using a
     * custom inserter.
     *
     *
     * ### Semantics
     *
     * The returned sequence should be a concept-identical sequence equal to
     * `Sequence`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - The implementation is determined by the inserter; there is no default
     *   implementation for all inserters.
     */
    template <typename Sequence, typename Inserter>
    struct copy BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Inserter>)
        : dispatch<tag::copy, Sequence, Inserter>
    { };

    /*!
     * @ingroup algorithms
     *
     * Copies the content of a sequence from one sequence to another.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `copy<Sequence, into<clear<Sequence>::type>>`.
     */
    template <typename Sequence>
    struct copy<Sequence>
        : dispatch<tag::copy, Sequence>
    { };
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/copy.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_COPY_HPP
