/*!
 * @file
 * This file defines the `boost::mpl11::pop_back` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_POP_BACK_HPP
#define BOOST_MPL11_INTRINSIC_POP_BACK_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct pop_back_impl; }

template <typename Sequence>
struct pop_back
    : detail::tag_dispatched<
        extension::pop_back_impl, Sequence
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_POP_BACK_HPP
