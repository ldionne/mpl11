/*!
 * @file
 * Defines the default implementation of `boost::mpl11::intrinsic::not_`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_NOT_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_NOT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename F>
struct dispatch<detail::default_<tag::not_>, F>
    : identity<bool_<!F::type::value>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_NOT_HPP
