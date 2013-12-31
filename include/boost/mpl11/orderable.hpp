/*!
 * @file
 * Defines `boost::mpl11::Orderable`.
 */

#ifndef BOOST_MPL11_ORDERABLE_HPP
#define BOOST_MPL11_ORDERABLE_HPP

#include <boost/mpl11/fwd/orderable.hpp>

#include <boost/mpl11/detail/comparison_operator.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults {
        struct Orderable {
            template <typename L, typename R>
            using less_equal_impl = not_<less<R, L>>;

            template <typename L, typename R>
            using greater_impl = less<R, L>;

            template <typename L, typename R>
            using greater_equal_impl = not_<less<L, R>>;
        };
    } // end namespace defaults

    namespace detail {
        template <typename TagL, typename TagR>
        struct flip_Orderable {
            template <typename L, typename R>
            using less_impl = typename Orderable<TagR, TagL>::
                              template less_impl<R, L>;

            template <typename L, typename R>
            using less_equal_impl = typename Orderable<TagR, TagL>::
                                    template less_equal_impl<R, L>;

            template <typename L, typename R>
            using greater_impl = typename Orderable<TagR, TagL>::
                                 template greater_impl<R, L>;

            template <typename L, typename R>
            using greater_equal_impl = typename Orderable<TagR, TagL>::
                                       template greater_equal_impl<R, L>;
        };

        template <>
        struct comparison_operator<true, less> {
            template <typename T1, typename T2>
            using apply = typename Orderable<
                typename tag_of<T1>::type, typename tag_of<T2>::type
            >::template less_impl<T1, T2>;
        };

        template <>
        struct comparison_operator<true, less_equal> {
            template <typename T1, typename T2>
            using apply = typename Orderable<
                typename tag_of<T1>::type, typename tag_of<T2>::type
            >::template less_equal_impl<T1, T2>;
        };

        template <>
        struct comparison_operator<true, greater> {
            template <typename T1, typename T2>
            using apply = typename Orderable<
                typename tag_of<T1>::type, typename tag_of<T2>::type
            >::template greater_impl<T1, T2>;
        };

        template <>
        struct comparison_operator<true, greater_equal> {
            template <typename T1, typename T2>
            using apply = typename Orderable<
                typename tag_of<T1>::type, typename tag_of<T2>::type
            >::template greater_equal_impl<T1, T2>;
        };
    } // end namespace detail

    template <typename T1, typename T2, typename ...Tn>
    struct less
        : detail::comparison_operator<sizeof...(Tn) == 0, less>::
            template apply<T1, T2, Tn...>
    { };

    template <typename T1, typename T2, typename ...Tn>
    struct less_equal
        : detail::comparison_operator<sizeof...(Tn) == 0, less_equal>::
            template apply<T1, T2, Tn...>
    { };

    template <typename T1, typename T2, typename ...Tn>
    struct greater
        : detail::comparison_operator<sizeof...(Tn) == 0, greater>::
            template apply<T1, T2, Tn...>
    { };

    template <typename T1, typename T2, typename ...Tn>
    struct greater_equal
        : detail::comparison_operator<sizeof...(Tn) == 0, greater_equal>::
            template apply<T1, T2, Tn...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_HPP
