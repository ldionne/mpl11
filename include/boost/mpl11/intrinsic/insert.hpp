/*!
 * @file
 * Defines `boost::mpl11::intrinsic::insert`.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/forward_decls.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/insert_range.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/single_element.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
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
        : detail::tag_dispatched<tag::insert, Sequence, Position, Element>
    { };

    /*!
     * @ingroup intrinsic
     *
     * Inserts an element in an `AssociativeSequence`.
     */
    template <typename Sequence, typename Element>
    struct insert<Sequence, Element>
        : detail::tag_dispatched<tag::insert, Sequence, Element>
    { };
} // end namespace intrinsic

template <typename Sequence, typename Position, typename Element>
struct dispatch<detail::default_<tag::insert>, Sequence, Position, Element>
    : intrinsic::insert_range<
        Sequence, Position, view::single_element<Element>
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_INSERT_HPP
