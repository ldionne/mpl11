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
     * At each step, `F` is invoked with the folded state and the part of the
     * sequence that remains to be folded, while `Predicate` is only invoked
     * with the part of the sequence that remains to be folded.
     */
    template <
        typename Predicate, typename Sequence, typename State, typename F,
        bool = apply<Predicate, Sequence>::type::value
    >
    struct foldl_until;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/tail.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace fu_detail {
    template <
        typename Predicate, typename Seq, typename State, typename F,
        bool = apply<Predicate, Seq>::type::value
    >
    struct step;

    template <typename Predicate, typename Seq, typename State, typename F>
    struct step<Predicate, Seq, State, F, true> {
        using state = State;
        using sequence = Seq;
    };

    template <typename Predicate, typename Seq, typename State, typename F>
    struct step<Predicate, Seq, State, F, false> {
        using state = typename apply<F, State, Seq>::type;
        using sequence = typename tail<Seq>::type;
    };
} // end namespace fu_detail

template <typename Predicate, typename Seq, typename State, typename F>
struct foldl_until<Predicate, Seq, State, F, true> {
    using type = State;
};

template <typename Pred, typename seq0, typename state0, typename F>
struct foldl_until<Pred, seq0, state0, F, false> {
private:
    using state1 = typename apply<F, state0, seq0>::type;
    using seq1   = typename tail<seq0>::type;

    using state2 = typename fu_detail::step<Pred, seq1, state1, F>::state;
    using seq2   = typename fu_detail::step<Pred, seq1, state1, F>::sequence;

    using state3 = typename fu_detail::step<Pred, seq2, state2, F>::state;
    using seq3   = typename fu_detail::step<Pred, seq2, state2, F>::sequence;

    using state4 = typename fu_detail::step<Pred, seq3, state3, F>::state;
    using seq4   = typename fu_detail::step<Pred, seq3, state3, F>::sequence;

public:
    using type = typename foldl_until<Pred, seq4, state4, F>::type;
};
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FOLDL_UNTIL_HPP
