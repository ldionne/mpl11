/*!
 * @file
 * Defines `boost::mpl11::detail::at_key::multiple_inheritance2`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_AT_KEY_MULTIPLE_INHERITANCE2_HPP
#define BOOST_MPL11_DETAIL_AT_KEY_MULTIPLE_INHERITANCE2_HPP

#include <boost/mpl11/detail/pair.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace at_key {
    template <typename key, typename k, typename v>
    struct select { };

    template <typename key, typename v>
    struct select<key, key, v> : v { };

    /*!
     * @ingroup details
     *
     * Key-based lookup into a parameter pack using multiple inheritance.
     *
     * @note
     * We don't risk duplicate base classes because there should not be
     * duplicate keys.
     */
    template <typename key, typename ...pairs>
    struct multiple_inheritance2;

    template <typename key, typename ...k, typename ...v>
    struct multiple_inheritance2<key, pair<k, v>...>
        : select<key, k, v>...
    { };
}}}} // end namespace boost::mpl11::detail::at_key

#endif // !BOOST_MPL11_DETAIL_AT_KEY_MULTIPLE_INHERITANCE2_HPP
