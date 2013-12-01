/*!
 * @file
 * Defines `boost::mpl11::flip`.
 */

#ifndef BOOST_MPL11_FLIP_HPP
#define BOOST_MPL11_FLIP_HPP

#include <boost/mpl11/fwd/flip.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/nested_alias.hpp>


namespace boost { namespace mpl11 {
    template <typename F>
    struct flip {
        template <typename A0, typename A1, typename ...An>
        BOOST_MPL11_NESTED_ALIAS(apply, mpl11::apply<F, A1, A0, An...>);
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FLIP_HPP
