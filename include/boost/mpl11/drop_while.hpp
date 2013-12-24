/*!
 * @file
 * Defines `boost::mpl11::drop_while`.
 */

#ifndef BOOST_MPL11_DROP_WHILE_HPP
#define BOOST_MPL11_DROP_WHILE_HPP

#include <boost/mpl11/fwd/drop_while.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/fwd/length.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/head.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tail.hpp>


namespace boost { namespace mpl11 {
    namespace drop_while_detail {
        template <typename Predicate, typename Sequence,
            bool = is_empty<Sequence>::value>
        struct consume;

        template <typename Predicate, typename Sequence>
        struct consume<Predicate, Sequence, false>
            : detail::conditional<
                apply<Predicate, typename head<Sequence>::type>::type::value,
                consume<Predicate, typename tail<Sequence>::type>,
                identity<Sequence>
            >::type
        { };

        template <typename Predicate, typename Sequence>
        struct consume<Predicate, Sequence, true> {
            using type = Sequence;
        };
    }

    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    template <typename Predicate, typename Sequence>
    struct head<drop_while<Predicate, Sequence>>
        : head<typename drop_while_detail::consume<Predicate, Sequence>::type>
    { };

    template <typename Predicate, typename Sequence>
    struct tail<drop_while<Predicate, Sequence>>
        : tail<typename drop_while_detail::consume<Predicate, Sequence>::type>
    { };

    template <typename Predicate, typename Sequence>
    struct is_empty<drop_while<Predicate, Sequence>>
        : is_empty<typename drop_while_detail::consume<Predicate, Sequence>::type>
    { };


    /////////////////////////////////
    // FiniteSequence
    /////////////////////////////////
    template <typename Predicate, typename Sequence>
    struct length<drop_while<Predicate, Sequence>>
        : length<typename drop_while_detail::consume<Predicate, Sequence>::type>
    { };

    template <typename Predicate, typename Sequence, typename F>
    struct unpack<drop_while<Predicate, Sequence>, F>
        : unpack<typename drop_while_detail::consume<Predicate, Sequence>::type, F>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DROP_WHILE_HPP
