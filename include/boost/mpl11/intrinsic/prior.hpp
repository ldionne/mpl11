/*!
 * @file
 * This file defines the `boost::mpl11::prior` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_PRIOR_HPP
#define BOOST_MPL11_INTRINSIC_PRIOR_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct prior_impl; }

template <typename Iterator>
struct prior
    : detail::tag_dispatched<
        extension::prior_impl, Iterator
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_PRIOR_HPP
