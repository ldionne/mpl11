/*!
 * @file
 * Defines `boost::mpl11::insert_range`.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/insert_range_fwd.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/joined.hpp>


namespace boost { namespace mpl11 {
namespace insert_range_detail {
    template <typename Sequence, typename Position, typename Range,
              bool = equal_to<
                Position, typename end<Sequence>::type
              >::type::value>
    struct insert_range_impl
        : algorithm::copy<
            view::joined<Sequence, Range>,
            typename clear<Sequence>::type
        >
    { };

    template <typename Sequence, typename Position, typename Range>
    struct insert_range_impl<Sequence, Position, Range, false>
        : algorithm::copy<
            view::joined<
                view::bounded_by<
                    typename begin<Sequence>::type, Position
                >,
                Range,
                view::bounded_by<
                    Position, typename end<Sequence>::type
                >
            >,
            typename clear<Sequence>::type
        >
    { };
} // end namespace insert_range_detail

template <typename Sequence, typename Range>
struct dispatch<tag::default_<tag::insert_range>, Sequence, Range>
    : algorithm::foldl<Range, Sequence, quote<insert>>
{ };

template <typename Sequence, typename Position, typename Range>
struct dispatch<tag::default_<tag::insert_range>, Sequence, Position, Range>
    : insert_range_detail::insert_range_impl<Sequence, Position, Range>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
