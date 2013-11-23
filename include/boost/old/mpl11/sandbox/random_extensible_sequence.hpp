/*!
 * @file
 * Defines `boost::mpl11::test::random_extensible_sequence`.
 */

#ifndef BOOST_MPL11_TEST_RANDOM_EXTENSIBLE_SEQUENCE_HPP
#define BOOST_MPL11_TEST_RANDOM_EXTENSIBLE_SEQUENCE_HPP

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/erase.hpp>
#include <boost/mpl11/insert.hpp>
#include <boost/mpl11/insert_range.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/test/back_extensible_sequence.hpp>
#include <boost/mpl11/test/front_extensible_sequence.hpp>


namespace boost { namespace mpl11 { namespace test {
    template <typename MakeSequence, typename MakeElement = quote<inherit>>
    class random_extensible_sequence
        : back_extensible_sequence<MakeSequence, MakeElement>,
          front_extensible_sequence<MakeSequence, MakeElement>
    {
        template <unsigned int i>
        using element = typename apply<MakeElement, uint<i>>::type;

        template <typename ...Elements>
        using Sequence = typename apply<MakeSequence, Elements...>::type;

        using a0 = element<0>;
        using a1 = element<1>;
        using a2 = element<2>;
        using a3 = element<3>;
        using a4 = element<4>;
        using a5 = element<5>;

        using S = Sequence<a0, a1, a2, a3>;

        template <unsigned int i>
        using iter_at = typename algorithm::advance_c<
            typename begin<S>::type, i
        >::type;

        // insert
        static_assert(equal_to<
            typename insert<S, iter_at<0>, a4>::type,
            Sequence<a4, a0, a1, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename insert<S, iter_at<1>, a4>::type,
            Sequence<a0, a4, a1, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename insert<S, iter_at<2>, a4>::type,
            Sequence<a0, a1, a4, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename insert<S, iter_at<3>, a4>::type,
            Sequence<a0, a1, a2, a4, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename insert<S, iter_at<4>, a4>::type,
            Sequence<a0, a1, a2, a3, a4>
        >::type::value, "");


        // insert_range
        static_assert(equal_to<
            typename insert_range<S, iter_at<0>, Sequence<a4, a5>>::type,
            Sequence<a4, a5, a0, a1, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<S, iter_at<1>, Sequence<a4, a5>>::type,
            Sequence<a0, a4, a5, a1, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<S, iter_at<2>, Sequence<a4, a5>>::type,
            Sequence<a0, a1, a4, a5, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<S, iter_at<3>, Sequence<a4, a5>>::type,
            Sequence<a0, a1, a2, a4, a5, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<S, iter_at<4>, Sequence<a4, a5>>::type,
            Sequence<a0, a1, a2, a3, a4, a5>
        >::type::value, "");


        // erase a single element
        static_assert(equal_to<
            typename erase<S, iter_at<0>>::type,
            Sequence<a1, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename erase<S, iter_at<1>>::type,
            Sequence<a0, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename erase<S, iter_at<2>>::type,
            Sequence<a0, a1, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename erase<S, iter_at<3>>::type,
            Sequence<a0, a1, a2>
        >::type::value, "");

        // erase with a range of iterators
        static_assert(equal_to<
            typename erase<S, iter_at<0>, iter_at<1>>::type,
            Sequence<a1, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename erase<S, iter_at<0>, iter_at<2>>::type,
            Sequence<a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename erase<S, iter_at<0>, iter_at<3>>::type,
            Sequence<a3>
        >::type::value, "");

        static_assert(equal_to<
            typename erase<S, iter_at<0>, iter_at<4>>::type,
            Sequence<>
        >::type::value, "");


        // erase with an empty range of iterators
        static_assert(equal_to<
            typename erase<S, iter_at<0>, iter_at<0>>::type,
            Sequence<a0, a1, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename erase<S, iter_at<1>, iter_at<1>>::type,
            Sequence<a0, a1, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename erase<S, iter_at<2>, iter_at<2>>::type,
            Sequence<a0, a1, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename erase<S, iter_at<3>, iter_at<3>>::type,
            Sequence<a0, a1, a2, a3>
        >::type::value, "");

        static_assert(equal_to<
            typename erase<S, iter_at<4>, iter_at<4>>::type,
            Sequence<a0, a1, a2, a3>
        >::type::value, "");


        // clear
        static_assert(equal_to<
            typename clear<Sequence<>>::type,
            Sequence<>
        >::type::value, "");

        static_assert(equal_to<
            typename clear<Sequence<a0>>::type,
            Sequence<>
        >::type::value, "");

        static_assert(equal_to<
            typename clear<Sequence<a0, a1>>::type,
            Sequence<>
        >::type::value, "");
    };
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_RANDOM_EXTENSIBLE_SEQUENCE_HPP
