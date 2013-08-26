/*!
 * @file
 * This file defines `boost::mpl11::integral_c`.
 */

#ifndef BOOST_MPL11_INTEGRAL_INTEGRAL_C_HPP
#define BOOST_MPL11_INTEGRAL_INTEGRAL_C_HPP

#include <boost/mpl11/intrinsic_fwd.hpp>

#include <boost/type_traits/remove_cv.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic { struct next; struct prior; }

    template <typename I, I N>
    class integral_c {
        struct implementation {
            template <typename Intrinsic, typename ...Args>
            struct apply;

            template <typename ...Ignore>
            struct apply<intrinsic::next, Ignore...> {
                using type = integral_c<I, N + 1>;
            };

            template <typename ...Ignore>
            struct apply<intrinsic::prior, Ignore...> {
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_INTEGRAL_C_HPP
