/*!
 * @file
 * This file defines the `boost::mpl11::pop_back` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_POP_BACK_HPP
#define BOOST_MPL11_INTRINSIC_POP_BACK_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Sequence, typename ...Args>
struct pop_back
    : detail::tag_dispatched<pop_back, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_POP_BACK_HPP
