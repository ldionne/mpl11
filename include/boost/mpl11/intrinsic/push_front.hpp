/*!
 * @file
 * Defines `boost::mpl11::intrinsic::push_front`.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Inserts an element at the beginning of a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `insert<Sequence, begin<Sequence>::type, Element>`.
     */
    template <typename Sequence, typename Element>
    struct push_front
        : detail::tag_dispatched<tag::push_front, Sequence, Element>
    { };
} // end namespace intrinsic

template <typename Sequence, typename Element>
struct dispatch<detail::default_<tag::push_front>, Sequence, Element>
    : intrinsic::insert<
        Sequence, typename intrinsic::begin<Sequence>::type, Element
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP
