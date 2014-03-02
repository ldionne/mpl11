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
    // box
    template <typename x>
    struct box {
        using type = x;
    };



    // datatype
    namespace core_detail {
        template <typename T>
        auto pick_datatype(T*)  -> typename T::mpl_datatype;
        auto pick_datatype(...) -> Foreign;
    }

    template <typename ctor>
    struct datatype {
        using type = decltype(core_detail::pick_datatype((ctor*)nullptr));
    };



    // common_datatype
    template <typename Left, typename Right>
    struct common_datatype
        : common_datatype<Right, Left>
    { };



    // cast
    template <typename From, typename To>
    struct cast : To::template from<From> { };

    template <typename To>
    struct cast<To, To> : quote<id> { };



    // Foreign
    template <typename Datatype>
    struct common_datatype<Foreign, Datatype> {
        using type = Foreign;
    };

    template <typename From>
    struct cast<From, Foreign> : quote<id> { };

    template <>
    struct cast<Foreign, Foreign> : quote<id> { };

    template <>
    struct Comparable<Foreign> {
        template <typename x, typename y>
        using equal_impl = detail::std_is_same<
            typename x::type, typename y::type
        >;

        template <typename x, typename y>
        using not_equal_impl = not_<detail::std_is_same<
            typename x::type, typename y::type
        >>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CORE_HPP
