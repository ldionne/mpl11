/*!
 * @file
 * Defines `boost::mpl11::detail::logical_or::strict`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_HPP
#define BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_HPP

#include <boost/mpl11/detail/logical_or/strict_is_same.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace logical_or {
    /*!
     * @ingroup details
     *
     * Alias to the most efficient non short-circuiting logical or.
     */
    template <typename ...xs>
    using strict = strict_is_same<xs...>;
}}}} // end namespace boost::mpl11::detail::logical_or

#endif // !BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_HPP
