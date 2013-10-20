/*!
 * @file
 * Defines `boost::mpl11::integral_c`.
 */

#ifndef BOOST_MPL11_INTEGRAL_C_HPP
#define BOOST_MPL11_INTEGRAL_C_HPP

#include <boost/mpl11/fwd/integral_c.hpp>

#include <boost/mpl11/boolean.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    namespace integral_c_detail {
        struct IntegralC : Boolean /*, Integral */ {
            template <typename Condition, typename Then, typename Else>
            struct if_
                : detail::conditional<Condition::value, Then, Else>
            { };

            template <typename Self>
            struct not_
                : identity<
                    bool_<!Self::value>
                >
            { };
#if 0
            template <typename Self>
            struct negate {
                using type = integral_c<decltype(-Self::value), -Self::value>;
            };

            template <typename Self, typename Other>
            struct plus {
                using type = integral_c<
                    decltype(Self::value + Other::value),
                    Self::value + Other::value
                >;
            };

            template <typename Self, typename Other>
            struct multiplies {
                using type = integral_c<
                    decltype(Self::value * Other::value),
                    Self::value * Other::value
                >;
            };

            template <typename Self, typename Other>
            struct modulus {
                using type = integral_c<
                    decltype(Self::value % Other::value),
                    Self::value % Other::value
                >;
            };
#endif

            template <typename Self, typename Other>
            struct less
                : identity<
                    bool_<(Self::value < Other::value)>
                >
            { };

            template <typename Self, typename Other>
            struct equal_to
                : identity<
                    bool_<(Self::value == Other::value)>
                >
            { };
        };
    } // end namespace integral_c_detail

    template <typename I, I N>
    struct integral_c {
        using value_type = I;
        static constexpr value_type value = N;
        constexpr operator value_type() const { return value; }

        using mpl_class = integral_c_detail::IntegralC;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_C_HPP
