/*!
 * @file
 * Defines `boost::mpl11::take` and `boost::mpl11::take_c`.
 */

#ifndef BOOST_MPL11_TAKE_HPP
#define BOOST_MPL11_TAKE_HPP

#include <boost/mpl11/fwd/take.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/integral_c.hpp> // required for fwd/take.hpp
#include <boost/mpl11/length.hpp>
#include <boost/mpl11/new.hpp>


namespace boost { namespace mpl11 {
namespace take_detail {
    template <typename N>
    struct assert_usage {
        static_assert(N::value >= 0,
        "Invalid usage of `take`: `N::value` must be non-negative.");
    };

    template <
        detail::std_size_t N, typename Sequence,
        bool = (N >= length<Sequence>::value)
    >
    struct end_impl;

    template <detail::std_size_t N, typename Sequence>
    struct end_impl<N, Sequence, true>
        : end<Sequence>
    { };

    template <detail::std_size_t N, typename Sequence>
    struct end_impl<N, Sequence, false>
        : advance_c<typename begin<Sequence>::type, N>
    { };
} // end namespace take_detail

template <typename N, typename Sequence>
struct take
    : apply<new_<Sequence>, take<N, Sequence>>
{ };

/////////////////////////////////
// Sequence
/////////////////////////////////
template <typename N, typename Sequence>
struct begin<take<N, Sequence>>
    : take_detail::assert_usage<N>,
      begin<Sequence>
{ };

template <typename N, typename Sequence>
struct end<take<N, Sequence>>
    : take_detail::assert_usage<N>,
      take_detail::end_impl<N::value, Sequence>
{ };

template <typename N, typename Sequence>
struct length<take<N, Sequence>>
    : take_detail::assert_usage<N>,
      integral_c<detail::std_size_t,
        (   // min(N, length<Sequence>)
            N::value < length<Sequence>::value
                ? N::value
                : length<Sequence>::value
        )
      >
{ };

template <typename N, typename Sequence>
struct is_empty<take<N, Sequence>>
    : take_detail::assert_usage<N>,
      bool_<N::value == 0 || is_empty<Sequence>::value>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TAKE_HPP
