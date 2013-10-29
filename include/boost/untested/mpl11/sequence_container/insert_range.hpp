/*!
 * @file
 * Defines `boost::mpl11::SequenceContainer::insert_range`.
 */

#ifndef BOOST_MPL11_SEQUENCE_CONTAINER_INSERT_RANGE_HPP
#define BOOST_MPL11_SEQUENCE_CONTAINER_INSERT_RANGE_HPP

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/insert_range.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/renew.hpp>
#include <boost/mpl11/sequence_container/sequence_container.hpp>


namespace boost { namespace mpl11 {
    template <typename SC, typename Position, typename First, typename Last>
    struct SequenceContainer::insert_range
        : mpl11::insert_range<SC, Position, iterator_range<First, Last>>
    { };

    template <typename SC, typename Position, typename Iterable>
    struct SequenceContainer::insert_range<SC, Position, Iterable>
        : renew<SC,
            joined_view<
                iterator_range<
                    typename begin<SC>::type, Position
                >,
                Iterable,
                iterator_range<
                    Position, typename end<SC>::type
                >
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_CONTAINER_INSERT_RANGE_HPP
