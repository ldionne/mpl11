/*!
 * @file
 * Defines `boost::mpl11::replicate` and `boost::mpl11::replicate_c`.
 */

#ifndef BOOST_MPL11_REPLICATE_HPP
#define BOOST_MPL11_REPLICATE_HPP

#include <boost/mpl11/fwd/replicate.hpp>

#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/integral_c.hpp> // required by fwd/replicate.hpp
#include <boost/mpl11/join.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
namespace replicate_detail {
    template <unsigned long long N, typename T>
    struct replicate_iterator;

    struct replicate_iterator_class final : ForwardIterator {
        template <typename Iterator>             struct next_impl;
        template <typename Iterator>             struct deref_impl;
        template <typename Self, typename Other> struct equal_impl;

        template <typename T> struct next_impl<replicate_iterator<0, T>>;
        template <typename T> struct deref_impl<replicate_iterator<0, T>>;

        template <unsigned long long N, typename T>
        struct next_impl<replicate_iterator<N, T>> {
            using type = replicate_iterator<N-1, T>;
        };

        template <unsigned long long N, typename T>
        struct deref_impl<replicate_iterator<N, T>> {
            using type = T;
        };

        template <unsigned long long I, unsigned long long J, typename T>
        struct equal_impl<replicate_iterator<I, T>, replicate_iterator<J, T>>
            : bool_<I == J>
        { };
    };

    struct replicate_class final : Sequence {
        template <typename Replicate> struct begin_impl;
        template <typename Replicate> struct end_impl;

        template <typename N, typename T>
        struct begin_impl<replicate<N, T>> {
            static_assert(N::value >= 0,
            "Invalid usage of replicate: N::value must be non-negative.");

            using type = replicate_iterator<N::value, T>;
        };

        template <typename N, typename T>
        struct end_impl<replicate<N, T>> {
            static_assert(N::value >= 0,
            "Invalid usage of replicate: N::value must be non-negative.");

            using type = replicate_iterator<0, T>;
        };
    };

    template <unsigned long long N, typename T>
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

template <unsigned long long N, typename T, typename Default>
struct class_of<replicate_detail::replicate_iterator<N, T>, Default> {
    using type = replicate_detail::replicate_iterator_class;
};

template <typename N, typename T, typename Default>
struct class_of<replicate<N, T>, Default> {
    using type = replicate_detail::replicate_class;
};

template <typename N, typename T>
struct replicate {
    static_assert(N::value >= 0,
    "Invalid usage of replicate: N::value must be non-negative.");

    using type = typename replicate_detail::replicate_impl<N::value, T>::type;
};

template <typename N, typename T, typename F>
struct unpack<replicate<N, T>, F>
    : unpack<replicate_t<N, T>, F>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_REPLICATE_HPP
