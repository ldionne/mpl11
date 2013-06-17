/*!
 * @file
 * This file defines `boost::mpl11::detail::wrap_with`.
 */

#ifndef BOOST_MPL11_DETAIL_WRAP_WITH_HPP
#define BOOST_MPL11_DETAIL_WRAP_WITH_HPP

#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
template <typename T>
class wrap {
    using Wrapped = typename eval<identity<T>>::type;

public:
    template <template <typename ...> class Wrapper>
    struct with {
        using type = Wrapper<Wrapped>;

        template <bool Cond>
        using if_c = mpl11::if_c<Cond, Wrapper<Wrapped>, Wrapped>;

        template <typename Cond>
        using if_ = if_c<Cond::type::value>;
    };
};
}}}}

#endif // !BOOST_MPL11_DETAIL_WRAP_WITH_HPP
