/*!
 * @file
 * This file defines the `boost::mpl11::erase` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct erase : detail::tag_dispatched<erase> {

    };
}

template <typename Sequence, typename ...Args>
struct erase
    : apply_raw<intrinsic::erase, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_ERASE_HPP
