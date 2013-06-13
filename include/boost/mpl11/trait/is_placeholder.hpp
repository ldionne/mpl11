/*!
 * @file
 * This file defines `boost::mpl11::trait::is_placeholder`.
 */

#ifndef BOOST_MPL11_TRAIT_IS_PLACEHOLDER_HPP
#define BOOST_MPL11_TRAIT_IS_PLACEHOLDER_HPP

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace trait {
    template <typename T>
    struct is_placeholder
        : false_
    { };
}}}}

#endif // !BOOST_MPL11_TRAIT_IS_PLACEHOLDER_HPP
