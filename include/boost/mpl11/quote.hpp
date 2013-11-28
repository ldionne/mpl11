/*!
 * @file
 * Defines `boost::mpl11::quote`.
 */

#ifndef BOOST_MPL11_QUOTE_HPP
#define BOOST_MPL11_QUOTE_HPP

#include <boost/mpl11/fwd/quote.hpp>

#include <boost/mpl11/detail/nested_alias.hpp>


namespace boost { namespace mpl11 {
    template <template <typename ...> class F>
    struct quote {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply, F<Args...>);
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_QUOTE_HPP
