/*!
 * @file
 * This file defines `boost::mpl11::detail::tag_dispatched`.
 */

#ifndef BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP
#define BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP

#include <boost/mpl11/apply_fwd.hpp>
#include <boost/mpl11/trait/dispatcher_of.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
    template <typename Operation>
    struct tag_dispatched {
        template <typename Receiver, typename ...Args>
        struct apply
            : mpl11::apply<
                typename trait::dispatcher_of<Receiver>::type,
                Operation, Args...
            >
        { };
    };
}}}}

#endif // !BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP

#include <boost/mpl11/apply.hpp>
