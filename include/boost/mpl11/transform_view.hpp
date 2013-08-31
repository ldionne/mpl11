/*!
 * @file
 * Defines `boost::mpl11::transform_view`.
 */

#ifndef BOOST_MPL11_TRANSFORM_VIEW_HPP
#define BOOST_MPL11_TRANSFORM_VIEW_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace transform_view_detail {
    template <typename First, typename Last, typename F>
    struct transform_iterator;

    template <typename OperationTag, typename First, typename Last, typename F>
    struct dispatch;


    template <typename First, typename Last, typename F>
    struct dispatch<tag::next, First, Last, F>
        : identity<
            transform_iterator<typename next<First>::type, Last, F>
        >
    { };

    template <typename Last, typename F>
    struct dispatch<tag::next, Last, Last, F>;


    template <typename First, typename Last, typename F>
    struct dispatch<tag::deref, First, Last, F>
        : apply_wrap<F, typename deref<First>::type>
    { };

    template <typename Last, typename F>
    struct dispatch<tag::deref, Last, Last, F>;


    template <typename First, typename Last, typename F>
    struct dispatch<tag::category_of, First, Last, F>
        : identity<category::forward_iterator>
    { };
} // end namespace transform_view_detail

template <typename Op, typename First, typename Last, typename F>
struct dispatch<Op, transform_view_detail::transform_iterator<First, Last, F>>
    : lazy_always<transform_view_detail::dispatch<Op, First, Last, F>>
{ };

/*!
 * View over a `Sequence`'s elements transformed by the application of `F`.
 *
 * Regardless of the category of the underlying sequence, `transform_view`
 * is only a forward sequence.
 */
template <typename Sequence, typename F>
struct transform_view BOOST_MPL11_DOXYGEN_ONLY({ });

template <typename Sequence, typename F>
struct dispatch<tag::begin, transform_view<Sequence, F>>
    : always<
        transform_view_detail::transform_iterator<
            typename begin<Sequence>::type,
            typename end<Sequence>::type,
            typename lambda<F>::type
        >
    >
{ };

template <typename Sequence, typename F>
struct dispatch<tag::end, transform_view<Sequence, F>>
    : always<
        transform_view_detail::transform_iterator<
            typename end<Sequence>::type,
            typename end<Sequence>::type,
            typename lambda<F>::type
        >
    >
{ };

template <typename Sequence, typename F>
struct dispatch<tag::category_of, transform_view<Sequence, F>>
    : always<category::forward_sequence>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TRANSFORM_VIEW_HPP
