/*!
 * @file
 * This file defines `boost::mpl11::facade`.
 */

#ifndef BOOST_MPL11_FACADE_BASE_HPP
#define BOOST_MPL11_FACADE_BASE_HPP

#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/has_key.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/set.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Intrinsics>
struct facade_tag {
    template <template <typename ...> class Intrinsic>
    struct is_enabled_for
        : has_key<Intrinsics, quote<Intrinsic>>
    { };
};

template <typename T, template <typename ...> class Intrinsic>
struct if_facade_enabled
    : if_<typename facade_tag<T>::template is_enabled_for<Intrinsic>>
{ };

template <template <typename ...> class ...Intrinsics>
struct facade {
    struct mpl11 {
        using tag = facade_tag<set<quote<Intrinsics>...>>;
    };
};
}}}

#endif // !BOOST_MPL11_FACADE_BASE_HPP
