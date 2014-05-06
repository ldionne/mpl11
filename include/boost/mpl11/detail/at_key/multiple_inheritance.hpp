/*!
 * @file
 * Defines `boost::mpl11::detail::at_key::multiple_inheritance`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_AT_KEY_MULTIPLE_INHERITANCE_HPP
#define BOOST_MPL11_DETAIL_AT_KEY_MULTIPLE_INHERITANCE_HPP

#include <boost/mpl11/detail/inherit.hpp>
#include <boost/mpl11/detail/pair.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace at_key {
    template <typename key, typename value>
    value multi_lookup_impl(pair<key, value>*);

    /*!
     * @ingroup details
     *
     * Key-based lookup into a parameter pack using multiple inheritance.
     *
     * Credit goes to Agustín Bergé for posting a variant of this technique
     * on the Boost.Dev mailing list.
     *
     * @internal
     * We assume the `xs` to be boxed types so we don't need `no_decay`.
     */
    template <typename key, typename ...pairs>
    using multiple_inheritance = decltype(
        // Disable ADL or the template arguments of the pairs will
        // be instantiated.
        at_key::multi_lookup_impl<key>((inherit<pairs...>*)nullptr)
    );
}}}} // end namespace boost::mpl11::detail::at_key

#endif // !BOOST_MPL11_DETAIL_AT_KEY_MULTIPLE_INHERITANCE_HPP
