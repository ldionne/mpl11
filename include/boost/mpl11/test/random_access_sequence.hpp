/*!
 * @file
 * Defines `boost::mpl11::test::random_access_sequence`.
 */

#ifndef BOOST_MPL11_TEST_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_TEST_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/test/bidirectional_sequence.hpp>


namespace boost { namespace mpl11 {
namespace random_access_sequence_detail {
    using namespace intrinsic;
    template <unsigned int>
    struct anything;

    template <template <typename ...> class Sequence,
              template <unsigned int> class A = anything>
    class random_access_sequence : test::bidirectional_sequence<Sequence, A> {
        using a0 = A<0>; using a1 = A<1>; using a2 = A<2>;

        // at/at_c
        static_assert(equal_to<
            typename at_c<Sequence<a0>, 0>::type,
            a0
        >::type::value, "");

        static_assert(equal_to<
            typename at_c<Sequence<a0, a1>, 0>::type,
            a0
        >::type::value, "");

        static_assert(equal_to<
            typename at_c<Sequence<a0, a1>, 1>::type,
            a1
        >::type::value, "");

        static_assert(equal_to<
            typename at_c<Sequence<a0, a1, a2>, 2>::type,
            a2
        >::type::value, "");
    };
} // end namespace random_access_sequence_detail

namespace test { using random_access_sequence_detail::random_access_sequence; }
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_RANDOM_ACCESS_SEQUENCE_HPP
