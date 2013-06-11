/*!
 * @file
 * This file defines `boost::mpl11::integral_c`.
 */

#ifndef BOOST_MPL11_INTEGRAL_C_HPP
#define BOOST_MPL11_INTEGRAL_C_HPP

#include <boost/type_traits/remove_cv.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension {
    template <typename> struct next_impl;
    template <typename> struct prior_impl;
}

namespace integral_c_detail { struct tag; }

template <typename I, I N>
struct integral_c {
    struct mpl11 { using tag = integral_c_detail::tag; };

    using value_type = typename remove_cv<I>::type;
    static constexpr value_type value = N;
    using type = integral_c;

private:
    friend struct extension::next_impl<integral_c_detail::tag>;
    friend struct extension::prior_impl<integral_c_detail::tag>;
    template <I NN> using rebind = integral_c<I, NN>;
};

namespace extension {
template <>
struct next_impl<integral_c_detail::tag> {
    template <typename IntegralC>
    struct apply {
        using type = typename IntegralC::template rebind<IntegralC::value + 1>;
    };
};

template <>
struct prior_impl<integral_c_detail::tag> {
    template <typename IntegralC>
    struct apply {
        using type = typename IntegralC::template rebind<IntegralC::value - 1>;
    };
};
}
}}}

#endif // !BOOST_MPL11_INTEGRAL_C_HPP
