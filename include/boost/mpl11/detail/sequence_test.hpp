/*!
 * @file
 * Defines `boost::mpl11::detail::sequence_test`.
 */

#ifndef BOOST_MPL11_DETAIL_SEQUENCE_TEST_HPP
#define BOOST_MPL11_DETAIL_SEQUENCE_TEST_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Generic unit test for finite `Sequence`s.
     *
     * To use `sequence_test`, simply instantiate it with the first
     * argument being the tested sequence and `Elements...` being the
     * expected contents of the sequence.
     */
    template <typename Sequence, typename ...Elements>
    struct sequence_test;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/sequence.hpp>
#include <boost/mpl11/list.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename Sequence, typename ...Elements>
    struct sequence_test {
        // head
        using Head = head_t<list<Elements...>>;
        static_assert(is_same<head_t<Sequence>, Head>::value, "");

        // tail
        using Tail = tail_t<list<Elements...>>;
        static_assert(equal<tail_t<Sequence>, Tail>::value, "");

        // init
        using Init = init_t<list<Elements...>>;
        static_assert(equal<init_t<Sequence>, Init>::value, "");

        // last
        using Last = last_t<list<Elements...>>;
        static_assert(is_same<last_t<Sequence>, Last>::value, "");

        // length
        static_assert(length<Sequence>::value == sizeof...(Elements), "");

        // is_empty
        static_assert(is_empty<Sequence>::value == !sizeof...(Elements), "");

        // unpack
        struct f { template <typename ...> struct apply { struct type; }; };
        static_assert(is_same<
            unpack_t<Sequence, f>,
            typename f::template apply<Elements...>::type
        >::value, "");

        // at_c: we test indices in range [0, sizeof...(Elements-1)
        template <std_size_t Index, typename Dummy = void>
        struct test_at : test_at<Index - 1> {
            static_assert(is_same<
                at_c_t<Sequence, Index>,
                at_c_t<list<Elements...>, Index>
            >::value, "");
        };

        template <typename Dummy>
        struct test_at<0, Dummy> {
            static_assert(is_same<
                at_c_t<Sequence, 0>,
                at_c_t<list<Elements...>, 0>
            >::value, "");
        };

        static constexpr auto instantiate =
            sizeof(test_at<sizeof...(Elements) - 1>)
        ;
    };

    template <typename Sequence>
    struct sequence_test<Sequence> {
        static_assert(is_empty<Sequence>::value, "");
        static_assert(length<Sequence>::value == 0, "");
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_SEQUENCE_TEST_HPP
