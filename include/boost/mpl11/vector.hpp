/*!
 * @file
 * Defines `boost::mpl11::vector`.
 */

#ifndef BOOST_MPL11_VECTOR_HPP
#define BOOST_MPL11_VECTOR_HPP

#include <boost/mpl11/fwd/vector.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/args.hpp>
#include <boost/mpl11/detail/dependent_on.hpp>
#include <boost/mpl11/detail/index_sequence.hpp>
#include <boost/mpl11/detail/nested_alias.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/advance.hpp>
#include <boost/mpl11/fwd/at.hpp>
#include <boost/mpl11/fwd/back.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/fwd/clear.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/distance.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/equal.hpp>
#include <boost/mpl11/fwd/erase.hpp>
#include <boost/mpl11/fwd/erase_range.hpp>
#include <boost/mpl11/fwd/front.hpp>
#include <boost/mpl11/fwd/has_optimization.hpp>
#include <boost/mpl11/fwd/insert.hpp>
#include <boost/mpl11/fwd/insert_range.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/join.hpp>
#include <boost/mpl11/fwd/length.hpp>
#include <boost/mpl11/fwd/less.hpp>
#include <boost/mpl11/fwd/new.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/pop_back.hpp>
#include <boost/mpl11/fwd/pop_front.hpp>
#include <boost/mpl11/fwd/prev.hpp>
#include <boost/mpl11/fwd/push_back.hpp>
#include <boost/mpl11/fwd/push_front.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp> // for vector_c
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/optimization.hpp>
#include <boost/mpl11/random_access_iterator.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/random_extensible_container.hpp>
#include <boost/mpl11/unpack.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Vector iterator
//////////////////////////////////////////////////////////////////////////////
namespace vector_detail {
    template <typename Vector, detail::std_size_t Pos>
    struct iterator;

    template <detail::std_size_t Index, typename Value>
    struct index_holder { };

    template <typename Indices, typename ...T>
    struct index_based_lookup;

    template <detail::std_size_t ...Indices, typename ...T>
    struct index_based_lookup<detail::index_sequence<Indices...>, T...>
        : index_holder<Indices, T>...
    { };

    template <detail::std_size_t Index, typename Value>
    identity<Value> at_index(index_holder<Index, Value>*);
} // end namespace vector_detail

template <typename V, detail::std_size_t Pos, typename Default>
struct class_of<vector_detail::iterator<V, Pos>, Default> {
    using type = RandomAccessIterator;
};

/////////////////////////////////
// ForwardIterator
/////////////////////////////////
template <typename V, detail::std_size_t Pos>
struct next<vector_detail::iterator<V, Pos>> {
    using type = vector_detail::iterator<V, Pos + 1>;
};

template <typename ...T>
struct next<vector_detail::iterator<vector<T...>, sizeof...(T)>> {
    struct type;

    static_assert(detail::dependent_on<type>::value(false),
    "Invalid usage of `next`: "
    "Incrementing a past-the-end iterator of a `vector`.");
};

template <typename Vector, detail::std_size_t Pos>
struct deref<vector_detail::iterator<Vector, Pos>>
    : decltype(vector_detail::at_index<Pos>((Vector*)nullptr))
{ };

template <typename ...T>
struct deref<vector_detail::iterator<vector<T...>, sizeof...(T)>> {
    struct type;

    static_assert(detail::dependent_on<type>::value(false),
    "Invalid usage of `deref`: "
    "Dereferencing a past-the-end iterator of a `vector`.");
};

template <typename V, detail::std_size_t Self, detail::std_size_t Other>
struct equal<
    vector_detail::iterator<V, Self>,
    vector_detail::iterator<V, Other>
>
    : bool_<Self == Other>
{ };

/////////////////////////////////
// BidirectionalIterator
/////////////////////////////////
template <typename V>
struct prev<vector_detail::iterator<V, 0>> {
    struct type;

    static_assert(detail::dependent_on<type>::value(false),
    "Invalid usage of `prev`: "
    "Decrementing an iterator to the beginning of a `vector`.");
};

template <typename V, detail::std_size_t Pos>
struct prev<vector_detail::iterator<V, Pos>> {
    using type = vector_detail::iterator<V, Pos - 1>;
};

/////////////////////////////////
// RandomAccessIterator
/////////////////////////////////
template <typename V, detail::std_size_t Pos, typename N>
struct advance<vector_detail::iterator<V, Pos>, N> {
    using type = vector_detail::iterator<V, Pos + N::value>;
};

template <typename V, detail::std_size_t First, detail::std_size_t Last>
struct distance<
    vector_detail::iterator<V, First>,
    vector_detail::iterator<V, Last>
>
    : integral_c<decltype(Last - First), Last - First>
{ };

template <typename V, detail::std_size_t Self, detail::std_size_t Other>
struct less<
    vector_detail::iterator<V, Self>,
    vector_detail::iterator<V, Other>
>
    : bool_<(Self < Other)>
{ };


//////////////////////////////////////////////////////////////////////////////
// Vector
//////////////////////////////////////////////////////////////////////////////
template <typename ...T, typename Default>
struct class_of<vector<T...>, Default>
    : inherit<RandomAccessSequence, RandomExtensibleContainer>
{ };

template <typename ...T>
struct vector
    : vector_detail::index_based_lookup<
        typename detail::make_index_sequence<sizeof...(T)>::type, T...
    >
{ };

