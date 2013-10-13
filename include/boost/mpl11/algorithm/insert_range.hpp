/*!
 * @file
 * Defines `boost::mpl11::insert_range`.
 */

#ifndef BOOST_MPL11_ALGORITHM_INSERT_RANGE_HPP
#define BOOST_MPL11_ALGORITHM_INSERT_RANGE_HPP

#include <boost/mpl11/algorithm/erase_key.hpp>
#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/algorithm/insert_range_fwd.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/joined.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Range>
struct dispatch<tag::default_<tag::insert_range>, Sequence, Range>
    : identity<
        view::joined<
            Range,
            typename foldl<
                Range, Sequence,
                erase_key<_1, key_of<Range, _2>>
            >::type
        >
    >
{ };

template <typename Sequence, typename Position, typename Range>
struct dispatch<tag::default_<tag::insert_range>, Sequence, Position, Range>
    : identity<
        view::joined<
            view::bounded_by<
                typename begin<Sequence>::type, Position
            >,
            Range,
            view::bounded_by<
                Position, typename end<Sequence>::type
            >
        >
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_INSERT_RANGE_HPP
