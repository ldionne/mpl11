/*!
 * @file
 * This file defines the trait metafunctions used in the library.
 */

#ifndef BOOST_MPL11_TRAITS_HPP
#define BOOST_MPL11_TRAITS_HPP

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace traits {
    template <typename T>
    struct tag_of {
        using type = typename T::mpl11::tag;
    };

    template <typename T>
    struct is_sequence
        : false_
    { };
}}}}

#endif // !BOOST_MPL11_TRAITS_HPP
