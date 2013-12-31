/*!
 * @file
 * Defines `boost::mpl11::find_if`.
 */

#ifndef BOOST_MPL11_FIND_IF_HPP
#define BOOST_MPL11_FIND_IF_HPP

#include <boost/mpl11/fwd/find_if.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
    namespace find_if_detail {
        template <
            typename First, typename Last,
            typename Predicate,
            bool = equal<First, Last>::value
        >
        struct find_if_impl;

        template <
            typename First, typename Last,
            typename Predicate,
            bool = apply_t<Predicate, deref_t<First>>::value
        >
        struct return_or_continue;

        template <typename First, typename Last, typename Predicate>
        struct find_if_impl<First, Last, Predicate, true> {
            using type = Last;
        };

        template <typename First, typename Last, typename Predicate>
        struct find_if_impl<First, Last, Predicate, false>
            : return_or_continue<First, Last, Predicate>
        { };

        template <typename First, typename Last, typename Predicate>
        struct return_or_continue<First, Last, Predicate, false>
            : find_if_impl<next_t<First>, Last, Predicate>
        { };

        template <typename First, typename Last, typename Predicate>
        struct return_or_continue<First, Last, Predicate, true> {
            using type = First;
        };
    } // end namespace find_if_detail

    template <typename Sequence, typename Predicate>
    struct find_if
        : find_if_detail::find_if_impl<
            begin_t<Sequence>,
            end_t<Sequence>,
            Predicate
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FIND_IF_HPP
