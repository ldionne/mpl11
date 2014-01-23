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

    template <typename ...>
    struct minimal_iterable_impl;

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
    template <typename ...T>
    struct minimal_iterable { using type = minimal_iterable_impl<T...>; };
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/iterable.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
namespace iterable_test_detail {
    template <typename> struct Expected;
    template <typename> struct Actual;

    template <
        typename X, typename Y,
        typename = Expected<typename X::type>,
        typename = Actual<typename Y::type>
    >
    struct assert_equal { static_assert(equal<X, Y>::value, ""); };
} // end namespace iterable_test_detail

namespace detail {
    template <typename Iter, typename ...Elements>
    struct iterable_test {
        using Reference = minimal_iterable<Elements...>;

        // at_c: we test indices in range [0, sizeof...(Elements) - 1)
        template <std_size_t Index, typename Dummy = void>
        struct test_at : test_at<Index - 1> {
            static_assert(equal<
                at_c<Iter, Index>,
                at_c<Reference, Index>
            >::value, "");
        };

        template <typename Dummy>
        struct test_at<0, Dummy> {
            static_assert(equal<
                at_c<Iter, 0>,
                at_c<Reference, 0>
            >::value, "");
        };

        template <typename ...Args>
        using assert_equal = iterable_test_detail::assert_equal<Args...>;

        // head, tail, init, last, unpack, at, is_empty, length
        static constexpr auto instantiate = 0
            + sizeof(assert_equal<head<Reference>, head<Iter>>)
            + sizeof(assert_equal<tail<Reference>, tail<Iter>>)
            + sizeof(assert_equal<init<Reference>, init<Iter>>)
            + sizeof(assert_equal<last<Reference>, last<Iter>>)
            + sizeof(assert_equal<
                        unpack<Reference, quote<minimal_iterable>>,
                        unpack<Iter, quote<minimal_iterable>>
                    >)
            + sizeof(assert_equal<length<Reference>,   length<Iter>>)
            + sizeof(assert_equal<is_empty<Reference>, is_empty<Iter>>)
            + sizeof(test_at<sizeof...(Elements) - 1>)
        ;
    };

    template <typename Iter>
    struct iterable_test<Iter>
        : iterable_test_detail::assert_equal<true_, is_empty<Iter>>,
          iterable_test_detail::assert_equal<size_t<0>, length<Iter>>
    { };

    struct minimal_iterable_tag;
} // end namespace detail

template <typename ...T>
struct tag_of<detail::minimal_iterable_impl<T...>> {
    using type = detail::minimal_iterable_tag;
};

template <typename ...T>
struct sequence_traits<detail::minimal_iterable_impl<T...>> {
    static constexpr bool has_O1_length = false;
    static constexpr bool has_O1_unpack = false;
    static constexpr bool is_finite = true;
};

template <typename Tag>
struct Comparable<detail::minimal_iterable_tag, Tag>
    : Comparable<iterable_tag, Tag>
{ };

template <typename Tag>
struct Orderable<detail::minimal_iterable_tag, Tag>
    : Orderable<iterable_tag, Tag>
{ };

template <>
struct Foldable<detail::minimal_iterable_tag>
    : Foldable<iterable_tag>
{ };

template <>
struct Functor<detail::minimal_iterable_tag>
    : Functor<iterable_tag>
{ };

template <>
struct Iterable<detail::minimal_iterable_tag> : Iterable<iterable_tag> {
    template <typename> struct head_impl;
    template <typename> struct tail_impl;
    template <typename> struct is_empty_impl;

    template <typename Head, typename ...Tail>
    struct head_impl<detail::minimal_iterable_impl<Head, Tail...>>
        : Head
    { };

    template <typename Head, typename ...Tail>
    struct tail_impl<detail::minimal_iterable_impl<Head, Tail...>>
        : detail::minimal_iterable<Tail...>
    { };

    template <typename ...T>
    struct is_empty_impl<detail::minimal_iterable_impl<T...>>
        : bool_<sizeof...(T) == 0>
    { };
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_ITERABLE_TEST_HPP
