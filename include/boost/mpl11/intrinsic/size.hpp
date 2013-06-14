/*!
 * @file
 * This file defines the `boost::mpl11::size` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_SIZE_HPP
#define BOOST_MPL11_INTRINSIC_SIZE_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct size : detail::tag_dispatched<size> {
        template <typename ...Args>
        struct apply
            : integral_c<
                decltype(mpl11::apply<
                    detail::tag_dispatched<size>, Args...
                >::type::value),
                mpl11::apply<
                    detail::tag_dispatched<size>, Args...
                >::type::value
            >
        { };
    };
}

template <typename Sequence, typename ...Args>
struct size
    : apply_raw<intrinsic::size, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_SIZE_HPP
