/*!
 * @file
 * Defines `boost::mpl11::view::onto_iterators`.
 */

#ifndef BOOST_MPL11_VIEW_ONTO_ITERATORS_HPP
#define BOOST_MPL11_VIEW_ONTO_ITERATORS_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace onto_iterators_detail {
    template <typename Iterator>
    struct raw_iterator;

    template <typename OperationTag, typename Iterator>
    struct dispatch;

    template <typename Iterator>
    struct dispatch<tag::next, Iterator>
        : identity<
            raw_iterator<typename intrinsic::next<Iterator>::type>
        >
    { };

    template <typename Iterator>
    struct dispatch<tag::prior, Iterator>
        : identity<
            raw_iterator<typename intrinsic::prior<Iterator>::type>
        >
    { };

    template <typename Iterator>
    struct dispatch<tag::deref, Iterator>
        : identity<Iterator>
    { };

    template <typename Iterator>
    struct dispatch<tag::category_of, Iterator>
        : category_of<Iterator>
    { };
} // end namespace onto_iterators_detail

template <typename Op, typename Iterator>
struct dispatch<Op, onto_iterators_detail::raw_iterator<Iterator>>
    : lazy_always<onto_iterators_detail::dispatch<Op, Iterator>>
{ };

namespace view {
    /*!
     * @ingroup Views
     *
     * View onto the iterators of a sequence.
     *
     * The category of `onto_iterators` depends on the category of the
     * underlying `Sequence`.
     */
    template <typename Sequence>
    struct onto_iterators BOOST_MPL11_DOXYGEN_ONLY({ });
} // end namespace view

template <typename OperationTag, typename Sequence, typename ...Args>
struct dispatch<OperationTag, view::onto_iterators<Sequence>, Args...>
    : dispatch<
        OperationTag,
        view::bounded_by<
            onto_iterators_detail::raw_iterator<
                typename intrinsic::begin<Sequence>::type
            >,
            onto_iterators_detail::raw_iterator<
                typename intrinsic::end<Sequence>::type
            >
        >,
        Args...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_ONTO_ITERATORS_HPP
