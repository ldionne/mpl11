/*!
 * @file
 * This file defines the `boost::mpl11::prior` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_PRIOR_HPP
#define BOOST_MPL11_INTRINSIC_PRIOR_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Iterator, typename ...Args>
struct prior
    : detail::tag_dispatched<prior, Iterator, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_PRIOR_HPP
