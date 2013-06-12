/*!
 * @file
 * This file defines the `boost::mpl11::advance` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_ADVANCE_HPP
#define BOOST_MPL11_ALGORITHM_ADVANCE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct advance_impl; }

template <typename Iterator, typename N>
struct advance
    : detail::tag_dispatched<
        extension::advance_impl, Iterator, N
    >
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_ADVANCE_HPP
