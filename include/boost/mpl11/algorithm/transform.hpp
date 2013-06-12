/*!
 * @file
 * This file defines the `boost::mpl11::transform` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_TRANSFORM_HPP
#define BOOST_MPL11_ALGORITHM_TRANSFORM_HPP

#include <boost/mpl11/detail/default_inserter.hpp>
#include <boost/mpl11/detail/none.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct transform_impl; }

template <typename Sequence, typename UnaryOp, typename Inserter = detail::none>
struct transform
    : detail::tag_dispatched<
        extension::transform_impl, Sequence, UnaryOp, Inserter
    >
{ };

template <typename Sequence, typename UnaryOp>
struct transform<Sequence, UnaryOp, detail::none>
    : transform<Sequence, UnaryOp, detail::default_inserter<Sequence>>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_TRANSFORM_HPP
