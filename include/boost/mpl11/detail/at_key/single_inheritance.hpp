/*!
 * @file
 * Defines `boost::mpl11::detail::at_key::single_inheritance`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_AT_KEY_SINGLE_INHERITANCE_HPP
#define BOOST_MPL11_DETAIL_AT_KEY_SINGLE_INHERITANCE_HPP

#include <boost/mpl11/detail/pair.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace at_key {
    template <typename ...pairs>
    struct single_map_impl {
        template <typename fail = void>
        static typename fail::key_not_found at_key_impl(...);
    };

    template <typename key, typename value, typename ...pairs>
    struct single_map_impl<pair<key, value>, pairs...>
        : single_map_impl<pairs...>
    {
        using single_map_impl<pairs...>::at_key_impl;
        static value at_key_impl(key*);
    };

    /*!
     * @ingroup details
     *
     * Key-based lookup into a parameter pack using single inheritance.
     */
    template <typename key, typename ...pairs>
    using single_inheritance = decltype(
        single_map_impl<pairs...>::at_key_impl((key*)nullptr)
    );
}}}} // end namespace boost::mpl11::detail::at_key

#endif // !BOOST_MPL11_DETAIL_AT_KEY_SINGLE_INHERITANCE_HPP
