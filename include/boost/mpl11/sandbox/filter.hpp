/*!
 * @file
 * Defines `boost::mpl11::filter`.
 */

#ifndef BOOST_MPL11_FILTER_HPP
#define BOOST_MPL11_FILTER_HPP

#include <boost/mpl11/fwd/filter.hpp>

#include <boost/mpl11/count_if.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
namespace filter_detail {
    template <typename First, typename Last, typename Predicate>
    struct filter_iterator;

    struct filter_iterator_class final : ForwardIterator {
        template <typename Iterator> struct next_impl;
        template <typename Iterator> struct deref_impl;
        template <typename Self, typename Other> struct equal_impl;

        template <typename First, typename Last, typename Predicate>
        struct next_impl<filter_iterator<First, Last, Predicate>> {
            using type = filter_iterator<
                find_if_t<iterator_range<next_t<First>, Last>, Predicate>,
                Last,
                Predicate
            >;
        };

        template <typename First, typename Last, typename Predicate>
        struct deref_impl<filter_iterator<First, Last, Predicate>>
            : deref<First>
        { };

        template <typename F1, typename F2, typename Last, typename Pred>
        struct equal_impl<
            filter_iterator<F1, Last, Pred>,
            filter_iterator<F2, Last, Pred>
        >
            : equal<F1, F2>
        { };
    };

    struct filter_class final : Sequence {
        template <typename Filter> struct begin_impl;
        template <typename Filter> struct end_impl;
        template <typename Filter> struct size_impl;

        template <typename Sequence, typename Predicate>
        struct begin_impl<filter<Sequence, Predicate>> {
            using type = filter_iterator<
                find_if_t<Sequence, Predicate>,
                end_t<Sequence>,
                Predicate
            >;
        };

        template <typename Sequence, typename Predicate>
        struct end_impl<filter<Sequence, Predicate>> {
            using type = filter_iterator<
                end_t<Sequence>,
                end_t<Sequence>,
                Predicate
            >;
        };

        template <typename Sequence, typename Predicate>
        struct size_impl<filter<Sequence, Predicate>>
            : count_if<Sequence, Predicate>
        { };
    };
} // end namespace filter_detail

template <typename Iterator, typename Predicate>
struct class_of<filter_detail::filter_iterator<Iterator, Predicate>> {
    using type = filter_detail::filter_iterator_class;
};

template <typename Sequence, typename Predicate>
struct class_of<filter<Sequence, Predicate>> {
    using type = filter_detail::filter_class;
};

template <typename Sequence, typename Predicate>
struct filter
    : new_<Sequence, filter<Sequence, Predicate>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FILTER_HPP
