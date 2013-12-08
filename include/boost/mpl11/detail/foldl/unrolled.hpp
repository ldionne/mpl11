/*!
 * @file
 * Defines `boost::mpl11::detail::unrolled_foldl`.
 */

#ifndef BOOST_MPL11_DETAIL_FOLDL_UNROLLED_HPP
#define BOOST_MPL11_DETAIL_FOLDL_UNROLLED_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Implements a recursive left-fold algorithm with loop unrolling.
     */
    template <typename Sequence, typename State, typename F>
    struct unrolled_foldl;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/size.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace unrolled_foldl_detail {
    template <std_size_t N, typename First, typename State, typename F>
    struct impl
        : impl<
            N - 4,
            typename impl<4, First, State, F>::iterator,
            typename impl<4, First, State, F>::state,
            F
        >
    { };

    template <typename iter0, typename state0, typename F>
    struct impl<0, iter0, state0, F> {
        using iterator = iter0;
        using state = state0;
    };

    template <typename iter0, typename state0, typename F>
    struct impl<1, iter0, state0, F> {
        using state = apply_t<F, state0, deref_t<iter0>>;
        using iterator = next_t<iter0>;
    };

    template <typename iter0, typename state0, typename F>
    struct impl<2, iter0, state0, F> {
        using state1 = apply_t<F, state0, deref_t<iter0>>;
        using iter1 = next_t<iter0>;

        using state = apply_t<F, state1, deref_t<iter1>>;
        using iterator = next_t<iter1>;
    };

    template <typename iter0, typename state0, typename F>
    struct impl<3, iter0, state0, F> {
        using state1 = apply_t<F, state0, deref_t<iter0>>;
        using iter1 = next_t<iter0>;

        using state2 = apply_t<F, state1, deref_t<iter1>>;
        using iter2 = next_t<iter1>;

        using state = apply_t<F, state2, deref_t<iter2>>;
        using iterator = next_t<iter2>;
    };

    template <typename iter0, typename state0, typename F>
    struct impl<4, iter0, state0, F> {
        using state1 = apply_t<F, state0, deref_t<iter0>>;
        using iter1 = next_t<iter0>;

        using state2 = apply_t<F, state1, deref_t<iter1>>;
        using iter2 = next_t<iter1>;

        using state3 = apply_t<F, state2, deref_t<iter2>>;
        using iter3 = next_t<iter2>;

        using state = apply_t<F, state3, deref_t<iter3>>;
        using iterator = next_t<iter3>;
    };
} // end namespace unrolled_foldl_detail

template <typename Sequence, typename State, typename F>
struct unrolled_foldl {
    using type = typename unrolled_foldl_detail::impl<
        size<Sequence>::value, begin_t<Sequence>, State, F
    >::state;
};
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FOLDL_UNROLLED_HPP
