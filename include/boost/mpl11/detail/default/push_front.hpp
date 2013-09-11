/*!
 * @file
 * Defines the default implementation of `boost::mpl11::push_front`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_PUSH_FRONT_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_PUSH_FRONT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Element>
struct dispatch<detail::default_<tag::push_front>, Sequence, Element>
    : insert<
        Sequence, typename begin<Sequence>::type, Element
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_PUSH_FRONT_HPP
