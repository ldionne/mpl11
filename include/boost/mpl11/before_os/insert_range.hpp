/*!
 * @file
 * Defines `boost::mpl11::insert_range`.
 */

#ifndef BOOST_MPL11_INSERT_RANGE_HPP
#define BOOST_MPL11_INSERT_RANGE_HPP

#include <boost/mpl11/fwd/insert_range.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/insert.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Range>
struct dispatch<tag::insert_range, Sequence, Range>
    : foldl<Range, Sequence, quote<insert>>
{ };

template <typename Sequence, typename Position, typename Range>
struct dispatch<tag::insert_range, Sequence, Position, Range>
    : identity<
        joined_view<
            iterator_range<
                typename begin<Sequence>::type, Position
            >,
            Range,
            iterator_range<
                Position, typename end<Sequence>::type
            >
        >
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_RANGE_HPP
