/*!
 * @file
 * Defines `boost::mpl11::contains`.
 */

#ifndef BOOST_MPL11_CONTAINS_HPP
#define BOOST_MPL11_CONTAINS_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/find.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
/*!
 * Returns whether `Sequence` contains one or more elements identical
 * to `Element`.
 *
 * The default implementation is equivalent to
 * `not_<is_same<find<Sequence, Element>::type, end<Sequence>::type>>`.
 */
template <typename Sequence, typename Element>
struct contains
    : detail::tag_dispatched<tag::contains, Sequence, Element>::template
      with_default<
        not_<is_same<find<_1, _2>, end<_1>>>
      >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINS_HPP
