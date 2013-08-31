/*!
 * @file
 * Defines `boost::mpl11::zip_view`.
 */

#ifndef BOOST_MPL11_ZIP_VIEW_HPP
#define BOOST_MPL11_ZIP_VIEW_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/joint_view.hpp>
#include <boost/mpl11/min.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/single_view.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/sliced_view.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace zip_view_detail {
    template <typename ...Iterators>
    struct zip_iterator;

    template <typename OperationTag, typename ...Iterators>
    struct dispatch;

    template <typename ...Iterators>
    struct dispatch<tag::next, Iterators...>
        : identity<
            zip_iterator<typename next<Iterators>::type...>
        >
    { };

    template <typename T1, typename T2, typename ...Tn>
    using view = joint_view<
        single_view<T1>, single_view<T2>, single_view<Tn>...
    >;

    template <typename ...Iterators>
    struct dispatch<tag::deref, Iterators...>
        : identity<
            view<typename deref<Iterators>::type...>
        >
    { };

    template <typename ...Iterators>
    struct dispatch<tag::category_of, Iterators...>
        : identity<category::forward_iterator>
    { };
} // end namespace zip_view_detail

template <typename OperationTag, typename ...Iterators>
struct dispatch<OperationTag, zip_view_detail::zip_iterator<Iterators...>>
    : lazy_always<zip_view_detail::dispatch<OperationTag, Iterators...>>
{ };

/*!
 * View over the elements of several zipped sequences.
 *
 * Specifically, each element of the `zip_view` is a sequence containing
 * the elements of each zipped sequence at that position.
 *
 * The number of elements in the `zip_view` is equal to the number of
 * elements of the smallest zipped sequence.
 *
 * Regardless of the category of the underlying sequences, `zip_view`
 * is only a forward sequence.
 *
 * @warning
 * Differences from the original MPL:
 * - The sequences to zip are specified using variadic template parameters
 *   instead of being provided as a sequence of sequences.
 * - The type of the sequence used to pass the arguments to `zip_view`
 *   does not affect the type of its elements, since the arguments are
 *   not provided in a sequence anymore.
 */
template <typename Sequence1, typename Sequence2, typename ...SequenceN>
struct zip_view BOOST_MPL11_DOXYGEN_ONLY({ });

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::size, zip_view<S1, S2, Sn...>>
    : lazy_always<
        min<size<S1>, size<S2>, size<Sn>...>
    >
{ };

template <typename ...Sequences>
struct dispatch<tag::begin, zip_view<Sequences...>>
    : always<
        zip_view_detail::zip_iterator<
            typename begin<
                sliced_view<Sequences,
                    ulong<0>, typename size<zip_view<Sequences...>>::type
                >
            >::type...
        >
    >
{ };

template <typename ...Sequences>
struct dispatch<tag::end, zip_view<Sequences...>>
    : always<
        zip_view_detail::zip_iterator<
            typename end<
                sliced_view<Sequences,
                    ulong<0>, typename size<zip_view<Sequences...>>::type
                >
            >::type...
        >
    >
{ };

template <typename ...Sequences>
struct dispatch<tag::category_of, zip_view<Sequences...>>
    : always<category::forward_sequence>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ZIP_VIEW_HPP
