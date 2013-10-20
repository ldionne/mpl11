/*!
 * @file
 * Defines `BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR`.
 */

#ifndef BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP
#define BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP

#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/detail/dual_dispatch.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


#define BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(NAME, OPERATOR)        \
namespace boost { namespace mpl11 {                                         \
    template <typename T1, typename T2>                                     \
    struct dispatch<tag::NAME, T1, T2>                                      \
        : detail::dual_dispatch<tag::NAME, T1, T2>::template apply<T1, T2>  \
    { };                                                                    \
                                                                            \
    template <>                                                             \
    struct dispatch<                                                        \
        tag::dual<tag::NAME>,                                               \
        category::integral_constant,                                        \
        category::integral_constant                                         \
    > {                                                                     \
        template <typename I, typename J>                                   \
        struct apply                                                        \
            : identity<                                                     \
                integral_c<                                                 \
                    decltype((I::value) OPERATOR (J::value)),               \
                    (I::value) OPERATOR (J::value)                          \
                >                                                           \
            >                                                               \
        { };                                                                \
    };                                                                      \
                                                                            \
    template <typename T1, typename T2, typename ...Tn>                     \
    struct dispatch<tag::NAME, T1, T2, Tn...>                               \
        : NAME<typename NAME<T1, T2>::type, Tn...>                          \
    { };                                                                    \
}} /* end namespace boost::mpl11 */                                         \
/**/

#endif // !BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP
