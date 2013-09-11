/*!
 * @file
 * Defines the default implementation of `boost::mpl11::intrinsic::is_empty`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_IS_EMPTY_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_IS_EMPTY_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence>
struct dispatch<detail::default_<tag::is_empty>, Sequence>
    : equal_to<
        typename intrinsic::begin<Sequence>::type,
        typename intrinsic::end<Sequence>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_IS_EMPTY_HPP
