/*!
 * @file
 * Defines `boost::mpl11::partial`.
 */

#ifndef BOOST_MPL11_PARTIAL_HPP
#define BOOST_MPL11_PARTIAL_HPP

#include <boost/mpl11/fwd/partial.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/nested_alias.hpp>
#include <boost/mpl11/fwd/into.hpp>
#include <boost/mpl11/fwd/quote.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename ...X>
    struct partial {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply, mpl11::apply<F, X..., Args...>);
    };

    template <template <typename ...> class F, typename ...T>
    struct partial<quote<F>, T...> {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply, F<T..., Args...>);
    };

    template <template <typename ...> class F, typename ...T>
    struct partial<into<F>, T...> {
        template <typename ...Args>
        struct apply {
            using type = F<T..., Args...>;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PARTIAL_HPP
