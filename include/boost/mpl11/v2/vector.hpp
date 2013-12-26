/*!
 * @file
 * Defines `boost::mpl11::vector`.
 */

#ifndef BOOST_MPL11_VECTOR_HPP
#define BOOST_MPL11_VECTOR_HPP

#include <boost/mpl11/v2/fwd/vector.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/index_sequence.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/at.hpp>
#include <boost/mpl11/fwd/head.hpp>
#include <boost/mpl11/fwd/init.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/last.hpp>
#include <boost/mpl11/fwd/length.hpp>
#include <boost/mpl11/fwd/slice.hpp>
#include <boost/mpl11/fwd/tail.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp> // for vector_c

#include <boost/mpl11/v2/forward_sequence.hpp> // for Comparable and Orderable
#include <boost/mpl11/v2/fwd/comparable.hpp>
#include <boost/mpl11/v2/fwd/orderable.hpp>
#include <boost/mpl11/v2/fwd/tag_of.hpp>
#include <boost/mpl11/v2/tags.hpp>


namespace boost { namespace mpl11 {
namespace vector_detail {
    template <detail::std_size_t Index, typename Value>
    struct index_holder { };

    template <typename Indices, typename ...T>
    struct index_based_lookup;

    template <detail::std_size_t ...Indices, typename ...T>
    struct index_based_lookup<detail::index_sequence<Indices...>, T...>
        : index_holder<Indices, T>...
    { };
} // end namespace vector_detail

template <typename ...T>
struct vector
    : vector_detail::index_based_lookup<
        typename detail::make_index_sequence<sizeof...(T)>::type, T...
    >
{ };

template <typename ...T>
struct tag_of<vector<T...>> {
    using type = random_access_sequence_tag;
};


/////////////////////////////////
// ForwardSequence
/////////////////////////////////
template <typename Head, typename ...Tail>
struct head<vector<Head, Tail...>> {
    using type = Head;
};

template <typename ...T>
struct head<vector<T...>> {
    static_assert(sizeof...(T) > 0,
    "Invalid usage of `head` on an empty `vector`.");
    struct type;
};

template <typename Head, typename ...Tail>
struct tail<vector<Head, Tail...>> {
    using type = vector<Tail...>;
};

template <typename ...T>
struct tail<vector<T...>> {
    static_assert(sizeof...(T) > 0,
    "Invalid usage of `tail` on an empty `vector`.");
    struct type;
};

template <typename ...T>
struct is_empty<vector<T...>>
    : false_
{ };

template <>
struct is_empty<vector<>>
    : true_
{ };


/////////////////////////////////
// FiniteSequence
/////////////////////////////////
template <typename ...T>
struct length<vector<T...>>
    : size_t<sizeof...(T)>
{ };

template <typename ...T, typename F>
struct unpack<vector<T...>, F>
    : apply<F, T...>
{ };


/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
template <typename Head, typename ...Tail>
struct last<vector<Head, Tail...>>
    : detail::variadic_last<Head, Tail...>
{ };

template <typename ...T>
struct last<vector<T...>> {
    static_assert(sizeof...(T) > 0,
    "Invalid usage of `last` on an empty `vector`.");
    struct type;
};

template <typename Head, typename ...Tail>
struct init<vector<Head, Tail...>>
#if 0
    : apply<
        detail::take_args<sizeof...(Tail), into<vector>>,
        Head, Tail...
    >
#endif
    : apply<args<0, sizeof...(Tail)>, Head, Tail...>
{ };

template <typename ...T>
struct init<vector<T...>> {
    static_assert(sizeof...(T) > 0,
    "Invalid usage of `init` on an empty `vector`.");
    struct type;
};


/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
namespace vector_detail {
    template <detail::std_size_t Index, typename Value>
    identity<Value> at_index(index_holder<Index, Value>*);
}

template <typename ...T, typename Index>
struct at<vector<T...>, Index> {
    static_assert(Index::value >= 0,
    "Invalid usage of `at`: Accessing a `vector` at a negative index.");

    static_assert(Index::value < sizeof...(T),
    "Invalid usage of `at`: Accessing a `vector` at an out-of-bounds index.");

    using type = typename decltype(
        vector_detail::at_index<Index::value>((vector<T...>*)nullptr)
    )::type;
};

template <typename ...T, typename Start, typename Stop>
struct slice<vector<T...>, Start, Stop>
#if 0
        detail::drop_args<Start::value,
            detail::take_args<Stop::value - Start::value,
                into<vector>
            >
        >
#endif
{
    static_assert(Start::value >= 0,
    "Invalid usage of `slice`: Start and Stop indexes must be non-negative.");

    static_assert(Start::value <= Stop::value,
    "Invalid usage of `slice`: Start index greater than the Stop index.");

    static_assert(Start::value <= sizeof...(T),
    "Invalid usage of `slice`: Start index out-of-bounds of the `vector`.");

    using type = typename apply<
        args<Start::value, Stop::value>, T...
    >::type;
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VECTOR_HPP
