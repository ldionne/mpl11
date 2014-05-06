/*!
 * @file
 * Defines `boost::mpl11::detail::at_index::overload_resolution`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_AT_INDEX_OVERLOAD_RESOLUTION_HPP
#define BOOST_MPL11_DETAIL_AT_INDEX_OVERLOAD_RESOLUTION_HPP

#include <boost/mpl11/detail/std_index_sequence.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace at_index {
    template <typename ignore>
    struct overload_impl;

    template <std_size_t ...ignore>
    struct overload_impl<std_index_sequence<ignore...>> {
        template <typename nth>
        static nth apply(decltype(ignore, (void*)nullptr)..., nth*, ...);
    };

    /*!
     * @ingroup details
     *
     * Index-based lookup into a parameter pack using overload resolution.
     *
     * Credit goes to Richard Smith for the original idea:
     * http://llvm.org/bugs/show_bug.cgi?id=13263.
     *
     *
     * @internal
     * We assume the `xs` to be boxed types so we don't need `no_decay`.
     */
    template <std_size_t index, typename ...xs>
    using overload_resolution = decltype(
        overload_impl<typename make_std_index_sequence<index>::type>::apply(
            (xs*)nullptr...
        )
    );
}}}} // end namespace boost::mpl11::detail::at_index

#endif // !BOOST_MPL11_DETAIL_AT_INDEX_OVERLOAD_RESOLUTION_HPP
