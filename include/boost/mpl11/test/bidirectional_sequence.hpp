/*!
 * @file
 * Defines `boost::mpl11::test::bidirectional_sequence`.
 */

#ifndef BOOST_MPL11_TEST_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_TEST_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/back.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/prior.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/test/forward_sequence.hpp>


namespace boost { namespace mpl11 { namespace test {
    template <typename MakeSequence, typename MakeElement = quote<inherit>>
    class bidirectional_sequence
        : forward_sequence<MakeSequence, MakeElement>
    {
        template <unsigned int i>
        using element = typename apply<MakeElement, uint<i>>::type;

        template <unsigned int ...i>
        using sequence = typename apply<MakeSequence, element<i>...>::type;

        // back
        static_assert(equal_to<
            typename back<sequence<0>>::type,
            element<0>
        >::type::value, "");

        static_assert(equal_to<
            typename back<sequence<0, 1>>::type,
            element<1>
        >::type::value, "");

        static_assert(equal_to<
            typename back<sequence<0, 1, 2>>::type,
            element<2>
        >::type::value, "");


        // prior
        static_assert(equal_to<
            typename prior<typename end<sequence<0>>::type>::type,
            typename begin<sequence<0>>::type
        >::type::value, "");
    };
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_BIDIRECTIONAL_SEQUENCE_HPP
