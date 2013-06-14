/*!
 * @file
 * This file defines the `boost::mpl11::erase_key` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct erase_key : detail::tag_dispatched<erase_key> {
        struct mpl11 {
            struct is_inplace_transformation;
        };
    };
}

template <typename AssociativeSequence, typename ...Args>
struct erase_key
    : apply_raw<intrinsic::erase_key, AssociativeSequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP
