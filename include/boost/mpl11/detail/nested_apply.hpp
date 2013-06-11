/*!
 * @file
 * This file defines `boost::mpl11::detail::nested_apply`.
 */

#ifndef BOOST_MPL11_DETAIL_NESTED_APPLY_HPP
#define BOOST_MPL11_DETAIL_NESTED_APPLY_HPP

#include <boost/utility/enable_if.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
namespace nested_apply_detail {
    template <typename T, typename ...Args>
    struct fetch_template_apply
    { typedef typename T::template apply<Args...> type; };

    template <typename T>
    struct fetch_non_template_apply
    { typedef typename T::apply type; };

    struct dont_fetch_anything { };

    template <typename T, typename ...Args>
    struct pick_apply_fetcher {
        template <typename U> static
        fetch_template_apply<U, Args...>
        test(typename U::template apply<Args...>* =0);

        template <typename U, typename = typename
            enable_if_c<sizeof...(Args) == 0>::type
        > static
        fetch_non_template_apply<U>
        test(typename U::apply* =0);

        template <typename U> static
        dont_fetch_anything
        test(...);

        typedef decltype(test<T>(0)) type;
    };
} // end namespace nested_apply_detail

template <typename M, typename ...Args>
struct nested_apply
    : nested_apply_detail::pick_apply_fetcher<M, Args...>::type
{ };
}}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_NESTED_APPLY_HPP
