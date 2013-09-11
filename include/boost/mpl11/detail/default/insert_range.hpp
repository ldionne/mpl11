/*!
 * @file
 * Defines the default implementation of
 * `boost::mpl11::intrinsic::insert_range`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_INSERT_RANGE_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_INSERT_RANGE_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/joined.hpp>


namespace boost { namespace mpl11 {
namespace insert_range_detail {
    template <typename Sequence, typename Position, typename Range,
              bool = equal_to<
                Position, typename intrinsic::end<Sequence>::type
              >::type::value>
    struct insert_range_impl
        : algorithm::copy<
            view::joined<Sequence, Range>,
            typename intrinsic::clear<Sequence>::type
        >
    { };

    template <typename Sequence, typename Position, typename Range>
    struct insert_range_impl<Sequence, Position, Range, false>
        : algorithm::copy<
            view::joined<
                view::bounded_by<
                    typename intrinsic::begin<Sequence>::type, Position
                >,
                Range,
                view::bounded_by<
                    Position, typename intrinsic::end<Sequence>::type
                >
            >,
            typename intrinsic::clear<Sequence>::type
        >
    { };
} // end namespace insert_range_detail

template <typename Sequence, typename Range>
struct dispatch<detail::default_<tag::insert_range>, Sequence, Range>
    : algorithm::foldl<Range, Sequence, quote<intrinsic::insert>>
{ };

template <typename Sequence, typename Position, typename Range>
struct dispatch<detail::default_<tag::insert_range>, Sequence, Position, Range>
    : insert_range_detail::insert_range_impl<Sequence, Position, Range>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_INSERT_RANGE_HPP
