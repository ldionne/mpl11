/*!
 * @file
 * Defines `boost::mpl11::test::associative_sequence`.
 */

#ifndef BOOST_MPL11_TEST_ASSOCIATIVE_SEQUENCE_HPP
#define BOOST_MPL11_TEST_ASSOCIATIVE_SEQUENCE_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/value_of.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/test/forward_sequence.hpp>


namespace boost { namespace mpl11 { namespace test {
    template <typename MakeSequence, typename MakeElement = quote<inherit>>
    class associative_sequence
        : forward_sequence<MakeSequence, MakeElement>
    {
        template <unsigned int i>
        using element = typename apply<MakeElement, uint<i>>::type;

        template <unsigned int ...i>
        using Sequence = typename apply<MakeSequence, element<i>...>::type;

        // equal_to
        static_assert(equal_to<
            Sequence<0, 1>,
            Sequence<1, 0>
        >::type::value, "");

        static_assert(equal_to<
            Sequence<0, 1, 2>,
            Sequence<2, 1, 0>
        >::type::value, "");


        // has_key
        static_assert(!has_key<
            Sequence<>,
            typename key_of<Sequence<>, element<0>>::type
        >::type::value, "");

        static_assert(!has_key<
            Sequence<1>,
            typename key_of<Sequence<1>, element<0>>::type
        >::type::value, "");

        static_assert(!has_key<
            Sequence<1, 2>,
            typename key_of<Sequence<1, 2>, element<0>>::type
        >::type::value, "");

        static_assert(has_key<
            Sequence<0>,
            typename key_of<Sequence<0>, element<0>>::type
        >::type::value, "");

        static_assert(has_key<
            Sequence<0, 1>,
            typename key_of<Sequence<0, 1>, element<0>>::type
        >::type::value, "");

        static_assert(has_key<
            Sequence<0, 1>,
            typename key_of<Sequence<0, 1>, element<1>>::type
        >::type::value, "");

        static_assert(has_key<
            Sequence<0, 1, 2>,
            typename key_of<Sequence<0, 1, 2>, element<1>>::type
        >::type::value, "");


        // at with a default
        static_assert(equal_to<
            typename at<
                Sequence<>,
                typename key_of<Sequence<>, element<0>>::type,
                struct Default
            >::type,
            struct Default
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<0>,
                typename key_of<Sequence<0>, element<1>>::type,
                struct Default
            >::type,
            struct Default
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<0, 1>,
                typename key_of<Sequence<0, 1>, element<2>>::type,
                struct Default
            >::type,
            struct Default
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<0>,
                typename key_of<Sequence<0>, element<0>>::type,
                struct Default
            >::type,
            typename value_of<Sequence<0>, element<0>>::type
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<0, 1>,
                typename key_of<Sequence<0, 1>, element<0>>::type,
                struct Default
            >::type,
            typename value_of<Sequence<0, 1>, element<0>>::type
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<0, 1>,
                typename key_of<Sequence<0, 1>, element<1>>::type,
                struct Default
            >::type,
            typename value_of<Sequence<0, 1>, element<1>>::type
        >::type::value, "");

        // at without a default
        static_assert(equal_to<
            typename at<
                Sequence<0>,
                typename key_of<Sequence<0>, element<0>>::type
            >::type,
            typename value_of<Sequence<0>, element<0>>::type
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<0, 1>,
                typename key_of<Sequence<0, 1>, element<0>>::type
            >::type,
            typename value_of<Sequence<0, 1>, element<0>>::type
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<0, 1>,
                typename key_of<Sequence<0, 1>, element<1>>::type
            >::type,
            typename value_of<Sequence<0, 1>, element<1>>::type
        >::type::value, "");
    };
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_ASSOCIATIVE_SEQUENCE_HPP
