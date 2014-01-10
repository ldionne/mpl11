/*!
 * @file
 * Defines `boost::mpl11::Comparable`.
 */

#ifndef BOOST_MPL11_COMPARABLE_HPP
#define BOOST_MPL11_COMPARABLE_HPP

#include <boost/mpl11/fwd/comparable.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
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
    } // end namespace detail

    namespace comparable_detail {
        struct Comparable_base {
            template <typename L, typename R>
            using equal_impl = detail::is_same<L, R>;

            template <typename L, typename R>
            using not_equal_impl = not_<detail::is_same<L, R>>;
        };
    } // end namespace comparable_detail

    template <typename TagL, typename TagR>
    struct Comparable : comparable_detail::Comparable_base { };

    template <>
    struct Comparable<comparable_tag, comparable_tag> {
        template <typename L, typename R>
        using equal_impl = not_<not_equal<L, R>>;

        template <typename L, typename R>
        using not_equal_impl = not_<equal<L, R>>;
    };

    template <typename T1, typename T2, typename ...Tn>
    struct equal
        : and_<equal<T1, T2>, equal<T2, Tn...>>
    { };

    template <typename T1, typename T2>
    struct equal<T1, T2>
        : Comparable<
            typename tag_of<T1>::type, typename tag_of<T2>::type
        >::template equal_impl<T1, T2>
    { };

    template <typename T1, typename T2, typename ...Tn>
    struct not_equal
        : and_<not_equal<T1, T2>, not_equal<T2, Tn...>>
    { };

    template <typename T1, typename T2>
    struct not_equal<T1, T2>
        : Comparable<
            typename tag_of<T1>::type, typename tag_of<T2>::type
        >::template not_equal_impl<T1, T2>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_HPP
