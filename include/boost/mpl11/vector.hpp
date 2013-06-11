/*!
 * @file
 * This file defines the `boost::mpl11::vector` container.
 */

#ifndef BOOST_MPL11_VECTOR_HPP
#define BOOST_MPL11_VECTOR_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/size_t.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace vector_detail { struct tag; }

template <typename ...T>
struct vector {
    struct mpl11 { using tag = vector_detail::tag; };

    template <std::size_t N>
    struct iterator {
        using next = iterator<N + 1>;
        using prior = iterator<N - 1>;
        using deref = take_at<N, T...>;
    };

    using size = size_t<sizeof...(T)>;
    using begin = iterator<0, vector>;
    using end = iterator<size::value, vector>;
    using empty = bool_<size::value == 0>;
    using clear = vector<>;
    template <typename U> using push_front = vector<U, T...>;
    template <typename U> using push_back = vector<T..., U>;
};

namespace extension {
    template <>
    struct begin_impl<vector_detail::tag> {
        template <typename Vector>
        struct apply {
            using type = typename Vector::begin;
        };
    };

    template <>
    struct end_impl<vector_detail::tag> {
        template <typename Vector>
        struct apply {
            using type = typename Vector::end;
        };
    };

    template <>
    struct size_impl<vector_detail::tag> {
        template <typename Vector>
        struct apply {
            using type = typename Vector::size;
        };
    };

    template <>
    struct empty_impl<vector_detail::tag> {
        template <typename Vector>
        struct apply {
            using type = typename Vector::empty;
        };
    };

    template <>
    struct front_impl<vector_detail::tag> {
        template <typename Vector>
        struct apply {
            using type = typename Vector::front;
        };
    };

    template <>
    struct back_impl<vector_detail::tag> {
        template <typename Vector>
        struct apply {
            using type = typename Vector::back;
        };
    };

    template <>
    struct at_impl<vector_detail::tag> {
        template <typename Vector, typename Position>
        struct apply {
            using type = typename Vector::template at<Position>;
        };
    };

    template <>
    struct insert_impl<vector_detail::tag> {
        template <typename Vector, typename Position, typename Element>
        struct apply {
            using type = typename Vector::template insert<Position, Element>;
        };
    };

    template <>
    struct insert_range_impl<vector_detail::tag> {
        template <typename Vector, typename Position, typename Range>
        struct apply {
            using type = typename Vector::template insert_range<Position, Range>;
        };
    };

    template <>
    struct erase_impl<vector_detail::tag> {
        template <typename Vector, typename Position>
        struct apply {
            using type = typename Vector::template erase<Position>;
        };
    };

    template <>
    struct erase_range_impl<vector_detail::tag> {
        template <typename Vector, typename Position, typename Last>
        struct apply {
            using type = typename Vector::template erase_range<Position, Last>;
        };
    };

    template <>
    struct clear_impl<vector_detail::tag> {
        template <typename Vector>
        struct apply {
            using type = typename Vector::clear;
        };
    };

    template <>
    struct push_back_impl<vector_detail::tag> {
        template <typename Vector, typename Element>
        struct apply {
            using type = typename Vector::template push_back<Element>;
        };
    };

    template <>
    struct pop_back_impl<vector_detail::tag> {
        template <typename Vector>
        struct apply {
            using type = typename Vector::pop_back;
        };
    };

    template <>
    struct push_front_impl<vector_detail::tag> {
        template <typename Vector, typename Element>
        struct apply {
            using type = typename Vector::template push_front<Element>;
        };
    };

    template <>
    struct pop_front_impl<vector_detail::tag> {
        template <typename Vector>
        struct apply {
            using type = typename Vector::pop_front;
        };
    };
}
}}}

#endif // !BOOST_MPL11_VECTOR_HPP
