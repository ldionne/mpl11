/*!
 * @file
 * This file defines `boost::mpl11::detail::wrap_with`.
 */

#ifndef BOOST_MPL11_DETAIL_WRAP_WITH_HPP
#define BOOST_MPL11_DETAIL_WRAP_WITH_HPP

#include <boost/mpl11/detail/trailing_if.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
template <typename T>
struct wrap {
    template <template <typename ...> class Wrapper>
    struct with : trailing_if<with<Wrapper>, T> {
        using type = Wrapper<T>;
    };
};
}}}}

#endif // !BOOST_MPL11_DETAIL_WRAP_WITH_HPP
