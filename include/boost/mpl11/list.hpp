/*!
 * @file
 * Defines `boost::mpl11::list`.
 */

#ifndef BOOST_MPL11_LIST_HPP
#define BOOST_MPL11_LIST_HPP

#include <boost/mpl11/fwd/list.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/iterable.hpp>


namespace boost { namespace mpl11 {
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
    struct Iterable<List> {
        template <typename self>
        using head_impl = typename self::type::head;

        template <typename self>
        using tail_impl = typename self::type::tail;

        template <typename self>
        using is_empty_impl = typename self::type::is_empty;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LIST_HPP
