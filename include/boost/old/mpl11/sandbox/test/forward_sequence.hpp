/*!
 * @file
 * Defines `boost::mpl11::test::forward_sequence`.
 */

#ifndef BOOST_MPL11_TEST_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_TEST_FORWARD_SEQUENCE_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/front.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/not_equal_to.hpp>


namespace boost { namespace mpl11 { namespace test {
    template <typename MakeSequence, typename MakeElement = quote<inherit>>
    class forward_sequence {
        template <unsigned int i>
        using element = typename apply<MakeElement, uint<i>>::type;

        template <unsigned int ...i>
        using sequence = typename apply<MakeSequence, element<i>...>::type;

        // equal_to
        static_assert(equal_to<
            forward_sequence::sequence<>,
            sequence<>
        >::type::value, "");

        static_assert(equal_to<
            sequence<0>,
            sequence<0>
        >::type::value, "");

        static_assert(equal_to<
            sequence<0, 1>,
            sequence<0, 1>
        >::type::value, "");


        // not_equal_to
        static_assert(not_equal_to<
            sequence<0>,
            sequence<>
        >::type::value, "");

        static_assert(not_equal_to<
            sequence<0>,
            sequence<1>
        >::type::value, "");


        // begin/end
        static_assert(equal_to<
            typename begin<sequence<>>::type,
            typename end<sequence<>>::type
        >::type::value, "");

        static_assert(not_equal_to<
            typename begin<sequence<0>>::type,
            typename end<sequence<0>>::type
        >::type::value, "");

        static_assert(not_equal_to<
            typename end<sequence<0>>::type,
            typename end<sequence<>>::type
        >::type::value, "");


        // size
        static_assert(size<sequence<>>::type::value == 0, "");
        static_assert(size<sequence<0>>::type::value == 1, "");
        static_assert(size<sequence<0, 1>>::type::value == 2, "");


        // is_empty
        static_assert(is_empty<sequence<>>::type::value, "");
        static_assert(!is_empty<sequence<0>>::type::value, "");
        static_assert(!is_empty<sequence<0, 1>>::type::value, "");


        // front
        static_assert(equal_to<
            typename front<sequence<0>>::type,
            element<0>
        >::type::value, "");

        static_assert(equal_to<
            typename front<sequence<0, 1>>::type,
            element<0>
        >::type::value, "");

        static_assert(equal_to<
            typename front<sequence<0, 1, 2>>::type,
            element<0>
        >::type::value, "");


        // next
        static_assert(equal_to<
            typename next<typename begin<sequence<0>>::type>::type,
            typename end<sequence<0>>::type
        >::type::value, "");


        // deref
        static_assert(equal_to<
            typename deref<typename begin<sequence<0>>::type>::type,
            element<0>
        >::type::value, "");
    };
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_FORWARD_SEQUENCE_HPP
