/*!
 * @file
 * Defines `boost::mpl11::view::single_element`.
 */

#ifndef BOOST_MPL11_VIEW_SINGLE_ELEMENT_HPP
#define BOOST_MPL11_VIEW_SINGLE_ELEMENT_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace single_element_detail {
    template <typename Element, bool IsEnd>
    struct single_element_iterator;

    template <typename OperationTag, typename Element, bool IsEnd>
    struct dispatch;

    template <typename Element>
    struct dispatch<tag::next, Element, false>
        : identity<single_element_iterator<Element, true>>
    { };

    template <typename Element>
    struct dispatch<tag::prior, Element, true>
        : identity<single_element_iterator<Element, false>>
    { };

    template <typename Element, bool IsEnd>
    struct dispatch<tag::category_of, Element, IsEnd>
        : identity<category::random_access_iterator>
    { };

    template <typename Element>
    struct dispatch<tag::deref, Element, false>
        : identity<Element>
    { };
} // end namespace single_element_detail

template <typename Op, typename E, bool B>
struct dispatch<Op, single_element_detail::single_element_iterator<E, B>>
    : single_element_detail::dispatch<Op, E, B>
{ };

namespace view {
    /*!
     * @ingroup view
     *
     * View onto an arbitrary `Element` as on a single-element sequence.
     *
     * `single_element` is a random access sequence.
     */
    template <typename Element>
    struct single_element BOOST_MPL11_DOXYGEN_ONLY({ });
} // end namespace view

template <typename Op, typename Element, typename ...Args>
struct dispatch<Op, view::single_element<Element>, Args...>
    : dispatch<
        Op,
        view::bounded_by<
            single_element_detail::single_element_iterator<Element, false>,
            single_element_detail::single_element_iterator<Element, true>
        >,
        Args...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_SINGLE_ELEMENT_HPP
