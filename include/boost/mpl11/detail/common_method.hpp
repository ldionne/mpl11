/*!
 * @file
 * Defines `boost::mpl11::detail::common_method`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_COMMON_METHOD_HPP
#define BOOST_MPL11_DETAIL_COMMON_METHOD_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Helper to reduce syntactic overhead in typeclasses.
     */
    template <typename Left, typename Right>
    struct common_method;
}}}


#include <boost/mpl11/core.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename Left, typename Right>
    struct common_method {
        template <template <typename ...> class f, typename x, typename y>
        using apply = f<
            typename cast<Left, typename common_datatype<Left, Right>::type>
            ::type::template apply<typename x::type>::type,

            typename cast<Right, typename common_datatype<Left, Right>::type>
            ::type::template apply<typename y::type>::type
        >;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_COMMON_METHOD_HPP
