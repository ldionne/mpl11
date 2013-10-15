/*!
 * @file
 * Defines `BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR`.
 */

#ifndef BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP
#define BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP

#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


#define BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(NAME, OPERATOR)        \
namespace boost { namespace mpl11 {                                         \
    template <typename T1, typename T2>                                     \
    struct dispatch<tag::NAME, T1, T2>                                      \
        : dispatch<                                                         \
            tag::by_category<tag::NAME>,                                    \
            typename category_of<T1>::type                                  \
        >                                                                   \
    {                                                                       \
        static_assert(equal_to<                                             \
                        typename category_of<T1>::type,                     \
                        typename category_of<T2>::type                      \
                      >::type::value,                                       \
        "Trying to perform a left associative operation between "           \
        "two types with different categories.");                            \
    };                                                                      \
                                                                            \
    template <typename T1, typename T2>                                     \
    struct dispatch<tag::by_category<tag::NAME>,category::integral_constant>\
        : identity<                                                         \
            integral_c<                                                     \
                decltype((T1::value) OPERATOR (T2::value)),                 \
                (T1::value) OPERATOR (T2::value)                            \
            >                                                               \
        >                                                                   \
    { };                                                                    \
                                                                            \
    template <typename T1, typename T2, typename ...Tn>                     \
    struct dispatch<tag::NAME, T1, T2, Tn...>                               \
        : NAME<typename NAME<T1, T2>::type, Tn...>                          \
    { };                                                                    \
}} /* end namespace boost::mpl11 */                                         \
/**/

#endif // !BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP
