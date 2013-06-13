/*!
 * @file
 * This file defines `boost::mpl11::integral_c`.
 */

#ifndef BOOST_MPL11_INTEGRAL_C_HPP
#define BOOST_MPL11_INTEGRAL_C_HPP

#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>

#include <boost/type_traits/remove_cv.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename I, I N>
class integral_c {
    struct implementation {
        template <template <typename ...> class Impl, typename ...Args>
        struct apply;

        template <typename IntegralC>
        struct apply<next, IntegralC> {
            using type = integral_c<I, N + 1>;
        };

        template <typename IntegralC>
        struct apply<prior, IntegralC> {
            using type = integral_c<I, N - 1>;
        };
    };

public:
    struct mpl11 { using dispatcher = implementation; };

    using value_type = typename remove_cv<I>::type;
    static constexpr value_type value = N;
    using type = integral_c;
    constexpr operator value_type() const { return value; }
};
}}}

#endif // !BOOST_MPL11_INTEGRAL_C_HPP
