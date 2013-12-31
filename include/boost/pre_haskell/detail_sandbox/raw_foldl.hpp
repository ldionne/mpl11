/*!
 * @file
 * Defines `boost::mpl11::detail::raw_foldl`.
 */

#ifndef BOOST_MPL11_DETAIL_RAW_FOLDL_HPP
#define BOOST_MPL11_DETAIL_RAW_FOLDL_HPP

#include <boost/mpl11/v2/fwd/is_empty.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Left-fold algorithm.
     *
     * At each step, `F` is invoked with the folded state and the part of the
     * sequence that remains to be folded.
     *
     *
     * @todo
     * Optimize this with loop unrolling and whatnot.
     */
    template <typename F, typename State, typename Sequence,
        bool = is_empty<Sequence>::value
    >
    struct raw_foldl;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/v2/is_empty.hpp>
#include <boost/mpl11/v2/tail.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename F, typename State, typename Sequence>
    struct raw_foldl<F, State, Sequence, true> {
        using state = State;
        using to_fold = Sequence;
    };

    template <typename F, typename State, typename Sequence>
    struct raw_foldl<F, State, Sequence, false>
        : raw_foldl<
            F,
            typename apply<F, State, Sequence>::type,
            typename tail<Sequence>::type
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_RAW_FOLDL_HPP
