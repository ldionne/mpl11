/*!
 * @file
 * Defines `boost::mpl11::RandomAccessIterator::distance`.
 */

#ifndef BOOST_MPL11_RANDOM_ACCESS_ITERATOR_DISTANCE_HPP
#define BOOST_MPL11_RANDOM_ACCESS_ITERATOR_DISTANCE_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/random_access_iterator/random_access_iterator.hpp>


namespace boost { namespace mpl11 {
    template <typename First, typename Last>
    struct RandomAccessIterator::distance
        : detail::not_implemented<distance<First, Last>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RANDOM_ACCESS_ITERATOR_DISTANCE_HPP
