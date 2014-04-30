/*!
 * @file
 * Defines `boost::mpl11::detail::logical_or::strict_specialization`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_SPECIALIZATION_HPP
#define BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_SPECIALIZATION_HPP

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace logical_or {
    template <typename ...xs>
    struct strict_specialization_impl
        : true_
    { };

    template <typename ...T>
    struct strict_specialization_impl<integer_c<T, false>...>
        : false_
    { };

    /*!
     * @ingroup details
     *
     * Strict (non short-circuiting) logical or implemented with (clever)
     * partial specialization.
     */
    template <typename ...xs>
    using strict_specialization = strict_specialization_impl<
        bool_<(bool)xs::type::value>...
    >;
}}}} // end namespace boost::mpl11::detail::logical_or

#endif // !BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_SPECIALIZATION_HPP
