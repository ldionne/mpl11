/*!
 * @file
 * This file defines the `boost::mpl11::prior` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_PRIOR_HPP
#define BOOST_MPL11_INTRINSIC_PRIOR_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct prior : detail::tag_dispatched<prior> {

    };
}

template <typename Iterator, typename ...Args>
struct prior
    : apply_raw<intrinsic::prior, Iterator, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_PRIOR_HPP
