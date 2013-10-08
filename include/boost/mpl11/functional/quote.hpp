/*!
 * @file
 * Defines `boost::mpl11::quote`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_QUOTE_HPP
#define BOOST_MPL11_FUNCTIONAL_QUOTE_HPP

#include <boost/mpl11/detail/either.hpp>
#include <boost/mpl11/functional/quote_fwd.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <template <typename ...> class F>
    struct quote {
        template <typename ...Args>
        struct apply
            : detail::either<
                F<Args...>,
                identity<F<Args...>>
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_QUOTE_HPP
