/*!
 * @file
 * Defines `boost::mpl11::RandomAccessIterable`.
 */

#ifndef BOOST_MPL11_RANDOM_ACCESS_ITERABLE_RANDOM_ACCESS_ITERABLE_HPP
#define BOOST_MPL11_RANDOM_ACCESS_ITERABLE_RANDOM_ACCESS_ITERABLE_HPP

#include <boost/mpl11/fwd/random_access_iterable.hpp>

#include <boost/mpl11/bidirectional_iterable/bidirectional_iterable.hpp>


namespace boost { namespace mpl11 {
    struct RandomAccessIterable : BidirectionalIterable {
        template <typename I, typename N>
        struct at;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RANDOM_ACCESS_ITERABLE_RANDOM_ACCESS_ITERABLE_HPP
