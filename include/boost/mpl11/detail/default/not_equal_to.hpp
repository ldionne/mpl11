/*!
 * @file
 * Defines the default implementation of
 * `boost::mpl11::intrinsic::not_equal_to`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_NOT_EQUAL_TO_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_NOT_EQUAL_TO_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/not.hpp>
#include <boost/mpl11/intrinsic/not_equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename T1, typename T2, typename ...Tn>
struct dispatch<detail::default_<tag::not_equal_to>, T1, T2, Tn...>
    : intrinsic::and_<
        intrinsic::not_equal_to<T1, T2>,
        intrinsic::not_equal_to<T2, Tn...>
    >
{ };

template <typename T1, typename T2>
struct dispatch<detail::default_<tag::not_equal_to>, T1, T2>
    : intrinsic::not_<intrinsic::equal_to<T1, T2>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_NOT_EQUAL_TO_HPP
