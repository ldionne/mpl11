/*!
 * @file
 * Defines `boost::mpl11::find`.
 */

#ifndef BOOST_MPL11_FIND_HPP
#define BOOST_MPL11_FIND_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace find_detail {
    template <typename Sequence, typename Element>
    struct find_impl
        : find_if<Sequence, is_same<Element, _1>>
    { };
} // end namespace find_detail

/*!
 * Returns an iterator to the first occurence of a given element in a
 * sequence, or the past-the-end iterator if no such element exists.
 *
 * The default implementation is equivalent to
 * `find_if<Sequence, is_same<Element, _1>>`.
 */
template <typename Sequence, typename Element>
struct find
    : detail::tag_dispatched<tag::find, Sequence, Element>::template
      with_default<find_detail::find_impl<_1, _2>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FIND_HPP
