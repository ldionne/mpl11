/*!
 * @file
 * Defines `boost::mpl11::compose`.
 */

#ifndef BOOST_MPL11_COMPOSE_HPP
#define BOOST_MPL11_COMPOSE_HPP

#include <boost/mpl11/fwd/compose.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/nested_alias.hpp>


namespace boost { namespace mpl11 {
    // This fancy implementation is to use compose<>'s nested apply directly
    // when we know we're not inheritting F1. This saves us some apply<>
    // instantiations.
    template <typename F1, typename F2, typename ...Fn>
    struct compose<F1, F2, Fn...> {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply,
            mpl11::apply<F1,
                typename compose<F2, Fn...>::template apply<Args...>::type
            >
        );
    };

    template <typename F1, typename F2>
    struct compose<F1, F2> {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply,
            mpl11::apply<F1, apply_t<F2, Args...>>);
    };

    template <typename F1>
    struct compose<F1>
        : F1
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPOSE_HPP
