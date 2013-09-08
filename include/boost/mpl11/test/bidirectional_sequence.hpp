/*!
 * @file
 * Defines `boost::mpl11::test::bidirectional_sequence`.
 */

#ifndef BOOST_MPL11_TEST_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_TEST_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/intrinsic/back.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/test/forward_sequence.hpp>


namespace boost { namespace mpl11 {
namespace bidirectional_sequence_detail {
    using namespace intrinsic;
    template <unsigned int>
    struct anything;

    template <template <typename ...> class Sequence,
              template <unsigned int> class A = anything>
    class bidirectional_sequence : test::forward_sequence<Sequence, A> {
        using a0 = A<0>; using a1 = A<1>; using a2 = A<2>;

        // back
        static_assert(equal_to<
            typename back<Sequence<a0>>::type,
            a0
        >::type::value, "");

        static_assert(equal_to<
            typename back<Sequence<a0, a1>>::type,
            a1
        >::type::value, "");

        static_assert(equal_to<
            typename back<Sequence<a0, a1, a2>>::type,
            a2
        >::type::value, "");


        // prior
        static_assert(equal_to<
            typename prior<typename end<Sequence<a0>>::type>::type,
            typename begin<Sequence<a0>>::type
        >::type::value, "");
    };
} // end namespace bidirectional_sequence_detail

namespace test { using bidirectional_sequence_detail::bidirectional_sequence; }
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_BIDIRECTIONAL_SEQUENCE_HPP
