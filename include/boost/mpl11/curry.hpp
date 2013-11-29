/*!
 * @file
 * Defines `boost::mpl11::curry`.
 */

#ifndef BOOST_MPL11_CURRY_HPP
#define BOOST_MPL11_CURRY_HPP

#include <boost/mpl11/fwd/curry.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/nested_alias.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename ...X>
    struct curry {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply, mpl11::apply<F, X..., Args...>);
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CURRY_HPP
