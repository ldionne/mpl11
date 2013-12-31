/*!
 * @file
 * Defines `boost::mpl11::Arithmetic`.
 */

#ifndef BOOST_MPL11_ARITHMETIC_HPP
#define BOOST_MPL11_ARITHMETIC_HPP

#include <boost/mpl11/fwd/arithmetic.hpp>

#include <boost/mpl11/detail/variadic_foldl.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults { struct Arithmetic { }; }

    #define BOOST_MPL11_DEFINE_METHOD(METHOD, METHOD_IMPL)                  \
        namespace arithmetic_detail {                                       \
            struct METHOD_IMPL {                                            \
                template <typename T1, typename T2>                         \
                using apply = typename Arithmetic<                          \
                    typename tag_of<T1>::type, typename tag_of<T2>::type    \
                >::template METHOD_IMPL<T1, T2>;                            \
            };                                                              \
        }                                                                   \
                                                                            \
        template <typename T1, typename T2, typename ...Tn>                 \
        struct METHOD                                                       \
            : detail::variadic_foldl<                                       \
                arithmetic_detail::METHOD_IMPL, T1, T2, Tn...               \
            >                                                               \
        { };                                                                \
    /**/
    BOOST_MPL11_DEFINE_METHOD(add, add_impl)
    BOOST_MPL11_DEFINE_METHOD(subtract, subtract_impl)
    BOOST_MPL11_DEFINE_METHOD(divide, divide_impl)
    BOOST_MPL11_DEFINE_METHOD(multiply, multiply_impl)
    #undef BOOST_MPL11_DEFINE_METHOD

    template <typename T1, typename T2>
    struct modulo
        : Arithmetic<
            typename tag_of<T1>::type, typename tag_of<T2>::type
        >::template modulo_impl<T1, T2>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARITHMETIC_HPP
