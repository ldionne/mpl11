/*!
 * @file
 * Defines `boost::mpl11::iterate`.
 */

#ifndef BOOST_MPL11_ITERATE_HPP
#define BOOST_MPL11_ITERATE_HPP

#include <boost/mpl11/fwd/iterate.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/iterable/cons.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename X>
    struct iterate
        : cons<X, iterate<F, apply<F, X>>>
    { };

    //! @todo
    //! This is a workaround. This may break if `cons` changes.
    template <typename F, typename X>
    struct sequence_traits<cons<X, iterate<F, apply<F, X>>>> {
        static constexpr bool has_O1_length = false;
        static constexpr bool has_O1_unpack = false;
        static constexpr bool is_finite = false;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATE_HPP
