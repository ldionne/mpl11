/*!
 * @file
 * Defines the default implementation of `boost::mpl11::intrinsic::insert`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_INSERT_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_INSERT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/insert_range.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/single_element.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Position, typename Element>
struct dispatch<detail::default_<tag::insert>, Sequence, Position, Element>
    : intrinsic::insert_range<
        Sequence, Position, view::single_element<Element>
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_INSERT_HPP
