/*!
 * @file
 * Defines `boost::mpl11::detail::logical_or::lazy`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LOGICAL_OR_LAZY_HPP
#define BOOST_MPL11_DETAIL_LOGICAL_OR_LAZY_HPP

#include <boost/mpl11/detail/logical_or/lazy_naive_struct.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace logical_or {
    /*!
     * @ingroup details
     *
     * Alias to the most efficient short-circuiting logical or.
     */
    template <typename ...xs>
    using lazy = lazy_naive_struct<xs...>;
}}}} // end namespace boost::mpl11::detail::logical_or

#endif // !BOOST_MPL11_DETAIL_LOGICAL_OR_LAZY_HPP
