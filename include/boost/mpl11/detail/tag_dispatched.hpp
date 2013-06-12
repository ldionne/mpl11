/*!
 * @file
 * This file defines `boost::mpl11::detail::tag_dispatched`.
 */

#ifndef BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP
#define BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/trait/tag_of.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
template <template <typename> class Impl, typename Receiver, typename ...Args>
struct tag_dispatched
    : apply_raw<
        Impl<typename trait::tag_of<Receiver>::type>,
        Receiver, Args...
    >
{ };
}}}}

#endif // !BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP
