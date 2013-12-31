/*!
 * @file
 * Defines `boost::mpl11::test::positional_iterator`.
 */

#ifndef BOOST_MPL11_TEST_POSITIONAL_ITERATOR_HPP
#define BOOST_MPL11_TEST_POSITIONAL_ITERATOR_HPP

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 { namespace test {
    template <long long i>
    struct positional_iterator {
        static constexpr auto value = i;

        struct mpl_class {
            template <typename Self>
            struct next_impl {
                using type = positional_iterator<Self::value + 1>;
            };

            template <typename Self>
            struct prev_impl {
                using type = positional_iterator<Self::value - 1>;
            };

            template <typename Self>
            using deref_impl = integral_c<decltype(Self::value), Self::value>;

            template <typename Self, typename Other>
            using equal_impl = bool_<Self::value == Other::value>;

            template <typename Self, typename Other>
            using less_impl = bool_<Self::value < Other::value>;

            template <typename Self, typename Other>
            struct distance_impl
                : integral_c<
                    decltype(Other::value - Self::value),
                    Other::value - Self::value
                >
            { };

            template <typename Self, typename N>
            struct advance_impl {
                using type = positional_iterator<Self::value + N::value>;
            };
        };
    };
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_POSITIONAL_ITERATOR_HPP
