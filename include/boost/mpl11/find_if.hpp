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
            bool = apply<Predicate, typename deref<First>::type>::type::value
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
            : find_if_impl<typename next<First>::type, Last, Predicate>
        { };

        template <typename First, typename Last, typename Predicate>
        struct return_or_continue<First, Last, Predicate, true> {
            using type = First;
        };
    } // end namespace find_if_detail

    template <typename Sequence, typename Predicate>
    struct find_if
        : find_if_detail::find_if_impl<
            typename begin<Sequence>::type,
            typename end<Sequence>::type,
            Predicate
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FIND_IF_HPP