/////////////////////////////////
// Sequence
/////////////////////////////////
template <typename ...T>
struct begin<vector<T...>> {
    using type = vector_detail::iterator<vector<T...>, 0>;
};

template <typename ...T>
struct end<vector<T...>> {
    using type = vector_detail::iterator<vector<T...>, sizeof...(T)>;
};

template <typename ...T>
struct is_empty<vector<T...>>
    : false_
{ };

template <>
struct is_empty<vector<>>
    : true_
{ };

template <typename ...T>
struct length<vector<T...>>
    : size_t<sizeof...(T)>
{ };

/////////////////////////////////
// DirectionalSequence
/////////////////////////////////
template <typename ...T>
struct front<vector<T...>> {
    static_assert(sizeof...(T) > 0,
    "Invalid usage of `front`: Using `front` on an empty `vector`.");

    struct type;
};

template <typename Head, typename ...Tail>
struct front<vector<Head, Tail...>> {
    using type = Head;
};

/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
template <typename ...T>
struct back<vector<T...>> {
    static_assert(sizeof...(T) > 0,
    "Invalid usage of `back`: Using `back` on an empty `vector`.");

    using type = typename decltype(
        vector_detail::at_index<sizeof...(T) - 1>((vector<T...>*)nullptr)
    )::type;
};

/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
template <typename ...T, typename Index>
struct at<vector<T...>, Index> {
    static_assert(Index::value >= 0,
    "Invalid usage of `at`: Accessing a `vector` at a negative index.");

    using type = typename decltype(
        vector_detail::at_index<Index::value>((vector<T...>*)nullptr)
    )::type;
};

/////////////////////////////////
// Container
/////////////////////////////////
template <typename ...T>
struct clear<vector<T...>> {
    using type = vector<>;
};

template <typename ...T>
struct new_<vector<T...>> {
    template <typename Sequence>
    BOOST_MPL11_NESTED_ALIAS(apply, unpack<Sequence, into<vector>>);
};

/////////////////////////////////
// BackExtensibleContainer
/////////////////////////////////
template <typename ...T>
struct pop_back<vector<T...>>
    : apply<args<0, sizeof...(T) - 1>, T...>
{ };

template <typename ...T, typename X>
struct push_back<vector<T...>, X> {
    using type = vector<T..., X>;
};

/////////////////////////////////
// FrontExtensibleContainer
/////////////////////////////////
template <typename ...Empty>
struct pop_front<Empty...> {
    static_assert(sizeof...(Empty) > 0,
    "Invalid usage of `pop_front`: "
    "Can't use `pop_front` on an empty `vector`.");

    struct type;
};

template <typename Head, typename ...Tail>
struct pop_front<vector<Head, Tail...>> {
    using type = vector<Tail...>;
};

template <typename ...T, typename X>
struct push_front<vector<T...>, X> {
    using type = vector<X, T...>;
};

/////////////////////////////////
// RandomExtensibleContainer
/////////////////////////////////
template <typename ...T, detail::std_size_t Pos, typename Range>
struct insert_range<
    vector<T...>,
    vector_detail::iterator<vector<T...>, Pos>,
    Range
>
    : join<
        // [0, Pos)
        apply_t<args<0, Pos>, T...>,
        // [begin<Range>, end<Range>)
        unpack_t<Range, into<vector>>,
        // [Pos, sizeof...(T))
        apply_t<args<Pos, sizeof...(T)>, T...>
    >
{ };

template <typename ...T, detail::std_size_t Pos, typename X>
struct insert<vector<T...>, vector_detail::iterator<vector<T...>, Pos>, X>
    : join<
        push_back_t<apply_t<args<0, Pos>, T...>, X>, // [0, Pos) ++ X
        apply_t<args<Pos, sizeof...(T)>, T...>       // [Pos, sizeof...(T))
    >
{ };

template <typename ...T, detail::std_size_t First, detail::std_size_t Last>
struct erase_range<
    vector<T...>,
    vector_detail::iterator<vector<T...>, First>,
    vector_detail::iterator<vector<T...>, Last>
>
    : join<
        // [0, First)
        apply_t<args<0, First>, T...>,
        // [Last, sizeof...(T))
        apply_t<args<Last, sizeof...(T)>, T...>
    >
{ };

template <typename ...T, detail::std_size_t Pos>
struct erase<vector<T...>, vector_detail::iterator<vector<T...>, Pos>>
    : join<
        // [0, Pos)
        apply_t<args<0, Pos>, T...>,
        // [Pos + 1, sizeof...(T))
        apply_t<args<Pos + 1, sizeof...(T)>, T...>
    >
{ };

/////////////////////////////////
// Other specializations
/////////////////////////////////
template <typename ...T, typename F>
struct unpack<vector<T...>, F>
    : apply<F, T...>
{ };

template <typename ...T, typename ...U, typename ...More>
struct join<vector<T...>, vector<U...>, More...>
    : join<vector<T..., U...>, More...>
{ };

template <typename ...T, typename ...U>
struct join<vector<T...>, vector<U...>> {
    using type = vector<T..., U...>;
};

template <typename ...T>
struct has_optimization<vector<T...>, optimization::O1_length>
    : true_
{ };

template <typename ...T>
struct has_optimization<vector<T...>, optimization::O1_unpack>
    : true_
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VECTOR_HPP
