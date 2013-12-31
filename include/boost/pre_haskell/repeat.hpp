/*!
 * @file
 * Defines `boost::mpl11::repeat` and `boost::mpl11::repeat_c`.
 */

#ifndef BOOST_MPL11_REPEAT_HPP
#define BOOST_MPL11_REPEAT_HPP

#include <boost/mpl11/fwd/repeat.hpp>

#include <boost/mpl11/detail/repeat_iterator.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/has_optimization.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/length.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/integral_c.hpp> // required by fwd/repeat.hpp
#include <boost/mpl11/join.hpp>
#include <boost/mpl11/optimization.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
namespace repeat_detail {
    template <typename N>
    struct assert_usage {
        static_assert(N::value >= 0,
        "Invalid usage of `repeat`: `N::value` must be non-negative.");
    };

    template <typename T, detail::std_size_t N>
    struct repeat_impl
        : join<
            typename repeat_impl<T, N/2>::type,
            typename repeat_impl<T, N - N/2>::type
        >
    { };

    template <typename T>
    struct repeat_impl<T, 0> { using type = vector<>; };

    template <typename T>
    struct repeat_impl<T, 1> { using type = vector<T>; };
} // end namespace repeat_detail

template <typename T, typename N>
struct repeat
    : repeat_detail::assert_usage<N>,
      repeat_detail::repeat_impl<T, N::value>
{ };

/////////////////////////////////
// Sequence
/////////////////////////////////
template <typename T, typename N>
struct begin<repeat<T, N>> : repeat_detail::assert_usage<N> {
    using type = detail::repeat_iterator<T, N::value>;
};

template <typename T, typename N>
struct end<repeat<T, N>> : repeat_detail::assert_usage<N> {
    using type = detail::repeat_iterator<T, 0>;
};

template <typename T, typename N>
struct is_empty<repeat<T, N>>
    : repeat_detail::assert_usage<N>,
      bool_<N::value == 0>
{ };

template <typename T, typename N>
struct length<repeat<T, N>>
    : repeat_detail::assert_usage<N>,
      N
{ };

/////////////////////////////////
// Other specializations
/////////////////////////////////
template <typename T, typename N, typename F>
struct unpack<repeat<T, N>, F>
    : unpack<typename repeat<T, N>::type, F>
{ };

template <typename T, typename N>
struct has_optimization<repeat<T, N>, optimization::O1_length>
    : true_
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_REPEAT_HPP
