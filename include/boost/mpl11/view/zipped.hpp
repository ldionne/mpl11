/*!
 * @file
 * Defines `boost::mpl11::view::zipped`.
 */

#ifndef BOOST_MPL11_VIEW_ZIPPED_HPP
#define BOOST_MPL11_VIEW_ZIPPED_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     *
     * View over the elements of several zipped sequences.
     *
     * Specifically, each element of `zipped` is a sequence containing
     * the elements of each zipped sequence at that position.
     *
     * The number of elements in `zipped` is equal to the number of
     * elements of the smallest zipped sequence.
     *
     * Regardless of the category of the underlying sequences, `zipped`
     * is only a forward sequence.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - The sequences to zip are specified using variadic template parameters
     *   instead of being provided as a sequence of sequences.
     * - The type of the sequence used to pass the arguments to `zipped`
     *   does not affect the type of its elements, since the arguments are
     *   not provided in a sequence anymore.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct zipped BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view


#include <boost/mpl11/algorithm/min.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/joined.hpp>
#include <boost/mpl11/view/single_element.hpp>
#include <boost/mpl11/view/sliced.hpp>


namespace boost { namespace mpl11 {
namespace zipped_detail {
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
    using view_on = view::joined<
        view::single_element<T1>,
        view::single_element<T2>,
        view::single_element<Tn>...
    >;

    template <typename ...Iterators>
    struct dispatch<tag::deref, Iterators...>
        : identity<
            view_on<typename deref<Iterators>::type...>
        >
    { };

    template <typename ...Iterators>
    struct dispatch<tag::category_of, Iterators...>
        : identity<category::forward_iterator>
    { };
} // end namespace zipped_detail

template <typename OperationTag, typename ...Iterators>
struct dispatch<OperationTag, zipped_detail::zip_iterator<Iterators...>>
    : zipped_detail::dispatch<OperationTag, Iterators...>
{ };

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::size, view::zipped<S1, S2, Sn...>>
    : algorithm::min<
        typename size<S1>::type,
        typename size<S2>::type,
        typename size<Sn>::type...
    >
{ };

template <typename ...Sequences>
struct dispatch<tag::begin, view::zipped<Sequences...>>
    : identity<
        zipped_detail::zip_iterator<
            typename begin<
                view::sliced<
                    Sequences,
                    ulong<0>,
                    typename size<view::zipped<Sequences...>>::type
                >
            >::type...
        >
    >
{ };

template <typename ...Sequences>
struct dispatch<tag::end, view::zipped<Sequences...>>
    : identity<
        zipped_detail::zip_iterator<
            typename end<
                view::sliced<
                    Sequences,
                    ulong<0>,
                    typename size<view::zipped<Sequences...>>::type
                >
            >::type...
        >
    >
{ };

template <typename ...Sequences>
struct dispatch<tag::category_of, view::zipped<Sequences...>>
    : identity<category::forward_sequence>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_ZIPPED_HPP
