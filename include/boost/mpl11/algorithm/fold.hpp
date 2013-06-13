/*!
 * @file
 * This file defines the `boost::mpl11::fold` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_FOLD_HPP
#define BOOST_MPL11_ALGORITHM_FOLD_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Sequence, typename ...Args>
struct fold
    : detail::tag_dispatched<fold, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_FOLD_HPP
