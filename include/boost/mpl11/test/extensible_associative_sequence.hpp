/*!
 * @file
 * Defines `boost::mpl11::test::extensible_associative_sequence`.
 */

#ifndef BOOST_MPL11_TEST_EXTENSIBLE_ASSOCIATIVE_SEQUENCE_HPP
#define BOOST_MPL11_TEST_EXTENSIBLE_ASSOCIATIVE_SEQUENCE_HPP

#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/erase_key.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/insert_range.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


namespace boost { namespace mpl11 {
namespace extensible_associative_sequence_detail {
    using namespace intrinsic;
    template <unsigned int>
    struct anything;

    template <template <typename ...> class Sequence,
              template <unsigned int> class A = anything>
    class extensible_associative_sequence {
        using a0 = A<0>; using a1 = A<1>; using a2 = A<2>;

        // insert
        static_assert(equal_to<
            typename insert<Sequence<>, a0>::type,
            Sequence<a0>
        >::type::value, "");

        static_assert(equal_to<
            typename insert<Sequence<a0>, a1>::type,
            Sequence<a0, a1>
        >::type::value, "");

        static_assert(equal_to<
            typename insert<Sequence<a0, a1>, a2>::type,
            Sequence<a0, a1, a2>
        >::type::value, "");

        static_assert(equal_to<
            typename insert<Sequence<a0, a1>, a0>::type,
            Sequence<a0, a1>
        >::type::value, "");

        static_assert(equal_to<
            typename insert<Sequence<a0, a1>, a1>::type,
            Sequence<a0, a1>
        >::type::value, "");


        // insert_range
        static_assert(equal_to<
            typename insert_range<Sequence<>, Sequence<>>::type,
            Sequence<>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<Sequence<>, Sequence<a0>>::type,
            Sequence<a0>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<Sequence<>, Sequence<a0, a1>>::type,
            Sequence<a0, a1>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<Sequence<>, Sequence<a0, a0>>::type,
            Sequence<a0>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<Sequence<a0>, Sequence<a0>>::type,
            Sequence<a0>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<Sequence<a0>, Sequence<a0, a1>>::type,
            Sequence<a0, a1>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<Sequence<a1>, Sequence<a0, a1>>::type,
            Sequence<a0, a1>
        >::type::value, "");

        static_assert(equal_to<
            typename insert_range<Sequence<a0>, Sequence<a1, a2>>::type,
            Sequence<a0, a1, a2>
        >::type::value, "");


        // erase_key
        static_assert(equal_to<
            typename erase_key<
                Sequence<a0>,
                typename key_of<Sequence<a0>, a0>::type
            >::type,
            Sequence<>
        >::type::value, "");

        static_assert(equal_to<
            typename erase_key<
                Sequence<a0, a1>,
                typename key_of<Sequence<a0, a1>, a0>::type
            >::type,
            Sequence<a1>
        >::type::value, "");

        static_assert(equal_to<
            typename erase_key<
                Sequence<a0, a1>,
                typename key_of<Sequence<a0, a1>, a1>::type
            >::type,
            Sequence<a0>
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
} // end namespace extensible_associative_sequence_detail

namespace test {
    using extensible_associative_sequence_detail::
                    extensible_associative_sequence;
}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_EXTENSIBLE_ASSOCIATIVE_SEQUENCE_HPP
