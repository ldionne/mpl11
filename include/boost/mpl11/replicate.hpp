/*!
 * @file
 * Defines `boost::mpl11::replicate` and `boost::mpl11::replicate_c`.
 */

#ifndef BOOST_MPL11_REPLICATE_HPP
#define BOOST_MPL11_REPLICATE_HPP

#include <boost/mpl11/fwd/replicate.hpp>

#include <boost/mpl11/detail/dependent_on.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/advance.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/distance.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/equal.hpp>
#include <boost/mpl11/fwd/has_optimization.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/not_equal.hpp>
#include <boost/mpl11/fwd/size.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/integral_c.hpp> // required by fwd/replicate.hpp
#include <boost/mpl11/join.hpp>
#include <boost/mpl11/optimization.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Replicate iterator
//////////////////////////////////////////////////////////////////////////////
namespace replicate_detail {
    template <detail::std_size_t N, typename T>
    struct iterator;
}

/////////////////////////////////
// ForwardIterator
/////////////////////////////////
template <typename T>
struct next<replicate_detail::iterator<0, T>> {
    struct type;

    static_assert(detail::dependent_on<type>::template value<bool, false>(),
    "Invalid usage of `next`: "
    "Incrementing a past-the-end iterator of `replicate`.");
};

template <detail::std_size_t N, typename T>
struct next<replicate_detail::iterator<N, T>> {
    using type = replicate_detail::iterator<N-1, T>;
};

template <typename T>
struct deref<replicate_detail::iterator<0, T>> {
    struct type;

    static_assert(detail::dependent_on<type>::template value<bool, false>(),
    "Invalid usage of `next`: "
    "Dereferencing a past-the-end iterator of `replicate`.");
};

template <detail::std_size_t N, typename T>
struct deref<replicate_detail::iterator<N, T>> {
    using type = T;
};

template <detail::std_size_t I, detail::std_size_t J, typename T>
struct equal<
    replicate_detail::iterator<I, T>,
    replicate_detail::iterator<J, T>
>
    : bool_<I == J>
{ };

template <detail::std_size_t I, detail::std_size_t J, typename T>
struct not_equal<
    replicate_detail::iterator<I, T>,
    replicate_detail::iterator<J, T>
>
    : bool_<I != J>
{ };

template <detail::std_size_t N, typename T, typename Dist>
struct advance<replicate_detail::iterator<N, T>, Dist> {
    static_assert(Dist::value <= N,
    "Invalid usage of `advance`: "
    "Advancing a `replicate` iterator beyond its end.");

    using type = replicate_detail::iterator<N - Dist::value, T>;
};

template <detail::std_size_t I, detail::std_size_t J, typename T>
struct distance<
    replicate_detail::iterator<I, T>,
    replicate_detail::iterator<J, T>
>
    : integral_c<decltype(I - J), I - J>
{ };


//////////////////////////////////////////////////////////////////////////////
// Replicate
//////////////////////////////////////////////////////////////////////////////
namespace replicate_detail {
    template <typename N>
    struct assert_usage {
        static_assert(N::value >= 0,
        "Invalid usage of `replicate`: `N::value` must be non-negative.");
    };

    template <detail::std_size_t N, typename T>
    struct replicate_impl
        : join<
            typename replicate_impl<N/2, T>::type,
            typename replicate_impl<N - N/2, T>::type
        >
    { };

    template <typename T>
    struct replicate_impl<0, T> { using type = vector<>; };

    template <typename T>
    struct replicate_impl<1, T> { using type = vector<T>; };
} // end namespace replicate_detail

template <typename N, typename T>
struct replicate
    : replicate_detail::assert_usage<N>,
      replicate_detail::replicate_impl<N::value, T>
{ };

/////////////////////////////////
// Sequence
/////////////////////////////////
template <typename N, typename T>
struct begin<replicate<N, T>> : replicate_detail::assert_usage<N> {
    using type = replicate_detail::iterator<N::value, T>;
};

template <typename N, typename T>
struct end<replicate<N, T>> : replicate_detail::assert_usage<N> {
    using type = replicate_detail::iterator<0, T>;
};

template <typename N, typename T>
struct is_empty<replicate<N, T>>
    : replicate_detail::assert_usage<N>,
      bool_<N::value == 0>
{ };

template <typename N, typename T>
struct size<replicate<N, T>>
    : replicate_detail::assert_usage<N>,
      N
{ };

/////////////////////////////////
// Other specializations
/////////////////////////////////
template <typename N, typename T, typename F>
struct unpack<replicate<N, T>, F>
    : unpack<typename replicate<N, T>::type, F>
{ };

template <typename N, typename T>
struct has_optimization<replicate<N, T>, optimization::O1_size>
    : true_
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_REPLICATE_HPP
