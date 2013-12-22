/*!
 * @file
 * Defines `boost::mpl11::detail::foldl_n`.
 */

#ifndef BOOST_MPL11_DETAIL_FOLDL_N_HPP
#define BOOST_MPL11_DETAIL_FOLDL_N_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Left-fold algorithm stopping after a given number of steps.
     *
     * At each step, `F` is invoked with the folded state and the part
     * of the sequence that remains to be folded.
     */
    template <std_size_t N, typename Sequence, typename State, typename F>
    struct foldl_n;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/tail.hpp>


namespace boost { namespace mpl11 { namespace detail {
template <std_size_t N, typename seq0, typename state0, typename F>
struct foldl_n {
private:
    template <std_size_t, typename, typename, typename> friend struct foldl_n;

    using state1   = typename foldl_n<N/2, seq0, state0, F>::state;
    using seq1     = typename foldl_n<N/2, seq0, state0, F>::sequence;

    using state    = typename foldl_n<N - N/2, seq1, state1, F>::state;
    using sequence = typename foldl_n<N - N/2, seq1, state1, F>::sequence;

public:
    using type = state;
};

template <typename Sequence, typename State, typename F>
struct foldl_n<0, Sequence, State, F> {
private:
    template <std_size_t, typename, typename, typename> friend struct foldl_n;

    using state = State;
    using sequence = Sequence;

public:
    using type = state;
};

template <typename Sequence, typename State, typename F>
struct foldl_n<1, Sequence, State, F> {
private:
    template <std_size_t, typename, typename, typename> friend struct foldl_n;

    using state = typename apply<F, State, Sequence>::type;
    using sequence = typename tail<Sequence>::type;

public:
    using type = state;
};
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FOLDL_N_HPP
