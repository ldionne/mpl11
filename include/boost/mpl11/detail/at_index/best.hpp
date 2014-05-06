/*!
 * @file
 * Defines `boost::mpl11::detail::at_index::best`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_AT_INDEX_BEST_HPP
#define BOOST_MPL11_DETAIL_AT_INDEX_BEST_HPP

#include <boost/mpl11/detail/at_index/overload_resolution.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace at_index {
    /*!
     * @ingroup details
     *
     * Alias to the most efficient index-based lookup.
     */
    template <std_size_t index, typename ...xs>
    using best = overload_resolution<index, xs...>;
}}}} // end namespace boost::mpl11::detail::at_index

#endif // !BOOST_MPL11_DETAIL_AT_INDEX_BEST_HPP
