/*!
 * @file
 * This file defines the `boost::mpl11::fold` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_FOLD_HPP
#define BOOST_MPL11_ALGORITHM_FOLD_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace algorithm {
    struct fold : detail::tag_dispatched<fold> {

    };
}

template <typename Sequence, typename ...Args>
struct fold
    : apply_raw<algorithm::fold, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_FOLD_HPP
