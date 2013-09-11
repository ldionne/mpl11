/*!
 * @file
 * Defines `boost::mpl11::test::random_access_sequence`.
 */

#ifndef BOOST_MPL11_TEST_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_TEST_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/test/bidirectional_sequence.hpp>


namespace boost { namespace mpl11 { namespace test {
    template <typename MakeSequence, typename MakeElement = quote<inherit>>
    class random_access_sequence
        : bidirectional_sequence<MakeSequence, MakeElement>
    {
        template <unsigned int i>
        using element = typename apply<MakeElement, uint<i>>::type;

        template <unsigned int ...i>
        using sequence = typename apply<MakeSequence, element<i>...>::type;

        // at/at_c
        static_assert(equal_to<
            typename at_c<sequence<0>, 0>::type,
            element<0>
        >::type::value, "");

        static_assert(equal_to<
            typename at_c<sequence<0, 1>, 0>::type,
            element<0>
        >::type::value, "");

        static_assert(equal_to<
            typename at_c<sequence<0, 1>, 1>::type,
            element<1>
        >::type::value, "");

        static_assert(equal_to<
            typename at_c<sequence<0, 1, 2>, 2>::type,
            element<2>
        >::type::value, "");
    };
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_RANDOM_ACCESS_SEQUENCE_HPP
