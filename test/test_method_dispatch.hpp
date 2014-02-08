/*!
 * @file
 * Defines utilities to ease the testing of typeclass method dispatching.
 */

#ifndef BOOST_MPL11_TEST_TEST_METHOD_DISPATCH_HPP
#define BOOST_MPL11_TEST_TEST_METHOD_DISPATCH_HPP

#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/fwd/core.hpp>


template <unsigned level = 0>
struct Archetype {
    template <typename>
    using from = boost::mpl11::quote<boost::mpl11::id>;
};

template <unsigned level = 0>
struct archetype {
    struct type { using mpl_datatype = Archetype<level>; };
};

namespace boost { namespace mpl11 {
    template <unsigned l1, unsigned l2>
    struct common_datatype<Archetype<l1>, Archetype<l2>> {
        using type = Archetype<(l1 < l2 ? l1 : l2)>;
    };
}}

template <template <typename ...> class f>
struct method_tag { using type = method_tag; };

template <template <typename ...> class f, typename ...args>
struct method {
    static_assert(boost::mpl11::detail::std_is_same<
        typename f<args...>::type,
        method_tag<f>
    >::value, "");
};

#endif // !BOOST_MPL11_TEST_TEST_METHOD_DISPATCH_HPP
