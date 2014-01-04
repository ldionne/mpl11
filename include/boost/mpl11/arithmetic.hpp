/*!
 * @file
 * Defines `boost::mpl11::Arithmetic`.
 */

#ifndef BOOST_MPL11_ARITHMETIC_HPP
#define BOOST_MPL11_ARITHMETIC_HPP

#include <boost/mpl11/fwd/arithmetic.hpp>

#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    #define BOOST_MPL11_ARITHMETIC_METHOD(METHOD_IMPL)                      \
        template <typename T1, typename T2>                                 \
        struct METHOD_IMPL                                                  \
            : Arithmetic<                                                   \
                typename tag_of<T1>::type, typename tag_of<T2>::type        \
            >::template METHOD_IMPL<T1, T2>                                 \
        { };                                                                \
    /**/
    BOOST_MPL11_ARITHMETIC_METHOD(add_impl)
    BOOST_MPL11_ARITHMETIC_METHOD(subtract_impl)
    BOOST_MPL11_ARITHMETIC_METHOD(divide_impl)
    BOOST_MPL11_ARITHMETIC_METHOD(multiply_impl)
    BOOST_MPL11_ARITHMETIC_METHOD(modulo_impl)
    #undef BOOST_MPL11_ARITHMETIC_METHOD
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARITHMETIC_HPP
