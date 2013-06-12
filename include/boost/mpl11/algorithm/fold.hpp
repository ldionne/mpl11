/*!
 * @file
 * This file defines the `boost::mpl11::fold` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_FOLD_HPP
#define BOOST_MPL11_ALGORITHM_FOLD_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct fold_impl; }

template <typename Sequence, typename State, typename BinaryOp>
struct fold
    : detail::tag_dispatched<
        extension::fold_impl, Sequence, State, BinaryOp
    >
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_FOLD_HPP
