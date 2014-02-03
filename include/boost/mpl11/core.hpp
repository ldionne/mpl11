/*!
 * @file
 * Defines the @ref Core module.
 */

#ifndef BOOST_MPL11_CORE_HPP
#define BOOST_MPL11_CORE_HPP

#include <boost/mpl11/fwd/core.hpp>

#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/logical.hpp>


namespace boost { namespace mpl11 {
    template <typename x>
    struct box {
        using type = x;
    };

    namespace core_detail {
        template <typename T>
        auto pick_datatype(T*)  -> typename T::mpl_datatype;
        auto pick_datatype(...) -> Foreign;
    }

    template <typename ctor>
    struct datatype {
        using type = decltype(core_detail::pick_datatype((ctor*)nullptr));
    };

    template <typename Left, typename Right>
    struct common_datatype
        : common_datatype<Right, Left>
    { };


    struct Foreign {
        template <typename Datatype>
        using from = quote<id>;
    };

    template <typename Datatype>
    struct common_datatype<Foreign, Datatype> {
        using type = Foreign;
    };

    template <>
    struct Comparable<Foreign> {
        template <typename x, typename y>
        using equal_impl = detail::std_is_same<x, y>;

        template <typename x, typename y>
        using not_equal_impl = not_<detail::std_is_same<x, y>>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CORE_HPP
