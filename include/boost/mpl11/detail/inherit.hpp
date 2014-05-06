/*!
 * @file
 * Defines `boost::mpl11::detail::inherit`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_INHERIT_HPP
#define BOOST_MPL11_DETAIL_INHERIT_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Type multiply inheriting from each of the `xs...`.
     */
    template <typename ...xs>
    struct inherit : xs... { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_INHERIT_HPP
