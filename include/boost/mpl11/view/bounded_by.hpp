/*!
 * @file
 * Defines `boost::mpl11::view::bounded_by`.
 */

#ifndef BOOST_MPL11_VIEW_BOUNDED_BY_HPP
#define BOOST_MPL11_VIEW_BOUNDED_BY_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace view {
    /*!
     * @ingroup view
     *
     * View over a range of elements delimited by [`First`, `Last`).
     *
     * `bounded_by` is either a `ForwardSequence`, a `BidirectionalSequence`
     * or a `RandomAccessSequence`, depending on the category of the
     * underlying iterators.
     */
    template <typename First, typename Last>
    struct bounded_by BOOST_MPL11_DOXYGEN_ONLY({ });
} // end namespace view

template <typename First, typename Last>
struct dispatch<tag::begin, view::bounded_by<First, Last>>
    : identity<First>
{ };

template <typename First, typename Last>
struct dispatch<tag::end, view::bounded_by<First, Last>>
    : identity<Last>
{ };

namespace bounded_by_detail {
    auto pick_category(category::random_access_iterator*)
        -> category::random_access_sequence
    ;

    auto pick_category(category::bidirectional_iterator*)
        -> category::bidirectional_sequence
    ;

    auto pick_category(category::forward_iterator*)
        -> category::forward_sequence
    ;
} // end namespace bounded_by_detail

template <typename First, typename Last>
struct dispatch<tag::category_of, view::bounded_by<First, Last>>
    : identity<
        decltype(
            bounded_by_detail::pick_category(
                (typename intrinsic::category_of<First>::type*)nullptr
            )
        )
    >
{
    static_assert(detail::is_same<
        typename intrinsic::category_of<First>::type,
        typename intrinsic::category_of<Last>::type
    >::value,
    "Attempt to use `bounded_by<First, Last>` with `First` and "
    "`Last` iterators having different categories.");
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_BOUNDED_BY_HPP
