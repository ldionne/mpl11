/*!
 * @file
 * Defines `boost::mpl11::vector`.
 */

#ifndef BOOST_MPL11_VECTOR_HPP
#define BOOST_MPL11_VECTOR_HPP

#include <boost/mpl11/fwd/vector.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/bidirectional_sequence.hpp>
#include <boost/mpl11/detail/index_sequence.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/detail/variadic_drop.hpp>
#include <boost/mpl11/detail/variadic_take.hpp>
#include <boost/mpl11/forward_sequence.hpp>
#include <boost/mpl11/fwd/finite_sequence.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp> // required for forward declaration
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/sequence_traits.hpp>


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

template <typename ...T>
struct sequence_traits<vector<T...>> : defaults::sequence_traits {
    static constexpr bool has_O1_size = true;
    static constexpr bool has_O1_unpack = true;
    static constexpr bool is_finite = true;
};

/////////////////////////////////
// ForwardSequence
/////////////////////////////////
template <typename Head, typename ...Tail>
struct head<vector<Head, Tail...>> {
    using type = Head;
};

template <typename Head, typename ...Tail>
struct tail<vector<Head, Tail...>> {
    using type = vector<Tail...>;
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

template <typename Head, typename ...Tail>
struct init<vector<Head, Tail...>>
    : apply<
        detail::variadic_take<sizeof...(Tail), into<vector>>,
        Head, Tail...
    >
{ };


/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
namespace vector_detail {
    template <detail::std_size_t Index, typename Value>
    identity<Value> at_index(index_holder<Index, Value>*);
}

template <typename ...T, typename Index>
struct at<vector<T...>, Index>
    : private BOOST_MPL11_CHECK_USAGE(at<vector<T...>, Index>)
{
    using type = typename decltype(
        vector_detail::at_index<Index::value>((vector<T...>*)nullptr)
    )::type;
};

template <typename ...T, typename Start, typename Stop>
struct slice<vector<T...>, Start, Stop>
    : private BOOST_MPL11_CHECK_USAGE(slice<vector<T...>, Start, Stop>)
{
    using type = typename apply<
        detail::variadic_drop<Start::value,
            detail::variadic_take<Stop::value - Start::value,
                into<vector>
            >
        >,
        T...
    >::type;
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VECTOR_HPP
