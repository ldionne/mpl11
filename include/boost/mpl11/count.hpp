/*!
 * @file
 * Defines `boost::mpl11::count`.
 */

#ifndef BOOST_MPL11_COUNT_HPP
#define BOOST_MPL11_COUNT_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/count_if.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace count_detail {
    template <typename Sequence, typename Element>
    struct count_impl
        : count_if<Sequence, is_same<Element, _1>>
    { };
} // end namespace count_detail

/*!
 * Returns the number of elements in `Sequence` that are identical
 * to `Element`.
 *
 * The default implementation is equivalent to
 * `count_if<Sequence, is_same<Element, _1>>`.
 */
template <typename Sequence, typename Element>
struct count
    : detail::tag_dispatched<tag::count, Sequence, Element>::template
      with_default<count_detail::count_impl<_1, _2>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COUNT_HPP
