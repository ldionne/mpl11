/*!
 * @file
 * Defines `boost::mpl11::iterator_range`.
 */

#ifndef BOOST_MPL11_ITERATOR_RANGE_HPP
#define BOOST_MPL11_ITERATOR_RANGE_HPP

#include <boost/mpl11/fwd/iterator_range.hpp>

#include <boost/mpl11/category/bidirectional_iterator.hpp>
#include <boost/mpl11/category/bidirectional_sequence.hpp>
#include <boost/mpl11/category/forward_iterator.hpp>
#include <boost/mpl11/category/forward_sequence.hpp>
#include <boost/mpl11/category/random_access_iterator.hpp>
#include <boost/mpl11/category/random_access_sequence.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
template <typename First, typename Last>
struct dispatch<tag::begin, iterator_range<First, Last>>
    : identity<First>
{ };

template <typename First, typename Last>
struct dispatch<tag::end, iterator_range<First, Last>>
    : identity<Last>
{ };

namespace iterator_range_detail {
    auto pick_category(category::random_access_iterator*)
        -> category::random_access_sequence
    ;

    auto pick_category(category::bidirectional_iterator*)
        -> category::bidirectional_sequence
    ;

    auto pick_category(category::forward_iterator*)
        -> category::forward_sequence
    ;
} // end namespace iterator_range_detail

template <typename First, typename Last>
struct dispatch<tag::category_of, iterator_range<First, Last>>
    : identity<
        decltype(
            iterator_range_detail::pick_category(
                (typename category_of<First>::type*)nullptr
            )
        )
    >
{
    static_assert(equal_to<
        typename category_of<First>::type,
        typename category_of<Last>::type
    >::type::value,
    "Attempt to use `iterator_range<First, Last>` with `First` and "
    "`Last` iterators having different categories.");
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATOR_RANGE_HPP
