/*!
 * @file
 * This file defines the `boost::mpl11::at` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_AT_HPP
#define BOOST_MPL11_INTRINSIC_AT_HPP

#include <boost/mpl11/detail/none.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/size_t.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct at_impl; }

template <typename AssociativeSequence,
          typename Key,
          typename Default = detail::none>
struct at
    : detail::tag_dispatched<
        extension::at_impl, AssociativeSequence, Key, Default
    >
{ };

template <typename Sequence, typename N>
struct at<Sequence, N, detail::none>
    : detail::tag_dispatched<
        extension::at_impl, Sequence, N
    >
{ };

template <typename Sequence, size_t<0>::value_type N>
struct at_c
    : at<Sequence, size_t<N>>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_AT_HPP
