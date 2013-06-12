/*!
 * @file
 * This file defines the `boost::mpl11::erase` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_HPP

#include <boost/mpl11/detail/none.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct erase_impl; }

template <typename Sequence, typename First, typename Last = detail::none>
struct erase
    : detail::tag_dispatched<
        extension::erase_impl, Sequence, First, Last
    >
{ };

template <typename Sequence, typename Position>
struct erase<Sequence, Position, detail::none>
    : detail::tag_dispatched<
        extension::erase_impl, Sequence, Position
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_ERASE_HPP
