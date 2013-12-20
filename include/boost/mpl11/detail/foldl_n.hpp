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
     * _`F` is invoked with the state and the iterator itself at each step,
     * not with the result of dereferencing the iterator._
     */
    template <std_size_t N, typename Iter, typename State, typename F>
    struct foldl_n;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 { namespace detail {
template <std_size_t N, typename iter0, typename state0, typename F>
struct foldl_n {
private:
    template <std_size_t, typename, typename, typename> friend struct foldl_n;

    using state1   = typename foldl_n<N/2, iter0, state0, F>::state;
    using iter1    = typename foldl_n<N/2, iter0, state0, F>::iterator;

    using state    = typename foldl_n<N - N/2, iter1, state1, F>::state;
    using iterator = typename foldl_n<N - N/2, iter1, state1, F>::iterator;

public:
    using type = state;
};

template <typename Iter, typename State, typename F>
struct foldl_n<0, Iter, State, F> {
private:
    template <std_size_t, typename, typename, typename> friend struct foldl_n;

    using state = State;
    using iterator = Iter;

public:
    using type = state;
};

template <typename Iter, typename State, typename F>
struct foldl_n<1, Iter, State, F> {
private:
    template <std_size_t, typename, typename, typename> friend struct foldl_n;

    using state = typename apply<F, State, Iter>::type;
    using iterator = typename next<Iter>::type;

public:
    using type = state;
};
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FOLDL_N_HPP
