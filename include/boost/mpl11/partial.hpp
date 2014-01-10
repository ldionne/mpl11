/*!
 * @file
 * Defines `boost::mpl11::partial`.
 */

#ifndef BOOST_MPL11_PARTIAL_HPP
#define BOOST_MPL11_PARTIAL_HPP

#include <boost/mpl11/fwd/partial.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/into.hpp>
#include <boost/mpl11/fwd/quote.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename ...X>
    struct partial {
        using type = partial;

        template <typename ...Args>
        using apply = mpl11::apply<F, X..., Args...>;
    };

    template <template <typename ...> class F, typename ...X>
    struct partial<quote<F>, X...> {
        using type = partial;

        template <typename ...Args>
        using apply = F<X..., Args...>;
    };

    template <template <typename ...> class F, typename ...X>
    struct partial<into<F>, X...> {
        using type = partial;

        template <typename ...Args>
        struct apply {
            using type = F<X..., Args...>;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PARTIAL_HPP
