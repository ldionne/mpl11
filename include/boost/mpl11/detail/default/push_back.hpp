/*!
 * @file
 * Defines the default implementation of `boost::mpl11::intrinsic::push_back`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_PUSH_BACK_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_PUSH_BACK_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Element>
struct dispatch<detail::default_<tag::push_back>, Sequence, Element>
    : intrinsic::insert<
        Sequence, typename intrinsic::end<Sequence>::type, Element
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_PUSH_BACK_HPP
