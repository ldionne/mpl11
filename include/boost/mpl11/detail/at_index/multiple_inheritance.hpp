/*!
 * @file
 * Defines `boost::mpl11::detail::at_index::multiple_inheritance`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_AT_INDEX_MULTIPLE_INHERITANCE_HPP
#define BOOST_MPL11_DETAIL_AT_INDEX_MULTIPLE_INHERITANCE_HPP

#include <boost/mpl11/detail/pair.hpp>
#include <boost/mpl11/detail/std_index_sequence.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace at_index {
    template <std_size_t index, typename value>
    value multi_lookup_impl(index_pair<index, value>*);

    template <typename indices, typename ...xs>
    struct indexer_impl;

    template <std_size_t ...indices, typename ...xs>
    struct indexer_impl<std_index_sequence<indices...>, xs...>
        : index_pair<indices, xs>...
    { };

    /*!
     * @ingroup details
     *
     * Index-based lookup into a parameter pack using multiple inheritance.
     *
     * Credit goes to Agustín Bergé for posting a variant of this technique
     * for type indices on the Boost.Dev mailing list.
     *
     * @internal
     * We assume the `xs` to be boxed types so we don't need `no_decay`.
     */
    template <std_size_t index, typename ...xs>
    using multiple_inheritance = decltype(
        // Disable ADL or the xs... will be instantiated.
        at_index::multi_lookup_impl<index>(
            (indexer_impl<
                typename make_std_index_sequence<sizeof...(xs)>::type, xs...
            >*)nullptr
        )
    );
}}}} // end namespace boost::mpl11::detail::at_index

#endif // !BOOST_MPL11_DETAIL_AT_INDEX_MULTIPLE_INHERITANCE_HPP
