/*!
 * @file
 * Defines `boost::mpl11::compose`.
 */

#ifndef BOOST_MPL11_COMPOSE_HPP
#define BOOST_MPL11_COMPOSE_HPP

#include <boost/mpl11/fwd/compose.hpp>

#include <boost/mpl11/apply.hpp>


namespace boost { namespace mpl11 {
    template <typename F1, typename ...Fn>
    struct compose {
        using type = compose;

        template <typename ...Args>
        using apply = mpl11::apply<F1,
            typename compose<Fn...>::template apply<Args...>
        >;
    };

    template <typename F>
    struct compose<F> {
        using type = compose;

        template <typename ...Args>
        using apply = mpl11::apply<F, Args...>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPOSE_HPP
