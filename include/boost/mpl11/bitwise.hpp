/*!
 * @file
 * Defines `boost::mpl11::Bitwise`.
 */

#ifndef BOOST_MPL11_BITWISE_HPP
#define BOOST_MPL11_BITWISE_HPP

#include <boost/mpl11/fwd/bitwise.hpp>

#include <boost/mpl11/detail/variadic_foldl.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults { struct Bitwise { }; }

    #define BOOST_MPL11_DEFINE_METHOD(METHOD, METHOD_IMPL)                  \
        namespace bitwise_detail {                                          \
            struct METHOD_IMPL {                                            \
                template <typename T1, typename T2>                         \
                using apply = typename Bitwise<                             \
                    typename tag_of<T1>::type, typename tag_of<T2>::type    \
                >::template METHOD_IMPL<T1, T2>;                            \
            };                                                              \
        }                                                                   \
                                                                            \
        template <typename T1, typename T2, typename ...Tn>                 \
        struct METHOD                                                       \
            : detail::variadic_foldl<                                       \
                bitwise_detail::METHOD_IMPL, T1, T2, Tn...                  \
            >                                                               \
        { };                                                                \
    /**/
    BOOST_MPL11_DEFINE_METHOD(bitand_, bitand_impl)
    BOOST_MPL11_DEFINE_METHOD(bitor_, bitor_impl)
    BOOST_MPL11_DEFINE_METHOD(bitxor, bitxor_impl)
    #undef BOOST_MPL11_DEFINE_METHOD

    template <typename T, typename Shift>
    struct shift_left
        : Bitwise<typename tag_of<T>::type, typename tag_of<T>::type>::
            template shift_left_impl<T, Shift>
    { };

    template <typename T, typename Shift>
    struct shift_right
        : Bitwise<typename tag_of<T>::type, typename tag_of<T>::type>::
            template shift_right_impl<T, Shift>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BITWISE_HPP
