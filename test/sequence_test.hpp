/*!
 * @file
 * Generic unit test for sequences.
 */

#ifndef BOOST_MPL11_TEST_SEQUENCE_TEST_HPP
#define BOOST_MPL11_TEST_SEQUENCE_TEST_HPP

#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/fwd/bidirectional_sequence.hpp>
#include <boost/mpl11/fwd/finite_sequence.hpp>
#include <boost/mpl11/fwd/forward_sequence.hpp>
#include <boost/mpl11/fwd/random_access_sequence.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/vector.hpp>


namespace mpl11_test {

using namespace boost::mpl11;
using detail::is_same;

template <typename Sequence, typename ...Elements>
struct forward_sequence_test;

template <typename Sequence, typename Head, typename ...Tail>
struct forward_sequence_test<Sequence, Head, Tail...> {
    static_assert(is_same<head_t<Sequence>, Head>::value, "");
    static_assert(equal<tail_t<Sequence>, vector<Tail...>>::value, "");
};

template <typename Sequence>
struct forward_sequence_test<Sequence> {
    static_assert(is_empty<Sequence>::value, "");
};



template <typename Sequence, typename ...Elements>
struct finite_sequence_test {
    static_assert(length<Sequence>::value == sizeof...(Elements), "");

    struct f { template <typename ...> struct apply { struct type; }; };
    static_assert(is_same<
        unpack_t<Sequence, f>,
        typename f::template apply<Elements...>::type
    >::value, "");
};


template <typename Sequence, typename ...Elements>
struct bidirectional_sequence_test {
    using Init = init_t<vector<Elements...>>;
    using Last = last_t<vector<Elements...>>;

    static_assert(is_same<last_t<Sequence>, Last>::value, "");
    static_assert(equal<init_t<Sequence>, Init>::value, "");
};

template <typename Sequence>
struct bidirectional_sequence_test<Sequence> { };



template <typename Sequence, typename ...Elements>
struct random_access_sequence_test {
    template <typename Index, typename Dummy = void>
    struct test_at : test_at<size_t<Index::value + 1>> {
        static_assert(is_same<
            at_t<Sequence, Index>,
            at_t<vector<Elements...>, Index>
        >::value, "");
    };

    template <typename Dummy>
    struct test_at<size_t<sizeof...(Elements) - 1>, Dummy> {
        static_assert(is_same<
            at_c_t<Sequence, sizeof...(Elements) - 1>,
            at_c_t<vector<Elements...>, sizeof...(Elements) - 1>
        >::value, "");
    };


    template <unsigned long Start, unsigned long Stop>
    struct test_slice_impl {
        static_assert(equal<
            slice_c_t<Sequence, Start, Stop>,
            slice_c_t<vector<Elements...>, Start, Stop>
        >::value, "");
    };

    template <typename Start, typename Stop, typename Dummy = void>
    struct test_slice
        : test_slice_impl<Start::value, Stop::value>,
          test_slice<Start, size_t<Stop::value + 1>>
    { };

    template <typename Dummy>
    struct test_slice<size_t<sizeof...(Elements)>, size_t<sizeof...(Elements)>, Dummy>
        : test_slice_impl<sizeof...(Elements), sizeof...(Elements)>
    { };

    template <typename Start, typename Dummy>
    struct test_slice<Start, size_t<sizeof...(Elements)>, Dummy>
        : test_slice_impl<Start::value, sizeof...(Elements)>,
          test_slice<size_t<Start::value + 1>, size_t<Start::value + 1>>
    { };

    static constexpr auto instantiate =
        sizeof(test_at<size_t<0>>) +
        sizeof(test_slice<size_t<0>, size_t<0>>)
    ;
};

template <typename Sequence>
struct random_access_sequence_test<Sequence> {
    static_assert(equal<slice_c_t<Sequence, 0, 0>, vector<>>::value, "");
};

} // end namespace mpl11_test

#endif // !BOOST_MPL11_TEST_SEQUENCE_TEST_HPP
