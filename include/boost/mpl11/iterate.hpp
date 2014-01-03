/*!
 * @file
 * Defines `boost::mpl11::iterate`.
 */

#ifndef BOOST_MPL11_ITERATE_HPP
#define BOOST_MPL11_ITERATE_HPP

#include <boost/mpl11/fwd/iterate.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/forward_sequence.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename X>
    struct iterate { using type = iterate; };

    template <typename F, typename X>
    struct tag_of<iterate<F, X>> {
        using type = forward_sequence_tag;
    };

    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    template <typename F, typename X>
    struct head<iterate<F, X>> {
        using type = X;
    };

    template <typename F, typename X>
    struct tail<iterate<F, X>> {
        using type = iterate<F, typename apply<F, X>::type>;
    };

    template <typename F, typename X>
    struct is_empty<iterate<F, X>>
        : false_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATE_HPP
