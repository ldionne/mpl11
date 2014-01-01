/*!
 * @file
 * Defines `boost::mpl11::Arithmetic`.
 */

#ifndef BOOST_MPL11_ARITHMETIC_HPP
#define BOOST_MPL11_ARITHMETIC_HPP

#include <boost/mpl11/fwd/arithmetic.hpp>

#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults { struct Arithmetic { }; }

    #define BOOST_MPL11_ARITHMETIC_METHOD(METHOD)                           \
        template <typename T1, typename T2>                                 \
        struct METHOD                                                       \
            : Arithmetic<                                                   \
                typename tag_of<T1>::type, typename tag_of<T2>::type        \
            >::template METHOD ## _impl<T1, T2>                             \
        { };                                                                \
    /**/
    BOOST_MPL11_ARITHMETIC_METHOD(add)
    BOOST_MPL11_ARITHMETIC_METHOD(subtract)
    BOOST_MPL11_ARITHMETIC_METHOD(divide)
    BOOST_MPL11_ARITHMETIC_METHOD(multiply)
    BOOST_MPL11_ARITHMETIC_METHOD(modulo)
    #undef BOOST_MPL11_ARITHMETIC_METHOD
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARITHMETIC_HPP
