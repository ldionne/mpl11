/*!
 * @file
 * Defines `boost::mpl11::snoc`.
 */

#ifndef BOOST_MPL11_ITERABLE_SNOC_HPP
#define BOOST_MPL11_ITERABLE_SNOC_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/iterable/iterable.hpp>
#include <boost/mpl11/list.hpp>
#include <boost/mpl11/partial.hpp>


namespace boost { namespace mpl11 {
    template <typename S, typename X>
    struct snoc {
        using type = typename if_c<is_empty<S>::value, list<X>, snoc>::type;
    };

    template <typename S, typename X>
    struct tag_of<snoc<S, X>> { using type = iterable_tag; };

    template <typename S, typename X>
    struct sequence_traits<snoc<S, X>> : sequence_traits<S> { };

    template <typename S, typename X>
    struct head_impl<snoc<S, X>> {
        using type = typename head<S>::type;
    };

    template <typename S, typename X>
    struct tail_impl<snoc<S, X>> {
        using type = typename snoc<
            typename tail<S>::type, X
        >::type;
    };

    template <typename S, typename X>
    struct is_empty_impl<snoc<S, X>>
        : false_
    { };

    template <typename S, typename X>
    struct length_impl<snoc<S, X>>
        : size_t<length<S>::value + 1>
    { };

    template <typename S, typename X, typename F>
    struct unpack_impl<snoc<S, X>, F> {
        using type = typename apply<
            typename unpack<S, partial<into<partial>, F>>::type, X
        >::type;
    };

    template <typename S, typename X>
    struct init_impl<snoc<S, X>> {
        using type = S;
    };

    template <typename S, typename X>
    struct last_impl<snoc<S, X>> {
        using type = X;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_SNOC_HPP
