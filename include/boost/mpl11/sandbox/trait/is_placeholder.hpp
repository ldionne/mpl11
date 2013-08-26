/*!
 * @file
 * This file defines `boost::mpl11::trait::is_placeholder`.
 */

#ifndef BOOST_MPL11_TRAIT_IS_PLACEHOLDER_HPP
#define BOOST_MPL11_TRAIT_IS_PLACEHOLDER_HPP

#include <boost/mpl11/has_xxx.hpp>


namespace boost { namespace mpl11 { namespace trait {
    namespace is_placeholder_detail {
        BOOST_MPL11_HAS_NESTED_TYPE(has_is_placeholder, mpl11::is_placeholder)
    }

    template <typename T>
    struct is_placeholder
        : is_placeholder_detail::has_is_placeholder<T>::type
    { };
}}} // end namespace boost::mpl11::trait

#endif // !BOOST_MPL11_TRAIT_IS_PLACEHOLDER_HPP
