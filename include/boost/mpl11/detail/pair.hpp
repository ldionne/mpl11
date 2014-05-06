/*!
 * @file
 * Defines `boost::mpl11::detail::pair` and `boost::mpl11::index_pair`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_PAIR_HPP
#define BOOST_MPL11_DETAIL_PAIR_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


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

    /*!
     * @ingroup details
     *
     * Empty struct (not a `mpl::pair`).
     *
     * This is used by some techniques to perform index-based lookup.
     */
    template <std_size_t index, typename value>
    struct index_pair { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_PAIR_HPP
