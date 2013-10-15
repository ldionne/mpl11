/*!
 * @file
 * Defines `BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR`.
 */

#ifndef BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP
#define BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP

#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


#define BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(NAME, OPERATOR)        \
    namespace boost { namespace mpl11 {                                     \
        namespace NAME ## _detail {                                         \
            template <typename Category1, typename T1,                      \
                      typename Category2, typename T2>                      \
            struct NAME ## _impl;                                           \
                                                                            \
            template <typename T1, typename T2>                             \
            struct NAME ## _impl<                                           \
                category::integral_constant, T1,                            \
                category::integral_constant, T2                             \
            >                                                               \
                : identity<                                                 \
                    integral_c<                                             \
                        decltype((T1::value) OPERATOR (T2::value)),         \
                        (T1::value) OPERATOR (T2::value)                    \
                    >                                                       \
                >                                                           \
            { };                                                            \
        } /* end namespace NAME ## _detail */                               \
                                                                            \
        template <typename T1, typename T2>                                 \
        struct dispatch<tag::default_<tag::NAME>, T1, T2>                   \
            : NAME ## _detail::NAME ## _impl<                               \
                typename detail::best_category_for<                         \
                    T1, category::integral_constant                         \
                >::type, T1,                                                \
                typename detail::best_category_for<                         \
                    T2, category::integral_constant                         \
                >::type, T2                                                 \
            >                                                               \
        { };                                                                \
                                                                            \
        template <typename T1, typename T2, typename ...Tn>                 \
        struct dispatch<tag::default_<tag::NAME>, T1, T2, Tn...>            \
            : NAME<typename NAME<T1, T2>::type, Tn...>                      \
        { };                                                                \
    }} /* end namespace boost::mpl11 */                                     \
/**/

#endif // !BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP
