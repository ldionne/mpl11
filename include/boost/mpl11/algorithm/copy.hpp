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
    template <typename From, typename To, typename Insert = detail::optional>
    struct copy;

    /*!
     * @ingroup algorithms
     *
     * Copies the content of a sequence from a sequence to another using a
     * custom operation for insertion.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `foldl<From, To, Insert>`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - Inserters are not used in this version; the destination sequence and
     *   the operation are specified separately.
     */
    template <typename From, typename To, typename Insert>
    struct copy BOOST_MPL11_DOXYGEN_ONLY(<From, To, Insert>)
        : dispatch<tag::copy, From, To, Insert>
    { };

    /*!
     * @ingroup algorithms
     *
     * Copies the content of a sequence from one sequence to another.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * - `foldl<From, To, push_back<_1, _2>>` if `To` is a
     *   @ref BackExtensibleSequence
     * - `foldr<From, To, push_front<_1, _2>>` if `To` is a
     *   @ref FrontExtensibleSequence
     * - `foldl<From, To, insert<_1, _2>>` if `To` is a
     *   @ref ExtensibleAssociativeSequence
     *
     *
     * @warning
     * Differences from the original MPL:
     * - Inserters are not used in this version.
     * - It is mandatory to specify a destination sequence.
     */
    template <typename From, typename To>
    struct copy<From, To>
        : dispatch<tag::copy, From, To>
    { };
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/copy.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_COPY_HPP
