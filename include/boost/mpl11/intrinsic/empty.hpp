/*!
 * @file
 * This file defines the `boost::mpl11::empty` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_EMPTY_HPP
#define BOOST_MPL11_INTRINSIC_EMPTY_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct empty : detail::tag_dispatched<empty> {
        template <typename ...Args>
        struct apply
            : bool_<
                apply_raw<
                    detail::tag_dispatched<empty>, Args...
                >::type::value
            >
        { };
    };
}

template <typename Sequence, typename ...Args>
struct empty
    : apply_raw<intrinsic::empty, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_EMPTY_HPP
