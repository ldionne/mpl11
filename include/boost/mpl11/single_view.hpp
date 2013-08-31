/*!
 * @file
 * Defines `boost::mpl11::single_view`.
 */

#ifndef BOOST_MPL11_SINGLE_VIEW_HPP
#define BOOST_MPL11_SINGLE_VIEW_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace single_view_detail {
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
} // end namespace single_view_detail

template <typename Op, typename E, bool B>
struct dispatch<Op, single_view_detail::single_element_iterator<E, B>>
    : lazy_always<single_view_detail::dispatch<Op, E, B>>
{ };

/*!
 * View onto an arbitrary `Element` as on a single-element sequence.
 *
 * `single_view` is a random access sequence.
 */
template <typename Element>
struct single_view BOOST_MPL11_DOXYGEN_ONLY({ });

template <typename Element>
struct dispatch<tag::begin, single_view<Element>>
    : always<single_view_detail::single_element_iterator<Element, false>>
{ };

template <typename Element>
struct dispatch<tag::end, single_view<Element>>
    : always<single_view_detail::single_element_iterator<Element, true>>
{ };

template <typename Element>
struct dispatch<tag::category_of, single_view<Element>>
    : always<category::random_access_sequence>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SINGLE_VIEW_HPP
