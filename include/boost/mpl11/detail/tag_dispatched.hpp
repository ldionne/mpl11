/*!
 * @file
 * This file defines `boost::mpl11::detail::tag_dispatched`.
 */

#ifndef BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP
#define BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP

namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
template <template <typename ...> class Impl, typename Receiver, typename ...Args>
struct tag_dispatched
    : Receiver::mpl11::dispatcher::template apply<Impl, Receiver, Args...>
{ };
}}}}

#endif // !BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP
