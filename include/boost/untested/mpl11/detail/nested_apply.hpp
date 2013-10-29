/*!
 * @file
 * Defines `boost::mpl11::detail::nested_apply`.
 */

#ifndef BOOST_MPL11_DETAIL_NESTED_APPLY_HPP
#define BOOST_MPL11_DETAIL_NESTED_APPLY_HPP

#include <boost/mpl11/empty_base.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
namespace nested_apply_detail {
    // Preferred overload.
    template <typename F, typename ...Args>
    auto pick(int, identity<F>*, identity<Args>* ...) ->
        identity<typename F::template apply<Args...>>
    ;

    // If there are no arguments, check for a non-template nested apply too.
    template <typename F>
    auto pick(char, identity<F>*) ->
        identity<typename F::apply>
    ;

    // Otherwise, there is no nested apply.
    auto pick(...) ->
        empty_base
    ;
} // end namespace nested_apply_detail

namespace detail {
    template <typename F, typename ...Args>
    struct nested_apply
        : decltype(
            nested_apply_detail::pick(
                int{}, (identity<F>*)nullptr, (identity<Args>*)nullptr...
            )
        )
    { };
} // end namespace detail
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_NESTED_APPLY_HPP
