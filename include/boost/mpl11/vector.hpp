/*!
 * @file
 * Defines `boost::mpl11::vector`.
 */

#ifndef BOOST_MPL11_VECTOR_HPP
#define BOOST_MPL11_VECTOR_HPP

#include <boost/mpl11/fwd/vector.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/args.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/detail/vector_at.hpp>
#include <boost/mpl11/detail/vector_concat.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/integral_c.hpp> // for vector_c
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/random_access_iterator.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/random_extensible_container.hpp>
#include <boost/mpl11/unpack.hpp>


namespace boost { namespace mpl11 {
namespace vector_detail {
    using IndexT = unsigned long long;

    template <typename Vector, IndexT Pos>
    struct iterator;

    struct iterator_class final : RandomAccessIterator {
        /////////////////////////////////
        // ForwardIterator
        /////////////////////////////////
        template <typename Iterator>             struct next_impl;
        template <typename Iterator>             struct deref_impl;
        template <typename Self, typename Other> struct equal_impl;

        template <typename Vector, IndexT Pos>
        struct next_impl<iterator<Vector, Pos>> {
            using type = iterator<Vector, Pos + 1>;
        };

        template <typename Vector, IndexT Pos>
        struct deref_impl<iterator<Vector, Pos>>
            : at_c<Vector, Pos>
        { };

        template <typename Vector, IndexT Self, IndexT Other>
        struct equal_impl<iterator<Vector, Self>, iterator<Vector, Other>>
            : bool_<Self == Other>
        { };

        /////////////////////////////////
        // BidirectionalIterator
        /////////////////////////////////
        template <typename Iterator> struct prev_impl;

        template <typename Vector, IndexT Pos>
        struct prev_impl<iterator<Vector, Pos>> {
            using type = iterator<Vector, Pos - 1>;
        };

        /////////////////////////////////
        // RandomAccessIterator
        /////////////////////////////////
        template <typename Iterator, typename N> struct advance_impl;
        template <typename First, typename Last> struct distance_impl;
        template <typename Self, typename Other> struct less_impl;

        template <typename Vector, IndexT Pos, typename N>
        struct advance_impl<iterator<Vector, Pos>, N> {
            using type = iterator<Vector, Pos + N::value>;
        };

        template <typename Vector, IndexT First, IndexT Last>
        struct distance_impl<iterator<Vector, First>, iterator<Vector, Last>>
            : integral_c<decltype(Last - First), Last - First>
        { };

        template <typename Vector, IndexT Self, IndexT Other>
        struct less_impl<iterator<Vector, Self>, iterator<Vector, Other>>
            : bool_<(Self < Other)>
        { };
    };

    struct vector_class final
        : RandomAccessSequence, RandomExtensibleContainer
    {
        /////////////////////////////////
        // Sequence
        /////////////////////////////////
        template <typename Vector> struct begin_impl;
        template <typename Vector> struct end_impl;
        template <typename Vector> struct is_empty_impl;
        template <typename Vector> struct size_impl;

        template <typename Vector>
        struct begin_impl {
            using type = iterator<Vector, 0>;
        };

        template <typename ...T>
        struct end_impl<vector<T...>> {
            using type = iterator<vector<T...>, sizeof...(T)>;
        };

        template <typename ...T>
        struct is_empty_impl<vector<T...>>
            : bool_<sizeof...(T) == 0>
        { };

        template <typename ...T>
        struct size_impl<vector<T...>>
            : size_t<sizeof...(T)>
        { };

        /////////////////////////////////
        // RandomAccessSequence
        /////////////////////////////////
        template <typename Vector, typename N> struct at_impl;

        template <typename Vector, typename N>
        struct at_impl : detail::vector_at<Vector, N::value> {
            static_assert(N::value >= 0,
            "Accessing a `vector` at a negative index.");
        };

        /////////////////////////////////
        // Container
        /////////////////////////////////
        template <typename Vector> struct clear_impl;
        template <typename Vector> struct new_impl;

        template <typename Vector>
        struct clear_impl {
            using type = vector<>;
        };

        template <typename Vector>
        struct new_impl {
            template <typename ...T>
            struct apply {
                using type = vector<T...>;
            };
        };

        /////////////////////////////////
        // BackExtensibleContainer
        /////////////////////////////////
        template <typename Vector>             struct pop_back_impl;
        template <typename Vector, typename X> struct push_back_impl;

        template <typename ...T>
        struct pop_back_impl<vector<T...>>
            : apply<args<0, sizeof...(T) - 1>, T...>
        { };

        template <typename ...T, typename X>
        struct push_back_impl<vector<T...>, X> {
            using type = vector<T..., X>;
        };

        /////////////////////////////////
        // FrontExtensibleContainer
        /////////////////////////////////
        template <typename Vector>             struct pop_front_impl;
        template <typename Vector, typename X> struct push_front_impl;

        template <typename Head, typename ...Tail>
        struct pop_front_impl<vector<Head, Tail...>> {
            using type = vector<Tail...>;
        };

        template <typename ...T, typename X>
        struct push_front_impl<vector<T...>, X> {
            using type = vector<X, T...>;
        };

        /////////////////////////////////
        // RandomExtensibleContainer
        /////////////////////////////////
        template <typename Vector, typename Pos, typename Range>
        struct insert_range_impl;
        template <typename Vector, typename Pos, typename X>
        struct insert_impl;
        template <typename Vector, typename First, typename Last>
        struct erase_range_impl;
        template <typename Vector, typename Pos>
        struct erase_impl;

        template <typename ...T, IndexT Pos, typename Range>
        struct insert_range_impl<
            vector<T...>, iterator<vector<T...>, Pos>, Range
        >
            : detail::vector_concat<
                // [0, Pos)
                typename apply<args<0, Pos>, T...>::type,
                typename unpack<Range, into<vector>>::type,
                // [Pos, sizeof...(T))
                typename apply<args<Pos, sizeof...(T)>, T...>::type
            >
        { };

        template <typename Vector, typename Pos, typename X>
        struct insert_impl
            : insert_range_impl<Vector, Pos, vector<X>>
        { };

        template <typename ...T, IndexT First, IndexT Last>
        struct erase_range_impl<
            vector<T...>,
            iterator<vector<T...>, First>,
            iterator<vector<T...>, Last>
        >
            : detail::vector_concat<
                // [0, First)
                typename apply<args<0, First>, T...>::type,
                // [Last, sizeof...(T))
                typename apply<args<Last, sizeof...(T)>, T...>::type
            >
        { };

        template <typename V, IndexT Pos>
        struct erase_impl<V, iterator<V, Pos>>
            : erase_range_impl<V, iterator<V, Pos>, iterator<V, Pos + 1>>
        { };
    };
} // end namespace vector_detail

template <typename Vector, vector_detail::IndexT Position>
struct class_of<vector_detail::iterator<Vector, Position>> {
    using type = vector_detail::iterator_class;
};

template <typename ...T>
struct class_of<vector<T...>> {
    using type = vector_detail::vector_class;
};

// Optimization
template <typename ...T, typename F>
struct unpack<vector<T...>, F>
    : apply<F, T...>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VECTOR_HPP
