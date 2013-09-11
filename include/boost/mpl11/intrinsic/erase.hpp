/*!
 * @file
 * Defines `boost::mpl11::erase`.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Overloaded intrinsic for removing elements from a sequence.
     */
    template <typename, typename, typename = detail::optional>
    struct erase;

    /*!
     * @ingroup intrinsics
     *
     * Removes several adjacent elements in a @ref RandomExtensibleSequence
     * starting from an arbitrary position.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to copying the whole sequence except for the content of the
     * range delimited by [`First`, `Last`).
     */
    template <typename Sequence, typename First, typename Last>
    struct erase BOOST_MPL11_DOXYGEN_ONLY(<Sequence, First, Last>)
        : dispatch<tag::erase, Sequence, First, Last>
    { };

    /*!
     * @ingroup intrinsics
     *
     * Removes an element at a position in a @ref RandomExtensibleSequence.
     *
     *
     * ## Semantics and default implementation
     *
     * Equivalent to `erase<Sequence, Position, next<Position>::type>`.
     */
    template <typename Sequence, typename Position>
    struct erase<Sequence, Position>
        : dispatch<tag::erase, Sequence, Position>
    { };
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/erase.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_ERASE_HPP
