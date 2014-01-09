/*!
 * @file
 * Defines `boost::mpl11::detail::iterable_test` and
 * `boost::mpl11::detail::minimal_iterable`.
 */

#ifndef BOOST_MPL11_DETAIL_ITERABLE_TEST_HPP
#define BOOST_MPL11_DETAIL_ITERABLE_TEST_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Generic unit test for finite iterables.
     *
     * To use `iterable_test`, simply instantiate it with the first
     * argument being the tested iterable and `Elements...` being the
     * expected contents of the iterable.
     */
    template <typename Iterable, typename ...Elements>
    struct iterable_test;

    /*!
     * @ingroup details
     *
     * Minimal iterable for testing purposes.
     *
     * When testing your own iterables, always use this iterable instead
     * of, say, `list`, because `list` could specialize some operations
     * for efficiency reasons. `minimal_iterable` is guaranteed not to
     * specialize anything unnecessary, i.e. to have the most default
     * behavior possible.
     */
    template <typename ...>
    struct minimal_iterable;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>
#include <boost/mpl11/fwd/iterable.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/list.hpp>


namespace boost { namespace mpl11 {
namespace detail {
    template <typename Iter, typename ...Elements>
    struct iterable_test {
        // head
        using Head = head_t<list<Elements...>>;
        static_assert(is_same<head_t<Iter>, Head>::value, "");

        // tail
        using Tail = tail_t<list<Elements...>>;
        static_assert(equal<tail_t<Iter>, Tail>::value, "");

        // init
        using Init = init_t<list<Elements...>>;
        static_assert(equal<init_t<Iter>, Init>::value, "");

        // last
        using Last = last_t<list<Elements...>>;
        static_assert(is_same<last_t<Iter>, Last>::value, "");

        // length
        static_assert(length<Iter>::value == sizeof...(Elements), "");

        // is_empty
        static_assert(is_empty<Iter>::value == !sizeof...(Elements), "");

        // unpack
        struct f { template <typename ...> struct apply { struct type; }; };
        static_assert(is_same<
            unpack_t<Iter, f>,
            typename f::template apply<Elements...>::type
        >::value, "");

        // at_c: we test indices in range [0, sizeof...(Elements-1)
        template <std_size_t Index, typename Dummy = void>
        struct test_at : test_at<Index - 1> {
            static_assert(is_same<
                at_c_t<Iter, Index>,
                at_c_t<list<Elements...>, Index>
            >::value, "");
        };

        template <typename Dummy>
        struct test_at<0, Dummy> {
            static_assert(is_same<
                at_c_t<Iter, 0>,
                at_c_t<list<Elements...>, 0>
            >::value, "");
        };

        static constexpr auto instantiate =
            sizeof(test_at<sizeof...(Elements) - 1>)
        ;
    };

    template <typename Iter>
    struct iterable_test<Iter> {
        static_assert(is_empty<Iter>::value, "");
        static_assert(length<Iter>::value == 0, "");
    };
} // end namespace detail

template <typename ...T>
struct tag_of<detail::minimal_iterable<T...>> {
    using type = iterable_tag;
};

template <typename ...T>
struct sequence_traits<detail::minimal_iterable<T...>> {
    static constexpr bool has_O1_length = false;
    static constexpr bool has_O1_unpack = false;
    static constexpr bool is_finite = true;
};

template <typename Head, typename ...Tail>
struct head_impl<detail::minimal_iterable<Head, Tail...>> {
    using type = Head;
};

template <typename Head, typename ...Tail>
struct tail_impl<detail::minimal_iterable<Head, Tail...>> {
    using type = detail::minimal_iterable<Tail...>;
};

template <typename ...T>
struct is_empty_impl<detail::minimal_iterable<T...>>
    : bool_<sizeof...(T) == 0>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_ITERABLE_TEST_HPP
