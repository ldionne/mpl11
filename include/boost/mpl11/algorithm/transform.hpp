/*!
 * @file
 * This file defines the `boost::mpl11::transform` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_TRANSFORM_HPP
#define BOOST_MPL11_ALGORITHM_TRANSFORM_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace algorithm {
    struct transform : detail::tag_dispatched<transform> {
        struct mpl11 {
            struct is_inplace_transformation;
        };
    };
}

template <typename Sequence, typename ...Args>
struct transform
    : apply_raw<algorithm::transform, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_TRANSFORM_HPP
