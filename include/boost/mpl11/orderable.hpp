/*!
 * @file
 * Defines the @ref Orderable typeclass.
 */

#ifndef BOOST_MPL11_ORDERABLE_HPP
#define BOOST_MPL11_ORDERABLE_HPP

#include <boost/mpl11/fwd/orderable.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/detail/box.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/detail/strict_variadic_foldl.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
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

            template <typename L, typename R>
            using min_impl = typename Orderable<TagR, TagL>::
                             template min_impl<R, L>;

            template <typename L, typename R>
            using max_impl = typename Orderable<TagR, TagL>::
                             template max_impl<R, L>;
        };
    } // end namespace detail

    template <>
    struct Orderable<orderable_tag, orderable_tag> {
        template <typename L, typename R>
        using less_equal_impl = not_<less<detail::box<R>, detail::box<L>>>;

        template <typename L, typename R>
        using greater_impl = less<detail::box<R>, detail::box<L>>;

        template <typename L, typename R>
        using greater_equal_impl = not_<less<detail::box<L>, detail::box<R>>>;

        template <typename L, typename R>
        using min_impl = detail::conditional<
            less<detail::box<L>, detail::box<R>>::value, L, R
        >;

        template <typename L, typename R>
        using max_impl = detail::conditional<
            less<detail::box<L>, detail::box<R>>::value, R, L
        >;
    };


    template <typename T1, typename T2, typename ...Tn>
    struct less
        : and_<less<T1, T2>, less<T2, Tn...>>
    { };

    template <typename T1, typename T2>
    struct less<T1, T2>
        : Orderable<
            typename tag_of<typename T1::type>::type,
            typename tag_of<typename T2::type>::type
        >::template less_impl<typename T1::type, typename T2::type>
    { };


    template <typename T1, typename T2, typename ...Tn>
    struct less_equal
        : and_<less_equal<T1, T2>, less_equal<T2, Tn...>>
    { };

    template <typename T1, typename T2>
    struct less_equal<T1, T2>
        : Orderable<
            typename tag_of<typename T1::type>::type,
            typename tag_of<typename T2::type>::type
        >::template less_equal_impl<typename T1::type, typename T2::type>
    { };


    template <typename T1, typename T2, typename ...Tn>
    struct greater
        : and_<greater<T1, T2>, greater<T2, Tn...>>
    { };

    template <typename T1, typename T2>
    struct greater<T1, T2>
        : Orderable<
            typename tag_of<typename T1::type>::type,
            typename tag_of<typename T2::type>::type
        >::template greater_impl<typename T1::type, typename T2::type>
    { };


    template <typename T1, typename T2, typename ...Tn>
    struct greater_equal
        : and_<greater_equal<T1, T2>, greater_equal<T2, Tn...>>
    { };

    template <typename T1, typename T2>
    struct greater_equal<T1, T2>
        : Orderable<
            typename tag_of<typename T1::type>::type,
            typename tag_of<typename T2::type>::type
        >::template greater_equal_impl<typename T1::type, typename T2::type>
    { };


    template <typename T1, typename T2, typename ...Tn>
    struct min
        : detail::strict_variadic_foldl<quote<min>, T1, T2, Tn...>
    { };

    template <typename T1, typename T2>
    struct min<T1, T2>
        : Orderable<
            typename tag_of<typename T1::type>::type,
            typename tag_of<typename T2::type>::type
        >::template min_impl<typename T1::type, typename T2::type>
    { };


    template <typename T1, typename T2, typename ...Tn>
    struct max
        : detail::strict_variadic_foldl<quote<max>, T1, T2, Tn...>
    { };

    template <typename T1, typename T2>
    struct max<T1, T2>
        : Orderable<
            typename tag_of<typename T1::type>::type,
            typename tag_of<typename T2::type>::type
        >::template max_impl<typename T1::type, typename T2::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_HPP
