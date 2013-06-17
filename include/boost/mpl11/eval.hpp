/*!
 * @file
 * This file defines `boost::mpl11::eval`.
 */

#ifndef BOOST_MPL11_EVAL_HPP
#define BOOST_MPL11_EVAL_HPP

#include <boost/mpl11/functional/protect.hpp>
#include <boost/mpl11/has_xxx.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Metafunction>
struct eval;

namespace eval_detail {
    BOOST_MPL11_HAS_NESTED_TYPE(has_type, type)

    template <typename T>
    struct eval_rec {
        using type = T;
    };

    template <typename T>
    struct eval_rec<protect<T>> {
        using type = protect<T>;
    };

    template <typename T>
    struct eval_rec<eval<T>>
        : eval<T>
    { };

    template <template <typename ...> class X, typename ...T>
    struct eval_rec<X<T...>> {
        using type = X<typename eval_rec<T>::type...>;
    };

    template <typename T, bool = has_type<T>::value>
    struct nested_type : T { };

    template <typename T>
    struct nested_type<T, false> { };

    template <typename T, bool = has_type<T>::value>
    struct nested_type_type : nested_type<typename T::type> { };

    template <typename T>
    struct nested_type_type<T, false> { };
}

template <typename Metafunction>
struct eval
    : eval_detail::nested_type_type<eval_detail::eval_rec<Metafunction>>
{ };
}}}

#endif // !BOOST_MPL11_EVAL_HPP
