/*!
 * @file
 * Defines `boost::mpl11::test::back_extensible_sequence`.
 */

#ifndef BOOST_MPL11_TEST_BACK_EXTENSIBLE_SEQUENCE_HPP
#define BOOST_MPL11_TEST_BACK_EXTENSIBLE_SEQUENCE_HPP

#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/pop_back.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


namespace boost { namespace mpl11 { namespace test {
    template <typename MakeSequence, typename MakeElement = quote<inherit>>
    class back_extensible_sequence {
        template <unsigned int i>
        using element = typename apply<MakeElement, uint<i>>::type;

        template <unsigned int ...i>
        using sequence = typename apply<MakeSequence, element<i>...>::type;

        // push_back
        static_assert(equal_to<
            typename push_back<sequence<>, element<0>>::type,
            sequence<0>
        >::type::value, "");

        static_assert(equal_to<
            typename push_back<sequence<0>, element<1>>::type,
            sequence<0, 1>
        >::type::value, "");

        static_assert(equal_to<
            typename push_back<sequence<0, 1>, element<2>>::type,
            sequence<0, 1, 2>
        >::type::value, "");


        // pop_back
        static_assert(equal_to<
            typename pop_back<sequence<0>>::type,
            sequence<>
        >::type::value, "");

        static_assert(equal_to<
            typename pop_back<sequence<0, 1>>::type,
            sequence<0>
        >::type::value, "");


        // clear
        static_assert(equal_to<
            typename clear<sequence<>>::type,
            sequence<>
        >::type::value, "");

        static_assert(equal_to<
            typename clear<sequence<0>>::type,
            sequence<>
        >::type::value, "");

        static_assert(equal_to<
            typename clear<sequence<0, 1>>::type,
            sequence<>
        >::type::value, "");
    };
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_BACK_EXTENSIBLE_SEQUENCE_HPP
