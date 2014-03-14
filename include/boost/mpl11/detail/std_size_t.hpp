/*!
 * @file
 * Defines `boost::mpl11::detail::std_size_t`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_STD_SIZE_T_HPP
#define BOOST_MPL11_DETAIL_STD_SIZE_T_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Type identical to `std::size_t`.
     */
    using std_size_t = decltype(sizeof(int));
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_STD_SIZE_T_HPP
