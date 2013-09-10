/*!
 * @file
 * Defines `boost::mpl11::intrinsic::erase`.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Overloaded intrinsic for removing elements from a sequence.
     */
    template <typename Sequence,
              typename First,
              typename Last = detail::optional>
    struct erase;

    /*!
     * @ingroup intrinsic
     *
     * Removes several adjacent elements in a sequence starting from an
     * arbitrary position.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to copying the whole sequence except for the content of the
     * range delimited by [`First`, `Last`).
     *
     *
     * @warning
     * Differences from the original MPL:
     * - It is possible to erase a range of elements in an
     *   @ref AssociativeSequence.
     */
    template <typename Sequence, typename First, typename Last>
    struct erase BOOST_MPL11_DOXYGEN_ONLY(<Sequence, First, Last>)
        : dispatch<tag::erase, Sequence, First, Last>
    { };

    /*!
     * @ingroup intrinsic
     *
     * Removes an element at a position in a sequence.
     *
     *
     * ## Semantics and default implementation
     *
     * Equivalent to `erase<Sequence, Position, next<Position>::type>`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - The semantics are the same for all types of sequences.
     */
    template <typename Sequence, typename Position>
    struct erase<Sequence, Position>
        : dispatch<tag::erase, Sequence, Position>
    { };
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/erase.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_ERASE_HPP
