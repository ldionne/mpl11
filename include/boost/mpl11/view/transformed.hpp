/*!
 * @file
 * Defines `boost::mpl11::view::transformed`.
 */

#ifndef BOOST_MPL11_VIEW_TRANSFORMED_HPP
#define BOOST_MPL11_VIEW_TRANSFORMED_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace transformed_detail {
    template <typename First, typename Last, typename F>
    struct transform_iterator;

    template <typename OperationTag, typename First, typename Last, typename F>
    struct dispatch;


    template <typename First, typename Last, typename F>
    struct dispatch<tag::next, First, Last, F>
        : identity<
            transform_iterator<typename intrinsic::next<First>::type, Last, F>
        >
    { };

    template <typename Last, typename F>
    struct dispatch<tag::next, Last, Last, F>;


    template <typename First, typename Last, typename F>
    struct dispatch<tag::deref, First, Last, F>
        : apply_wrap<F, typename intrinsic::deref<First>::type>
    { };

    template <typename Last, typename F>
    struct dispatch<tag::deref, Last, Last, F>;


    template <typename First, typename Last, typename F>
    struct dispatch<tag::category_of, First, Last, F>
        : identity<category::forward_iterator>
    { };
} // end namespace transformed_detail

template <typename Op, typename First, typename Last, typename F>
struct dispatch<Op, transformed_detail::transform_iterator<First, Last, F>>
    : lazy_always<transformed_detail::dispatch<Op, First, Last, F>>
{ };

namespace view {
    /*!
     * @ingroup Views
     *
     * View over a `Sequence`'s elements transformed by the application of `F`.
     *
     * Regardless of the category of the underlying sequence, `transformed`
     * is only a forward sequence.
     */
    template <typename Sequence, typename F>
    struct transformed BOOST_MPL11_DOXYGEN_ONLY({ });
} // end namespace view

template <typename Sequence, typename F>
struct dispatch<tag::begin, view::transformed<Sequence, F>>
    : always<
        transformed_detail::transform_iterator<
            typename intrinsic::begin<Sequence>::type,
            typename intrinsic::end<Sequence>::type,
            typename lambda<F>::type
        >
    >
{ };

template <typename Sequence, typename F>
struct dispatch<tag::end, view::transformed<Sequence, F>>
    : always<
        transformed_detail::transform_iterator<
            typename intrinsic::end<Sequence>::type,
            typename intrinsic::end<Sequence>::type,
            typename lambda<F>::type
        >
    >
{ };

template <typename Sequence, typename F>
struct dispatch<tag::category_of, view::transformed<Sequence, F>>
    : always<category::forward_sequence>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_TRANSFORMED_HPP
