/*!
 * @file
 * This file defines the `boost::mpl11::advance` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_ADVANCE_HPP
#define BOOST_MPL11_ALGORITHM_ADVANCE_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace algorithm {
    struct advance : detail::tag_dispatched<advance> {
        struct mpl11 {
            struct is_inplace_transformation;
        };
    };
}

template <typename Iterator, typename ...Args>
struct advance
    : apply_raw<algorithm::advance, Iterator, Args...>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_ADVANCE_HPP
