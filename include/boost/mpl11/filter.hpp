/*!
 * @file
 * Defines `boost::mpl11::filter`.
 */

#ifndef BOOST_MPL11_FILTER_HPP
#define BOOST_MPL11_FILTER_HPP

#include <boost/mpl11/fwd/filter.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/count_if.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/equal.hpp>
#include <boost/mpl11/fwd/length.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// filter iterator
//////////////////////////////////////////////////////////////////////////////
namespace filter_detail {
    template <typename First, typename Last, typename Predicate>
    struct filter_iterator;
}

template <typename First, typename Last, typename Predicate, typename Def>
struct class_of<filter_detail::filter_iterator<First, Last, Predicate>, Def> {
    using type = ForwardIterator;
};

template <typename First, typename Last, typename Predicate>
struct next<filter_detail::filter_iterator<First, Last, Predicate>> {
    using type = filter_detail::filter_iterator<
        find_if_t<iterator_range<next_t<First>, Last>, Predicate>,
        Last,
        Predicate
    >;
};

template <typename First, typename Last, typename Predicate>
struct deref<filter_detail::filter_iterator<First, Last, Predicate>>
    : deref<First>
{ };

template <typename F1, typename F2, typename Last, typename Pred>
struct equal<
    filter_detail::filter_iterator<F1, Last, Pred>,
    filter_detail::filter_iterator<F2, Last, Pred>
>
    : equal<F1, F2>
{ };


//////////////////////////////////////////////////////////////////////////////
// filter
//////////////////////////////////////////////////////////////////////////////
template <typename Sequence, typename Predicate>
struct filter
    : apply<new_<Sequence>, filter<Sequence, Predicate>>
{ };

template <typename Seq, typename Pred, typename Default>
struct class_of<filter<Seq, Pred>, Default> {
    using type = Sequence;
};

template <typename Sequence, typename Predicate>
struct begin<filter<Sequence, Predicate>> {
    using type = filter_detail::filter_iterator<
        find_if_t<Sequence, Predicate>,
        end_t<Sequence>,
        Predicate
    >;
};

template <typename Sequence, typename Predicate>
struct end<filter<Sequence, Predicate>> {
    using type = filter_detail::filter_iterator<
        end_t<Sequence>,
        end_t<Sequence>,
        Predicate
    >;
};

template <typename Sequence, typename Predicate>
struct length<filter<Sequence, Predicate>>
    : count_if<Sequence, Predicate>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FILTER_HPP
