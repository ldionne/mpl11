/*!
 * @file
 * Defines `boost::mpl11::list`.
 */

#ifndef BOOST_MPL11_LIST_HPP
#define BOOST_MPL11_LIST_HPP

#include <boost/mpl11/fwd/list.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/index_sequence.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/detail/variadic_last.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/id.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
    template <typename ...T>
    struct tag_of<list<T...>> { using type = sequence_tag; };

    template <typename ...T>
    struct sequence_traits<list<T...>> {
        static constexpr bool has_O1_length = true;
        static constexpr bool has_O1_unpack = true;
        static constexpr bool is_finite = true;
    };

    /////////////////////////////////
    // Minimal complete definition
    /////////////////////////////////
    template <typename Head, typename ...Tail>
    struct head_impl<list<Head, Tail...>> {
        using type = Head;
    };

    template <typename Head, typename ...Tail>
    struct tail_impl<list<Head, Tail...>> {
        using type = list<Tail...>;
    };

    template <typename ...T>
    struct is_empty_impl<list<T...>>
        : false_
    { };

    template <>
    struct is_empty_impl<list<>>
        : true_
    { };


    /////////////////////////////////
    // Optimizations
    /////////////////////////////////
    template <typename ...T>
    struct length_impl<list<T...>>
        : size_t<sizeof...(T)>
    { };

    template <typename ...T, typename F>
    struct unpack_impl<list<T...>, F> {
        using type = typename apply<F, T...>::type;
    };

    template <typename Head, typename ...Tail>
    struct last_impl<list<Head, Tail...>> {
        using type = typename detail::variadic_last<Head, Tail...>::type;
    };

    namespace list_detail {
        using namespace detail;

        template <std_size_t Index, typename Value>
        struct index_holder { };

        template <typename Indices, typename ...T>
        struct index_based_lookup;

        template <std_size_t ...Indices, typename ...T>
        struct index_based_lookup<index_sequence<Indices...>, T...>
            : index_holder<Indices, T>...
        { };

        template <std_size_t Index, typename Value>
        id<Value> at_index(index_holder<Index, Value>*);
    } // end namespace list_detail

    template <typename ...T>
    struct list
        : list_detail::index_based_lookup<
            typename detail::make_index_sequence<sizeof...(T)>::type, T...
        >
    { };

    template <typename ...T, detail::std_size_t Index>
    struct at_c_impl<list<T...>, Index> {
        using type = typename decltype(
            list_detail::at_index<Index>((list<T...>*)nullptr)
        )::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LIST_HPP
