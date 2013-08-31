/*!
 * @file
 * Defines `boost::mpl11::view::filtered`.
 */

#ifndef BOOST_MPL11_VIEW_FILTERED_HPP
#define BOOST_MPL11_VIEW_FILTERED_HPP

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/tagged_with.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/facade.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/tag_of.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace view {
/*!
 * @ingroup Views
 * View into the subset of elements of `Sequence` satisfying `Predicate`.
 *
 * Regardless of the category of the underlying sequence, `filtered`
 * is only a forward sequence.
 */
template <typename Sequence, typename Predicate>
struct filtered {
private:
    using Last = typename end<Sequence>::type;

    template <typename Iterator>
    struct filter_iterator;

    template <typename Iterator>
    struct make_filter_iterator
        : identity<
            detail::tagged_with<tag::facade,
                filter_iterator<
                    typename find_if<
                        bounded_by<Iterator, Last>,
                        Predicate
                    >::type
                >
            >
        >
    { };

    template <typename Iterator>
    struct filter_iterator {
        template <typename OperationTag, typename ...Args>
        struct apply;

        template <typename Self>
        struct apply<tag::next, Self>
            : make_filter_iterator<typename next<Iterator>::type>
        { };

        template <typename Self>
        struct apply<tag::deref, Self>
            : deref<Iterator>
        { };

        template <typename Self>
        struct apply<tag::category_of, Self>
            : identity<category::forward_iterator>
        { };
    };

public:
    template <typename OperationTag, typename ...Args>
    struct apply;

    template <typename Self>
    struct apply<tag::begin, Self>
        : make_filter_iterator<
            typename begin<Sequence>::type
        >
    { };

    template <typename Self>
    struct apply<tag::end, Self>
        : make_filter_iterator<Last>
    { };

    template <typename Self>
    struct apply<tag::category_of, Self>
        : identity<category::forward_sequence>
    { };
};
} // end namespace view

template <typename Sequence, typename Predicate>
struct tag_of<view::filtered<Sequence, Predicate>>
    : identity<tag::facade>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_FILTERED_HPP
