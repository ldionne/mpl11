/*!
 * @file
 * Defines `boost::mpl11::foldl`.
 */

#ifndef BOOST_MPL11_FOLDL_HPP
#define BOOST_MPL11_FOLDL_HPP

#include <boost/mpl11/fwd/foldl.hpp>

#include <boost/mpl11/detail/foldl/normal.hpp>
#include <boost/mpl11/detail/foldl/unpacked.hpp>
#include <boost/mpl11/detail/foldl/unrolled.hpp>
#include <boost/mpl11/has_optimization.hpp>
#include <boost/mpl11/optimization.hpp>


namespace boost { namespace mpl11 {
namespace foldl_detail {
    template <
        typename Sequence, typename State, typename F,
        bool = has_optimization<Sequence, optimization::O1_unpack>::value,
        bool = has_optimization<Sequence, optimization::O1_size>::value>
    struct foldl_dispatch;

    template <typename Sequence, typename State, typename F, bool Any>
    struct foldl_dispatch<Sequence, State, F, true, Any>
        : detail::unpacked_foldl<Sequence, State, F>
    { };

    template <typename Sequence, typename State, typename F>
    struct foldl_dispatch<Sequence, State, F, false, true>
        : detail::unrolled_foldl<Sequence, State, F>
    { };

    template <typename Sequence, typename State, typename F>
    struct foldl_dispatch<Sequence, State, F, false, false>
        : detail::normal_foldl<Sequence, State, F>
    { };
} // end namespace foldl_detail

template <typename Sequence, typename State, typename F>
struct foldl
    : foldl_detail::foldl_dispatch<Sequence, State, F>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDL_HPP
