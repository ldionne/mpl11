/*!
 * @file
 * Defines `boost::mpl11::detail::at_index::multiple_inheritance2`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_AT_INDEX_MULTIPLE_INHERITANCE2_HPP
#define BOOST_MPL11_DETAIL_AT_INDEX_MULTIPLE_INHERITANCE2_HPP

#include <boost/mpl11/detail/std_index_sequence.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace at_index {
    template <std_size_t n, std_size_t index, typename ...xs>
    struct select { };

    template <std_size_t n, typename ...xs>
    struct select<n, n, xs...> : xs... { };

    template <std_size_t n, typename indices, typename ...xs>
    struct m2_indexer_impl;

    template <std_size_t n, std_size_t ...index, typename ...xs>
    struct m2_indexer_impl<n, std_index_sequence<index...>, xs...>
        : select<n, index, xs>...
    { };

    /*!
     * @ingroup details
     *
     * Index-based lookup into a parameter pack using multiple inheritance.
     *
     * Credit goes to Richard Smith for the original idea:
     * http://llvm.org/bugs/show_bug.cgi?id=13263.
     */
    template <std_size_t n, typename ...xs>
    using multiple_inheritance2 = m2_indexer_impl<
        n, typename make_std_index_sequence<sizeof...(xs)>::type, xs...
    >;
}}}} // end namespace boost::mpl11::detail::at_index

#endif // !BOOST_MPL11_DETAIL_AT_INDEX_MULTIPLE_INHERITANCE2_HPP
