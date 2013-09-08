/*!
 * @file
 * Defines `boost::mpl11::test::extensible_sequence`.
 */

#ifndef BOOST_MPL11_TEST_EXTENSIBLE_SEQUENCE_HPP
#define BOOST_MPL11_TEST_EXTENSIBLE_SEQUENCE_HPP

#include <boost/mpl11/algorithm/advance.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/insert_range.hpp>


namespace boost { namespace mpl11 {
namespace extensible_sequence_detail {
    using namespace intrinsic;
    using namespace algorithm;
    template <unsigned int>
    struct anything;

    template <template <typename ...> class Sequence,
              template <unsigned int> class A = anything>
    class extensible_sequence {
        using a0 = A<0>; using a1 = A<1>; using a2 = A<2>; using a3 = A<3>;
        using a4 = A<4>; using a5 = A<5>;

        using S = Sequence<a0, a1, a2, a3>;

        template <unsigned long i>
        using iter_at = typename advance_c<typename begin<S>::type, i>::type;

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
} // end namespace extensible_sequence_detail

namespace test { using extensible_sequence_detail::extensible_sequence; }
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_EXTENSIBLE_SEQUENCE_HPP
