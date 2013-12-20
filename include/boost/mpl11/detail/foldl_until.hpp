/*!
 * @file
 * Defines `boost::mpl11::detail::foldl_until`.
 */

#ifndef BOOST_MPL11_DETAIL_FOLDL_UNTIL_HPP
#define BOOST_MPL11_DETAIL_FOLDL_UNTIL_HPP

#include <boost/mpl11/fwd/apply.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Left-fold algorithm using a `Predicate` to decide when to stop.
     *
     * `F` is invoked with the state and the iterator at each step, while
     * `Predicate` is invoked with the iterator at each step. _They are not
     * invoked with the result of dereferencing the iterator, but with the
     * iterator itself._
     */
    template <
        typename Predicate, typename Iter, typename State, typename F,
        bool = apply<Predicate, Iter>::type::value
    >
    struct foldl_until;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace fu_detail {
    template <
        typename Predicate, typename Iter, typename State, typename F,
        bool = apply<Predicate, Iter>::type::value
    >
    struct step;

    template <typename Predicate, typename Iter, typename State, typename F>
    struct step<Predicate, Iter, State, F, true> {
        using state = State;
        using iterator = Iter;
    };

    template <typename Predicate, typename Iter, typename State, typename F>
    struct step<Predicate, Iter, State, F, false> {
        using state = typename apply<F, State, Iter>::type;
        using iterator = typename next<Iter>::type;
    };
} // end namespace fu_detail

template <typename Predicate, typename Iter, typename State, typename F>
struct foldl_until<Predicate, Iter, State, F, true> {
    using type = State;
};

template <typename Pred, typename iter0, typename state0, typename F>
struct foldl_until<Pred, iter0, state0, F, false> {
private:
    using state1 = typename apply<F, state0, iter0>::type;
    using iter1  = typename next<iter0>::type;

    using state2 = typename fu_detail::step<Pred, iter1, state1, F>::state;
    using iter2  = typename fu_detail::step<Pred, iter1, state1, F>::iterator;

    using state3 = typename fu_detail::step<Pred, iter2, state2, F>::state;
    using iter3  = typename fu_detail::step<Pred, iter2, state2, F>::iterator;

    using state4 = typename fu_detail::step<Pred, iter3, state3, F>::state;
    using iter4  = typename fu_detail::step<Pred, iter3, state3, F>::iterator;

public:
    using type = typename foldl_until<Pred, iter4, state4, F>::type;
};
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FOLDL_UNTIL_HPP
