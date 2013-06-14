/*!
 * @file
 * This file defines the `boost::mpl11::deref` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_DEREF_HPP
#define BOOST_MPL11_INTRINSIC_DEREF_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct deref : detail::tag_dispatched<deref> {

    };
}

template <typename Iterator, typename ...Args>
struct deref
    : apply_raw<intrinsic::deref, Iterator, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_DEREF_HPP
