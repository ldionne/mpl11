/*!
 * @file
 * Defines `boost::mpl11::detail::at_key::best`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_AT_KEY_BEST_HPP
#define BOOST_MPL11_DETAIL_AT_KEY_BEST_HPP

#include <boost/mpl11/detail/at_key/multiple_inheritance.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace at_key {
    /*!
     * @ingroup details
     *
     * Alias to the most efficient key-based lookup.
     */
    template <typename key, typename ...pairs>
    using best = multiple_inheritance<key, pairs...>;
}}}} // end namespace boost::mpl11::detail::at_index

#endif // !BOOST_MPL11_DETAIL_AT_KEY_BEST_HPP
