/*!
 * @file
 * Defines `boost::mpl11::vector`.
 */

#ifndef BOOST_MPL11_VECTOR_HPP
#define BOOST_MPL11_VECTOR_HPP

#include <boost/mpl11/fwd/vector.hpp>

#include <boost/mpl11/at.hpp>
#include <boost/mpl11/detail/copy_into_variadic_pack.hpp>
#include <boost/mpl11/detail/variadic/at.hpp>
#include <boost/mpl11/detail/variadic/concat.hpp>
#include <boost/mpl11/detail/variadic/drop.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>
#include <boost/mpl11/detail/variadic/rebind.hpp>
#include <boost/mpl11/detail/variadic/take.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/integral_c.hpp> // for vector_c
#include <boost/mpl11/random_access_iterator.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/random_extensible_container.hpp>


namespace boost { namespace mpl11 {
namespace vector_detail {
    using Index = unsigned long long;

    template <typename Vector, Index Pos>
    struct iterator;

    struct iterator_class final : RandomAccessIterator {
        /////////////////////////////////
        // ForwardIterator
        /////////////////////////////////
        template <typename Iterator> struct next_impl;
        template <typename Vector, Index Pos>
        struct next_impl<iterator<Vector, Pos>> {
            using type = iterator<Vector, Pos + 1>;
        };

        template <typename Iterator> struct deref_impl;
        template <typename Vector, Index Pos>
        struct deref_impl<iterator<Vector, Pos>>
            : at_c<Vector, Pos>
        { };

        template <typename Self, typename Other> struct equal_impl;
        template <typename Vector, Index Self, Index Other>
        struct equal_impl<iterator<Vector, Self>, iterator<Vector, Other>>
            : bool_<Self == Other>
        { };

        /////////////////////////////////
        // BidirectionalIterator
        /////////////////////////////////
        template <typename Iterator> struct prev_impl;
        template <typename Vector, Index Pos>
        struct prev_impl<iterator<Vector, Pos>> {
            using type = iterator<Vector, Pos - 1>;
        };

        /////////////////////////////////
        // RandomAccessIterator
        /////////////////////////////////
        template <typename Iterator, typename N> struct advance_impl;
        template <typename Vector, Index Pos, typename N>
        struct advance_impl<iterator<Vector, Pos>, N> {
            using type = iterator<Vector, Pos + N::value>;
        };

        template <typename First, typename Last> struct distance_impl;
        template <typename Vector, Index First, Index Last>
        struct distance_impl<iterator<Vector, First>, iterator<Vector, Last>>
            : integral_c<decltype(Last - First), Last - First>
        { };

        template <typename Self, typename Other> struct less_impl;
        template <typename Vector, Index Self, Index Other>
        struct less_impl<iterator<Vector, Self>, iterator<Vector, Other>>
            : bool_<(Self < Other)>
        { };
    };

    namespace variadic = detail::variadic;
    struct vector_class final
        : RandomAccessSequence, RandomExtensibleContainer
    {
        /////////////////////////////////
        // Sequence
        /////////////////////////////////
        template <typename Vector>
        struct begin_impl {
            using type = iterator<Vector, 0>;
        };

        template <typename Vector> struct end_impl;
        template <typename ...T>
        struct end_impl<vector<T...>> {
            using type = iterator<vector<T...>, sizeof...(T)>;
        };

        template <typename Vector> struct is_empty_impl;
        // See below for the other specialization.
        template <typename ...T>
        struct is_empty_impl<vector<T...>>
            : false_
        { };

        template <typename Vector> struct size_impl;
        template <typename ...T>
        struct size_impl<vector<T...>>
            : size_t<sizeof...(T)>
        { };

        /////////////////////////////////
        // RandomAccessSequence
        /////////////////////////////////
        template <typename Vector, typename N> struct at_impl;
        template <typename ...T, typename N>
        struct at_impl<vector<T...>, N>
            : variadic::at<variadic::pack<T...>, N::value>
        { };

        /////////////////////////////////
        // Container
        /////////////////////////////////
        template <typename Vector>
        struct clear_impl {
            using type = vector<>;
        };

        /////////////////////////////////
        // BackExtensibleContainer
        /////////////////////////////////
        template <typename Vector> struct pop_back_impl;
        template <typename ...T>
        struct pop_back_impl<vector<T...>>
            : variadic::rebind<
                typename variadic::take<
                    variadic::pack<T...>, sizeof...(T) - 1
                >::type,
                vector
            >
        { };

        template <typename Vector, typename X> struct push_back_impl;
        template <typename ...T, typename X>
        struct push_back_impl<vector<T...>, X> {
            using type = vector<T..., X>;
        };

        /////////////////////////////////
        // FrontExtensibleContainer
        /////////////////////////////////
        template <typename Vector> struct pop_front_impl;
        template <typename Head, typename ...Tail>
        struct pop_front_impl<vector<Head, Tail...>> {
            using type = vector<Tail...>;
        };

        template <typename Vector, typename X> struct push_front_impl;
        template <typename ...T, typename X>
        struct push_front_impl<vector<T...>, X> {
            using type = vector<X, T...>;
        };

        /////////////////////////////////
        // RandomExtensibleContainer
        /////////////////////////////////
        template <typename Vector, typename Pos, typename Range>
        struct insert_range_impl;
        template <typename ...T, Index Pos, typename Range>
        struct insert_range_impl<
            vector<T...>, iterator<vector<T...>, Pos>, Range
        >
            : variadic::rebind<
                typename variadic::concat<
                    // [0, Pos)
                    typename variadic::take<variadic::pack<T...>, Pos>::type,
                    typename detail::copy_into_variadic_pack<Range>::type,
                    // [Pos, sizeof...(T))
                    typename variadic::drop<variadic::pack<T...>, Pos>::type
                >::type,
                vector
            >
        { };

        template <typename Vector, typename Pos, typename X>
        struct insert_impl
            : insert_range_impl<Vector, Pos, vector<X>>
        { };

        template <typename Vector, typename First, typename Last>
        struct erase_range_impl;
        template <typename ...T, Index First, Index Last>
        struct erase_range_impl<
            vector<T...>,
            iterator<vector<T...>, First>,
            iterator<vector<T...>, Last>
        >
            : variadic::rebind<
                typename variadic::concat<
                    // [0, First)
                    typename variadic::take<variadic::pack<T...>,First>::type,
                    // [Last, sizeof...(T))
                    typename variadic::drop<variadic::pack<T...>, Last>::type
                >::type,
                vector
            >
        { };

        template <typename V, typename Pos> struct erase_impl;
        template <typename V, Index Pos>
        struct erase_impl<V, iterator<V, Pos>>
            : erase_range_impl<V, iterator<V, Pos>, iterator<V, Pos + 1>>
        { };
    };

    // This can't appear inside the class because it's a full specialization.
    template <>
    struct vector_class::is_empty_impl<vector<>>
        : true_
    { };
} // end namespace vector_detail

template <typename Vector, vector_detail::Index Position>
struct class_of<vector_detail::iterator<Vector, Position>> {
    using type = vector_detail::iterator_class;
};

template <typename ...Elements>
struct class_of<vector<Elements...>> {
    using type = vector_detail::vector_class;
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VECTOR_HPP
