/*!
 * @file
 * Defines `boost::mpl11::test::front_extensible_sequence`.
 */

#ifndef BOOST_MPL11_TEST_FRONT_EXTENSIBLE_SEQUENCE_HPP
#define BOOST_MPL11_TEST_FRONT_EXTENSIBLE_SEQUENCE_HPP

#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/pop_front.hpp>
#include <boost/mpl11/intrinsic/push_front.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


namespace boost { namespace mpl11 { namespace test {
    template <typename MakeSequence, typename MakeElement = quote<inherit>>
    class front_extensible_sequence {
        template <unsigned int i>
        using element = typename apply<MakeElement, uint<i>>::type;

        template <unsigned int ...i>
        using sequence = typename apply<MakeSequence, element<i>...>::type;

        // push_front
        static_assert(equal_to<
            typename push_front<sequence<>, element<0>>::type,
            sequence<0>
        >::type::value, "");

        static_assert(equal_to<
            typename push_front<sequence<1>, element<0>>::type,
            sequence<0, 1>
        >::type::value, "");

        static_assert(equal_to<
            typename push_front<sequence<1, 2>, element<0>>::type,
            sequence<0, 1, 2>
        >::type::value, "");


        // pop_front
        static_assert(equal_to<
            typename pop_front<sequence<0>>::type,
            sequence<>
        >::type::value, "");

        static_assert(equal_to<
            typename pop_front<sequence<0, 1>>::type,
            sequence<1>
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

#endif // !BOOST_MPL11_TEST_FRONT_EXTENSIBLE_SEQUENCE_HPP
