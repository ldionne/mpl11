/*!
 * @file
 * Defines `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Overloaded intrinsic for inserting elements in a sequence.
     */
    template <typename, typename, typename = detail::optional>
    struct insert;

    /*!
     * @ingroup intrinsics
     *
     * Inserts an element at an arbitrary position in a
     * @ref RandomExtensibleSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            insert_range<
                Sequence,
                Position,
                view::single_element<Element>
            >
       @endcode
     *
     *
     * @warning
     * Differences from the original MPL:
     * - The default implementation differs.
     */
    template <typename Sequence, typename Position, typename Element>
    struct insert BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Position, Element>)
        : dispatch<tag::insert, Sequence, Position, Element>
    { };

    /*!
     * @ingroup intrinsics
     *
     * Inserts an element in an @ref AssociativeSequence.
     */
    template <typename Sequence, typename Element>
    struct insert<Sequence, Element>
        : dispatch<tag::insert, Sequence, Element>
    { };
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/insert.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_INSERT_HPP
