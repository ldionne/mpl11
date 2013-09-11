/*!
 * @file
 * Defines `boost::mpl11::test::back_extensible_sequence`.
 */

#ifndef BOOST_MPL11_TEST_BACK_EXTENSIBLE_SEQUENCE_HPP
#define BOOST_MPL11_TEST_BACK_EXTENSIBLE_SEQUENCE_HPP

#include <boost/mpl11/intrinsic/pop_back.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/test/extensible_sequence.hpp>


namespace boost { namespace mpl11 {
namespace back_extensible_sequence_detail {
    using namespace intrinsic;
    template <unsigned int>
    struct anything;

    template <template <typename ...> class Sequence,
              template <unsigned int> class A = anything>
    class back_extensible_sequence : test::extensible_sequence<Sequence, A> {
        using a0 = A<0>; using a1 = A<1>; using a2 = A<2>;

        // push_back
        static_assert(equal_to<
            typename push_back<Sequence<>, a0>::type,
            Sequence<a0>
        >::type::value, "");

        static_assert(equal_to<
            typename push_back<Sequence<a0>, a1>::type,
            Sequence<a0, a1>
        >::type::value, "");

        static_assert(equal_to<
            typename push_back<Sequence<a0, a1>, a2>::type,
            Sequence<a0, a1, a2>
        >::type::value, "");


        // pop_back
        static_assert(equal_to<
            typename pop_back<Sequence<a0>>::type,
            Sequence<>
        >::type::value, "");

        static_assert(equal_to<
            typename pop_back<Sequence<a0, a1>>::type,
            Sequence<a0>
        >::type::value, "");
    };
} // end namespace back_extensible_sequence_detail

namespace test {
    using back_extensible_sequence_detail::back_extensible_sequence;
}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_BACK_EXTENSIBLE_SEQUENCE_HPP
