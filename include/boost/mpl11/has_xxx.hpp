/*!
 * @file
 * This file defines macros to do SFINAE checks.
 */

#ifndef BOOST_MPL11_HAS_XXX_HPP
#define BOOST_MPL11_HAS_XXX_HPP

#include <boost/mpl11/bool.hpp>


#define BOOST_MPL11_HAS_NESTED_TYPE(TRAIT_NAME, NESTED_TYPE)                \
    template <typename T>                                                   \
    class TRAIT_NAME {                                                      \
        template <typename U>                                               \
        static ::boost::mpl11::true_ test(typename U::NESTED_TYPE* =0);     \
                                                                            \
        template <typename U>                                               \
        static ::boost::mpl11::false_ test(...);                            \
                                                                            \
    public:                                                                 \
        using type = decltype(test<T>(0));                                  \
        static constexpr bool value = type::value;                          \
    };                                                                      \
/**/

#endif // !BOOST_MPL11_HAS_XXX_HPP
