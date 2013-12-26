/*!
 * @file
 * Defines `boost::mpl11::Comparable`.
 */

#ifndef BOOST_MPL11_COMPARABLE_HPP
#define BOOST_MPL11_COMPARABLE_HPP

#include <boost/mpl11/fwd/comparable.hpp>

#include <boost/mpl11/detail/comparison_operator.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults {
        struct Comparable {
            template <typename L, typename R>
            using equal_impl = not_<not_equal<L, R>>;

            template <typename L, typename R>
            using not_equal_impl = not_<equal<L, R>>;
        };
    } // end namespace defaults

    namespace detail {
        template <typename TagL, typename TagR>
        struct flip_Comparable {
            template <typename L, typename R>
            using equal_impl = typename Comparable<TagR, TagL>::
                               template equal_impl<R, L>;

            template <typename L, typename R>
            using not_equal_impl = typename Comparable<TagR, TagL>::
                                   template not_equal_impl<R, L>;
        };

        template <>
        struct comparison_operator<true, equal> {
            template <typename T1, typename T2>
            using apply = typename Comparable<
                typename tag_of<T1>::type, typename tag_of<T2>::type
            >::template equal_impl<T1, T2>;
        };

        template <>
        struct comparison_operator<true, not_equal> {
            template <typename T1, typename T2>
            using apply = typename Comparable<
                typename tag_of<T1>::type, typename tag_of<T2>::type
            >::template not_equal_impl<T1, T2>;
        };
    } // end namespace detail

    template <typename TagL, typename TagR>
    struct Comparable {
        template <typename L, typename R>
        using equal_impl = detail::is_same<L, R>;

        template <typename L, typename R>
        using not_equal_impl = detail::is_not_same<L, R>;
    };

    template <typename T1, typename T2, typename ...Tn>
    struct equal
        : detail::comparison_operator<sizeof...(Tn) == 0, equal>::
            template apply<T1, T2, Tn...>
    { };

    template <typename T1, typename T2, typename ...Tn>
    struct not_equal
        : detail::comparison_operator<sizeof...(Tn) == 0, not_equal>::
            template apply<T1, T2, Tn...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_HPP
