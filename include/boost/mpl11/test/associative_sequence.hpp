/*!
 * @file
 * Defines `boost::mpl11::test::associative_sequence`.
 */

#ifndef BOOST_MPL11_TEST_ASSOCIATIVE_SEQUENCE_HPP
#define BOOST_MPL11_TEST_ASSOCIATIVE_SEQUENCE_HPP

#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/intrinsic/has_key.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/intrinsic/value_of.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/test/forward_sequence.hpp>


namespace boost { namespace mpl11 {
namespace associative_sequence_detail {
    using namespace intrinsic;
    template <unsigned int>
    struct anything;

    template <template <typename ...> class Sequence,
              template <unsigned int> class A = anything>
    class associative_sequence : test::forward_sequence<Sequence, A> {
        using a0 = A<0>; using a1 = A<1>; using a2 = A<2>;

        // equal_to
        static_assert(equal_to<
            Sequence<a0, a1>,
            Sequence<a1, a0>
        >::type::value, "");

        static_assert(equal_to<
            Sequence<a0, a1, a2>,
            Sequence<a2, a1, a0>
        >::type::value, "");


        // has_key
        static_assert(!has_key<
            Sequence<>,
            typename key_of<Sequence<>, a0>::type
        >::type::value, "");

        static_assert(!has_key<
            Sequence<a1>,
            typename key_of<Sequence<a1>, a0>::type
        >::type::value, "");

        static_assert(!has_key<
            Sequence<a1, a2>,
            typename key_of<Sequence<a1, a2>, a0>::type
        >::type::value, "");

        static_assert(has_key<
            Sequence<a0>,
            typename key_of<Sequence<a0>, a0>::type
        >::type::value, "");

        static_assert(has_key<
            Sequence<a0, a1>,
            typename key_of<Sequence<a0, a1>, a0>::type
        >::type::value, "");

        static_assert(has_key<
            Sequence<a0, a1>,
            typename key_of<Sequence<a0, a1>, a1>::type
        >::type::value, "");

        static_assert(has_key<
            Sequence<a0, a1, a2>,
            typename key_of<Sequence<a0, a1, a2>, a1>::type
        >::type::value, "");


        // at with a default
        static_assert(equal_to<
            typename at<
                Sequence<>,
                typename key_of<Sequence<>, a0>::type,
                struct Default
            >::type,
            struct Default
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<a0>,
                typename key_of<Sequence<a0>, a1>::type,
                struct Default
            >::type,
            struct Default
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<a0, a1>,
                typename key_of<Sequence<a0, a1>, a2>::type,
                struct Default
            >::type,
            struct Default
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<a0>,
                typename key_of<Sequence<a0>, a0>::type,
                struct Default
            >::type,
            typename value_of<Sequence<a0>, a0>::type
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<a0, a1>,
                typename key_of<Sequence<a0, a1>, a0>::type,
                struct Default
            >::type,
            typename value_of<Sequence<a0, a1>, a0>::type
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<a0, a1>,
                typename key_of<Sequence<a0, a1>, a1>::type,
                struct Default
            >::type,
            typename value_of<Sequence<a0, a1>, a1>::type
        >::type::value, "");

        // at without a default
        static_assert(equal_to<
            typename at<
                Sequence<a0>,
                typename key_of<Sequence<a0>, a0>::type
            >::type,
            typename value_of<Sequence<a0>, a0>::type
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<a0, a1>,
                typename key_of<Sequence<a0, a1>, a0>::type
            >::type,
            typename value_of<Sequence<a0, a1>, a0>::type
        >::type::value, "");

        static_assert(equal_to<
            typename at<
                Sequence<a0, a1>,
                typename key_of<Sequence<a0, a1>, a1>::type
            >::type,
            typename value_of<Sequence<a0, a1>, a1>::type
        >::type::value, "");
    };
} // end namespace associative_sequence_detail

namespace test { using associative_sequence_detail::associative_sequence; }
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_ASSOCIATIVE_SEQUENCE_HPP
