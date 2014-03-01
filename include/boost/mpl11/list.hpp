/*!
 * @file
 * Defines `boost::mpl11::list`.
 */

#ifndef BOOST_MPL11_LIST_HPP
#define BOOST_MPL11_LIST_HPP

#include <boost/mpl11/fwd/list.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/std_index_sequence.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/iterable.hpp>


namespace boost { namespace mpl11 {
    namespace list_detail {
        using namespace detail;

        template <std_size_t n, typename x>
        struct pair { };

        template <typename ns, typename ...xs>
        struct index_map;

        template <std_size_t ...ns, typename ...xs>
        struct index_map<std_index_sequence<ns...>, xs...>
            : pair<ns, xs>...
        { };

        template <std_size_t n, typename x>
        x at_index(pair<n, x>*);
    } // end namespace list_detail

    template <typename x, typename ...xs>
    struct list<x, xs...> {
        using type = list;
        using mpl_datatype = List;

        using head = x;
        using tail = list<xs...>;
        using is_empty = false_;
    };

    template <>
    struct list<> {
        using type = list;
        using mpl_datatype = List;

        using is_empty = true_;
    };

    template <typename x, typename xs>
    struct cons {
        using type = cons;
        using mpl_datatype = List;

        using head = x;
        using tail = xs;
        using is_empty = false_;
    };

    template <>
    struct Iterable<List> : default_Iterable {
        template <typename self>
        using head_impl = typename self::type::head;

        template <typename self>
        using tail_impl = typename self::type::tail;

        template <typename self>
        using is_empty_impl = typename self::type::is_empty;

        template <typename n, typename self>
        struct at_impl : default_Iterable::at_impl<n, self> { };

        template <typename n, typename ...xs>
        struct at_impl<n, list<xs...>>
            : decltype(list_detail::at_index<n::type::value>(
                (list_detail::index_map<
                    typename detail::make_std_index_sequence<
                        sizeof...(xs)
                    >::type,
                    xs...
                >*)nullptr
            ))
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LIST_HPP
