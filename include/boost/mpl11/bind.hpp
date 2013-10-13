/*!
 * @file
 * Defines `boost::mpl11::bind`.
 */

#ifndef BOOST_MPL11_BIND_HPP
#define BOOST_MPL11_BIND_HPP

#include <boost/mpl11/fwd/bind.hpp>

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/is_placeholder.hpp>


namespace boost { namespace mpl11 {
    namespace bind_detail {
        template <typename X, typename ...Args>
        using substitute = typename if_<is_placeholder<X>,
            apply_wrap<X, Args...>,
            identity<X>
        >::type::type;
    } // end namespace bind_detail

    template <typename F, typename ...An>
    struct bind {
        template <typename ...Args>
        struct apply
            : apply_wrap<
                bind_detail::substitute<F, Args...>,
                bind_detail::substitute<An, Args...>...
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIND_HPP
