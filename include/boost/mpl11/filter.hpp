/*!
 * @file
 * Defines `boost::mpl11::filter`.
 */

#ifndef BOOST_MPL11_FILTER_HPP
#define BOOST_MPL11_FILTER_HPP

#include <boost/mpl11/fwd/filter.hpp>

#include <boost/mpl11/compose.hpp>
#include <boost/mpl11/count_if.hpp>
#include <boost/mpl11/detail/default_unpack.hpp>
#include <boost/mpl11/drop_while.hpp>
#include <boost/mpl11/fwd/init.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/last.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/head.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/length.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/reverse.hpp>
#include <boost/mpl11/tail.hpp>


namespace boost { namespace mpl11 {
    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    template <typename Predicate, typename Sequence>
    struct head<filter<Predicate, Sequence>>
        : head<drop_while<compose<quote<not_>, Predicate>, Sequence>>
    { };

    template <typename Predicate, typename Sequence>
    struct tail<filter<Predicate, Sequence>> {
        using type = filter<
            Predicate,
            typename tail<
                drop_while<compose<quote<not_>, Predicate>, Sequence>
            >::type
        >;
    };

    template <typename Predicate, typename Sequence>
    struct is_empty<filter<Predicate, Sequence>>
        : bool_<length<filter<Predicate, Sequence>>::value == 0>
    { };


    /////////////////////////////////
    // FiniteSequence
    /////////////////////////////////
    template <typename Predicate, typename Sequence>
    struct length<filter<Predicate, Sequence>>
        : count_if<Sequence, Predicate>
    { };

    template <typename Predicate, typename Sequence, typename F>
    struct unpack<filter<Predicate, Sequence>, F>
        : detail::default_unpack<filter<Predicate, Sequence>, F>
    { };


    /////////////////////////////////
    // BidirectionalSequence
    /////////////////////////////////
    template <typename Predicate, typename Sequence>
    struct last<filter<Predicate, Sequence>>
        : head<drop_while<compose<quote<not_>, Predicate>, reverse<Sequence>>>
    { };

    template <typename Predicate, typename Sequence>
    struct init<filter<Predicate, Sequence>> {
        using type = filter<
            Predicate,
            reverse<tail_t<drop_while<compose<quote<not_>, Predicate>, reverse<Sequence>>>>
        >;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FILTER_HPP
