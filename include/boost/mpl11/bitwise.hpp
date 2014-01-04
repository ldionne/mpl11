/*!
 * @file
 * Defines `boost::mpl11::Bitwise`.
 */

#ifndef BOOST_MPL11_BITWISE_HPP
#define BOOST_MPL11_BITWISE_HPP

#include <boost/mpl11/fwd/bitwise.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename T, typename Shift>
    struct shift_left : shift_left_c<T, Shift::value> {
#ifndef BOOST_MPL11_NO_CHECKED_METHODS
        static_assert(Shift::value >= 0,
        "Invalid usage of `shift_left` with a negative `Shift`.");
#endif
    };

    template <typename T, typename Shift>
    struct shift_right : shift_right_c<T, Shift::value> {
#ifndef BOOST_MPL11_NO_CHECKED_METHODS
        static_assert(Shift::value >= 0,
        "Invalid usage of `shift_right` with a negative `Shift`.");
#endif
    };

    #define BOOST_MPL11_BITWISE_METHOD(METHOD_IMPL)                         \
        template <typename T1, typename T2>                                 \
        struct METHOD_IMPL                                                  \
            : Bitwise<                                                      \
                typename tag_of<T1>::type, typename tag_of<T2>::type        \
            >::template METHOD_IMPL<T1, T2>                                 \
        { };                                                                \
    /**/
    BOOST_MPL11_BITWISE_METHOD(bitand_impl)
    BOOST_MPL11_BITWISE_METHOD(bitor_impl)
    BOOST_MPL11_BITWISE_METHOD(bitxor_impl)
    #undef BOOST_MPL11_BITWISE_METHOD

    template <typename T, typename Shift>
    struct shift_left_impl
        : shift_left_c<T, Shift::value>
    { };

    template <typename T, typename Shift>
    struct shift_right_impl
        : shift_right_c<T, Shift::value>
    { };

    template <typename T, detail::std_size_t Shift>
    struct shift_left_c_impl
        : Bitwise<typename tag_of<T>::type>::
          template shift_left_c_impl<T, Shift>
    { };

    template <typename T, detail::std_size_t Shift>
    struct shift_right_c_impl
        : Bitwise<typename tag_of<T>::type>::
          template shift_right_c_impl<T, Shift>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BITWISE_HPP
