/*!
 * @file
 * Defines `boost::mpl11::detail::std_is_same`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_STD_IS_SAME_HPP
#define BOOST_MPL11_DETAIL_STD_IS_SAME_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Equivalent to `std::is_same`; except it only has a nested `::value`
     * and a nested `::type`.
     */
    template <typename T, typename U>
    struct std_is_same {
        static constexpr bool value = false;
        using type = std_is_same;
    };

    template <typename T>
    struct std_is_same<T, T> {
        static constexpr bool value = true;
        using type = std_is_same;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_STD_IS_SAME_HPP
