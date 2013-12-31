/*!
 * @file
 * Defines `boost::mpl11::foldl`.
 */

#ifndef BOOST_MPL11_FOLDL_HPP
#define BOOST_MPL11_FOLDL_HPP

#include <boost/mpl11/fwd/foldl.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/foldl_n.hpp>
#include <boost/mpl11/detail/foldl_until.hpp>
#include <boost/mpl11/detail/foldl_variadic.hpp>
#include <boost/mpl11/has_optimization.hpp>
#include <boost/mpl11/head.hpp>
#include <boost/mpl11/is_empty.hpp>
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
    struct apply_head {
        template <typename State, typename ToFold>
        using apply = mpl11::apply<F, State, typename head<ToFold>::type>;
    };

    template <typename Sequence, typename State, typename F>
    struct foldl_dispatch<Sequence, State, F, false, true>
        : detail::foldl_n<
            length<Sequence>::value,
            Sequence,
            State,
            apply_head<F>
        >
    { };

    template <typename Sequence, typename State, typename F>
    struct foldl_dispatch<Sequence, State, F, false, false>
        : detail::foldl_until<
            quote<is_empty>,
            Sequence,
            State,
            apply_head<F>
        >
    { };
} // end namespace foldl_detail

template <typename Sequence, typename State, typename F>
struct foldl
    : foldl_detail::foldl_dispatch<Sequence, State, F>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDL_HPP
