/*!
 * @file
 * Defines `boost::mpl11::iterate`.
 */

#ifndef BOOST_MPL11_ITERATE_HPP
#define BOOST_MPL11_ITERATE_HPP

#include <boost/mpl11/fwd/iterate.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/sequence/sequence.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename X>
    struct iterate { using type = iterate; };

    template <typename F, typename X>
    struct tag_of<iterate<F, X>> { using type = sequence_tag; };

    /////////////////////////////////
    // Minimal complete definition
    /////////////////////////////////
    template <typename F, typename X>
    struct head_impl<iterate<F, X>> {
        using type = X;
    };

    template <typename F, typename X>
    struct tail_impl<iterate<F, X>> {
        using type = iterate<F, typename apply<F, X>::type>;
    };

    template <typename F, typename X>
    struct is_empty_impl<iterate<F, X>>
        : false_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATE_HPP
