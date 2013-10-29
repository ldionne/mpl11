/*!
 * @file
 * Defines `boost::mpl11::detail::test::integral_constant`.
 */

#ifndef BOOST_MPL11_DETAIL_TEST_INTEGRAL_CONSTANT_HPP
#define BOOST_MPL11_DETAIL_TEST_INTEGRAL_CONSTANT_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/detail/test/instantiate.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/prior.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace test {
    template <typename MakeIntegralConstant>
    class integral_constant {
        template <typename T, T N>
        using ic = typename apply<
            MakeIntegralConstant, T, integral_c<T, N>
        >::type;

        template <typename T, T N>
        struct impl {
            // ::value
            static_assert(ic<T, N>::value == N, "");

            // ::type
            static_assert(equal_to<
                typename ic<T, N>::type,
                ic<T, N>
            >::type::value, "");

            // ::value_type
            static_assert(equal_to<
                typename ic<T, N>::value_type,
                T
            >::type::value, "");

            // next
            static_assert(equal_to<
                typename next<ic<T, N>>::type,
                ic<T, N + 1>
            >::type::value, "");

            // prior
            static_assert(equal_to<
                typename prior<ic<T, N>>::type,
                ic<T, N - 1>
            >::type::value, "");

            // category_of
            static_assert(equal_to<
                typename category_of<ic<T, N>>::type,
                category::integral_constant
            >::type::value, "");

            // conversion to a runtime value
            static constexpr T i = ic<T, N>{};
        };

        BOOST_MPL11_INSTANTIATE_TEST(impl<int, -2>);
        BOOST_MPL11_INSTANTIATE_TEST(impl<int, -1>);
        BOOST_MPL11_INSTANTIATE_TEST(impl<int, 0>);
        BOOST_MPL11_INSTANTIATE_TEST(impl<int, 1>);
        BOOST_MPL11_INSTANTIATE_TEST(impl<int, 2>);
    };
}}}} // end namespace boost::mpl11::detail::test

#endif // !BOOST_MPL11_DETAIL_TEST_INTEGRAL_CONSTANT_HPP
