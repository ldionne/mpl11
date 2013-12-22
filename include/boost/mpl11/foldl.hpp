/*!
 * @file
 * Defines `boost::mpl11::foldl`.
 */

#ifndef BOOST_MPL11_FOLDL_HPP
#define BOOST_MPL11_FOLDL_HPP

#include <boost/mpl11/fwd/foldl.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/foldl_n.hpp>
#include <boost/mpl11/detail/foldl_until.hpp>
#include <boost/mpl11/detail/foldl_variadic.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/flip.hpp>
#include <boost/mpl11/has_optimization.hpp>
#include <boost/mpl11/length.hpp>
#include <boost/mpl11/optimization.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/unpack.hpp>


namespace boost { namespace mpl11 {
namespace foldl_detail {
    template <
        typename Sequence, typename State, typename F,
        bool = has_optimization<Sequence, optimization::O1_unpack>::value,
        bool = has_optimization<Sequence, optimization::O1_length>::value>
    struct foldl_dispatch;

    template <typename Sequence, typename State, typename F, bool Any>
    struct foldl_dispatch<Sequence, State, F, true, Any>
        : unpack<
            Sequence,
            partial<quote<detail::foldl_variadic>, State, F>
        >
    { };

    template <typename F>
    struct deref_iter {
        template <typename State, typename Iter>
        using apply = mpl11::apply<F, State, typename deref<Iter>::type>;
    };

    template <typename Sequence, typename State, typename F>
    struct foldl_dispatch<Sequence, State, F, false, true>
        : detail::foldl_n<
            length<Sequence>::value,
            typename begin<Sequence>::type,
            State,
            deref_iter<F>
        >
    { };

    //! @todo
    //! Remove usage of flip<> below when join_iterator is fixed.
    template <typename Sequence, typename State, typename F>
    struct foldl_dispatch<Sequence, State, F, false, false>
        : detail::foldl_until<
            partial<flip<quote<equal>>, typename end<Sequence>::type>,
            typename begin<Sequence>::type,
            State,
            deref_iter<F>
        >
    { };
} // end namespace foldl_detail

template <typename Sequence, typename State, typename F>
struct foldl
    : foldl_detail::foldl_dispatch<Sequence, State, F>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDL_HPP
