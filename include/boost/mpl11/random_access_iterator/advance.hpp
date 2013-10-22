/*!
 * @file
 * Defines `boost::mpl11::RandomAccessIterator::advance`.
 */

#ifndef BOOST_MPL11_RANDOM_ACCESS_ITERATOR_ADVANCE_HPP
#define BOOST_MPL11_RANDOM_ACCESS_ITERATOR_ADVANCE_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/random_access_iterator/random_access_iterator.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator, typename N>
    struct RandomAccessIterator::advance
        : detail::not_implemented<advance<Iterator, N>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RANDOM_ACCESS_ITERATOR_ADVANCE_HPP
