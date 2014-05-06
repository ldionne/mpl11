/*!
 * @file
 * Defines `boost::mpl11::detail::pair`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_PAIR_HPP
#define BOOST_MPL11_DETAIL_PAIR_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Empty struct (not a `mpl::pair`).
     *
     * This is used by some techniques to perform key-based lookup.
     */
    template <typename key, typename value>
    struct pair { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_PAIR_HPP
