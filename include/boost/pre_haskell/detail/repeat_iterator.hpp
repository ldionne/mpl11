/*!
 * @file
 * Defines `boost::mpl11::detail::repeat_iterator`.
 */

#ifndef BOOST_MPL11_DETAIL_REPEAT_ITERATOR_HPP
#define BOOST_MPL11_DETAIL_REPEAT_ITERATOR_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * `ForwardIterator` repeating the given type `N` times.
     *
     * The past-the-end iterator is `repeat_iterator<T, 0>`.
     */
    template <typename T, std_size_t N>
    struct repeat_iterator;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/detail/dependent_on.hpp>
#include <boost/mpl11/fwd/advance.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/distance.hpp>
#include <boost/mpl11/fwd/equal.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/not_equal.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct next<detail::repeat_iterator<T, 0>> {
        static_assert(detail::dependent_on<T>::value(false),
        "Invalid usage of `next`: "
        "Incrementing a past-the-end `repeat_iterator`.");

        struct type;
    };

    template <typename T, detail::std_size_t N>
    struct next<detail::repeat_iterator<T, N>> {
        using type = detail::repeat_iterator<T, N - 1>;
    };

    template <typename T>
    struct deref<detail::repeat_iterator<T, 0>> {
        static_assert(detail::dependent_on<T>::value(false),
        "Invalid usage of `next`: "
        "Dereferencing a past-the-end `repeat_iterator`.");

        struct type;
    };

    template <typename T, detail::std_size_t N>
    struct deref<detail::repeat_iterator<T, N>> {
        using type = T;
    };

    template <typename T, detail::std_size_t I, detail::std_size_t J>
    struct equal<
        detail::repeat_iterator<T, I>,
        detail::repeat_iterator<T, J>
    >
        : bool_<I == J>
    { };

    template <typename T, detail::std_size_t I, detail::std_size_t J>
    struct not_equal<
        detail::repeat_iterator<T, I>,
        detail::repeat_iterator<T, J>
    >
        : bool_<I != J>
    { };

    template <typename T, detail::std_size_t N, typename Distance>
    struct advance<detail::repeat_iterator<T, N>, Distance> {
        static_assert(Distance::value <= N,
        "Invalid usage of `advance`: "
        "Advancing a `repeat_iterator` out of its bounds.");

        using type = detail::repeat_iterator<T, N - Distance::value>;
    };

    template <typename T, detail::std_size_t I, detail::std_size_t J>
    struct distance<
        detail::repeat_iterator<T, I>,
        detail::repeat_iterator<T, J>
    >
        : integral_c<decltype(I - J), I - J>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_REPEAT_ITERATOR_HPP
