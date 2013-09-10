/*!
 * @file
 * Defines `boost::mpl11::intrinsic::insert`.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Overloaded intrinsic for inserting elements in a sequence.
     */
    template <typename Sequence,
              typename Position,
              typename Element = detail::optional>
    struct insert;

    /*!
     * @ingroup intrinsic
     *
     * Inserts an element at an arbitrary position in a sequence.
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
     * @ingroup intrinsic
     *
     * Inserts an element in an @ref AssociativeSequence.
     */
    template <typename Sequence, typename Element>
    struct insert<Sequence, Element>
        : dispatch<tag::insert, Sequence, Element>
    { };
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/insert.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_INSERT_HPP
