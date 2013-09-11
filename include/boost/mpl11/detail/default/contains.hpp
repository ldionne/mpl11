/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::contains`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_CONTAINS_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_CONTAINS_HPP

#include <boost/mpl11/algorithm/find.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/operator/not_equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Element>
struct dispatch<detail::default_<tag::contains>, Sequence, Element>
    : not_equal_to<
        typename algorithm::find<Sequence, Element>::type,
        typename end<Sequence>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_CONTAINS_HPP
