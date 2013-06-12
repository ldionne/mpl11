/*!
 * @file
 * This file defines the `boost::mpl11::distance` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_DISTANCE_HPP
#define BOOST_MPL11_ALGORITHM_DISTANCE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/traits.hpp>

#include <boost/type_traits/is_same.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct distance_impl; }

template <typename First, typename Last>
struct distance
    : detail::tag_dispatched<
        extension::distance_impl, First, Last
    >
{
    static_assert(is_same<
        typename traits::tag_of<First>::type,
        typename traits::tag_of<Last>::type
    >::value, "trying to compute the distance between two iterators "
              "with different dispatch tags");
};
}}}

#endif // !BOOST_MPL11_ALGORITHM_DISTANCE_HPP
