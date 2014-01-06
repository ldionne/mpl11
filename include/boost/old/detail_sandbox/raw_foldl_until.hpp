/*!
 * @file
 * Defines `boost::mpl11::detail::raw_foldl_until`.
 */

#ifndef BOOST_MPL11_DETAIL_RAW_FOLDL_UNTIL_HPP
#define BOOST_MPL11_DETAIL_RAW_FOLDL_UNTIL_HPP

#include <boost/mpl11/v2/fwd/is_empty.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Left-fold algorithm using a `Predicate` to stop early.
     *
     * At each step, `F` is invoked with the folded state and the part of the
     * sequence that remains to be folded if invoking `Predicate` with the
     * same arguments yields `false`. The fold is stopped when `Predicate`
     * returns `true` for the first time.
     *
     *
     * @todo
     * Optimize this with loop unrolling and whatnot.
     */
    template <
        typename Predicate, typename F, typename State, typename Sequence,
        bool = is_empty<Sequence>::value
    >
    struct raw_foldl_until;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/v2/is_empty.hpp>
#include <boost/mpl11/v2/tail.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename Pred, typename F, typename State, typename Sequence>
    struct raw_foldl_until<Pred, F, State, Sequence, true> {
        using state = State;
        using to_fold = Sequence;
    };

    namespace raw_foldl_until_detail {
        template <typename Pred, typename F, typename State, typename Sequence,
            bool = apply<Pred, State, Sequence>::type::value
        >
        struct cont;

        template <typename Pred, typename F, typename State, typename Sequence>
        struct cont<Pred, F, State, Sequence, true> {
            using state = State;
            using to_fold = Sequence;
        };

        template <typename Pred, typename F, typename State, typename Sequence>
        struct cont<Pred, F, State, Sequence, false>
            : raw_foldl_until<
                Pred,
                F,
                typename apply<F, State, Sequence>::type,
                typename tail<Sequence>::type
            >
        { };
    } // end namespace raw_foldl_until_detail

    template <typename Pred, typename F, typename State, typename Sequence>
    struct raw_foldl_until<Pred, F, State, Sequence, false>
        : raw_foldl_until_detail::cont<Pred, F, State, Sequence>
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_RAW_FOLDL_UNTIL_HPP
