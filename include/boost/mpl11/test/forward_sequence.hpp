/*!
 * @file
 * Defines `boost::mpl11::test::forward_sequence`.
 */

#ifndef BOOST_MPL11_TEST_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_TEST_FORWARD_SEQUENCE_HPP

#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/front.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/operator/not_equal_to.hpp>


namespace boost { namespace mpl11 {
namespace forward_sequence_detail {
    using namespace intrinsic;
    template <unsigned int>
    struct anything;

    template <template <typename ...> class Sequence,
              template <unsigned int> class A = anything>
    class forward_sequence {
        using a0 = A<0>; using a1 = A<1>; using a2 = A<2>;

        // equal_to
        static_assert(equal_to<
            Sequence<>,
            Sequence<>
        >::type::value, "");

        static_assert(equal_to<
            Sequence<a0>,
            Sequence<a0>
        >::type::value, "");

        static_assert(equal_to<
            Sequence<a0, a1>,
            Sequence<a0, a1>
        >::type::value, "");


        // not_equal_to
        static_assert(not_equal_to<
            Sequence<a0>,
            Sequence<>
        >::type::value, "");

        static_assert(not_equal_to<
            Sequence<a0>,
            Sequence<a1>
        >::type::value, "");


        // begin/end
        static_assert(equal_to<
            typename begin<Sequence<>>::type,
            typename end<Sequence<>>::type
        >::type::value, "");

        static_assert(not_equal_to<
            typename begin<Sequence<a0>>::type,
            typename end<Sequence<a0>>::type
        >::type::value, "");

        static_assert(not_equal_to<
            typename end<Sequence<a0>>::type,
            typename end<Sequence<>>::type
        >::type::value, "");


        // size
        static_assert(size<Sequence<>>::type::value == 0, "");
        static_assert(size<Sequence<a0>>::type::value == 1, "");
        static_assert(size<Sequence<a0, a1>>::type::value == 2, "");


        // is_empty
        static_assert(is_empty<Sequence<>>::type::value, "");
        static_assert(!is_empty<Sequence<a0>>::type::value, "");
        static_assert(!is_empty<Sequence<a0, a1>>::type::value, "");


        // front
        static_assert(equal_to<
            typename front<Sequence<a0>>::type,
            a0
        >::type::value, "");

        static_assert(equal_to<
            typename front<Sequence<a0, a1>>::type,
            a0
        >::type::value, "");

        static_assert(equal_to<
            typename front<Sequence<a0, a1, a2>>::type,
            a0
        >::type::value, "");


        // next
        static_assert(equal_to<
            typename next<typename begin<Sequence<a0>>::type>::type,
            typename end<Sequence<a0>>::type
        >::type::value, "");


        // deref
        static_assert(equal_to<
            typename deref<typename begin<Sequence<a0>>::type>::type,
            a0
        >::type::value, "");
    };
} // end namespace forward_sequence_detail

namespace test { using forward_sequence_detail::forward_sequence; }
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_FORWARD_SEQUENCE_HPP
