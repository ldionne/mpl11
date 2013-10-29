/*!
 * @file
 * Defines `boost::mpl11::insert_range`.
 */

#ifndef BOOST_MPL11_INSERT_RANGE_HPP
#define BOOST_MPL11_INSERT_RANGE_HPP

#include <boost/mpl11/fwd/insert_range.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Position, typename First, typename Last>
    struct insert_range
        : class_<Sequence>::type::template
            insert_range<Sequence, Position, First, Last>
    { };

    // For AssociativeContainers this is <Sequence, First, Last>
    template <typename Sequence, typename Position, typename Range>
    struct insert_range<Sequence, Position, Range>
        : class_<Sequence>::type::template
            insert_range<Sequence, Position, Range>
    { };

    template <typename Sequence, typename Range>
    struct insert_range<Sequence, Range>
        : class_<Sequence>::type::template insert_range<Sequence, Range>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_RANGE_HPP
