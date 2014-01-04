/*!
 * @file
 * Defines `boost::mpl11::cons`.
 */

#ifndef BOOST_MPL11_CONS_HPP
#define BOOST_MPL11_CONS_HPP

#include <boost/mpl11/fwd/cons.hpp>

#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
    template <typename Head, typename Tail>
    struct cons { using type = cons; };

    template <typename Head, typename Tail>
    struct tag_of<cons<Head, Tail>> { using type = sequence_tag; };

    template <typename Head, typename Tail>
    struct sequence_traits<cons<Head, Tail>>
        : sequence_traits<Tail>
    { };

    template <typename Head, typename Tail>
    struct head_impl<cons<Head, Tail>> {
        using type = Head;
    };

    template <typename Head, typename Tail>
    struct tail_impl<cons<Head, Tail>> {
        using type = Tail;
    };

    template <typename Head, typename Tail>
    struct is_empty_impl<cons<Head, Tail>>
        : false_
    { };

    template <typename Head, typename Tail>
    struct length_impl<cons<Head, Tail>>
        : size_t<length<Tail>::value + 1>
    { };

    template <typename Head, typename Tail, typename F>
    struct unpack_impl<cons<Head, Tail>, F> {
        using type = typename unpack<Tail, partial<F, Head>>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONS_HPP
