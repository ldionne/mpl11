/*!
 * @file
 * Defines the methods of the @ref Enumerable typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_ENUMERABLE_HPP
#define BOOST_MPL11_ENUMERABLE_HPP

#include <boost/mpl11/fwd/enumerable.hpp>

#include <boost/mpl11/core.hpp>


namespace boost { namespace mpl11 {
    template <typename e>
    struct succ :
        Enumerable<typename datatype<typename e::type>::type>::
        template succ_impl<e>
    { };

    template <typename e>
    struct pred :
        Enumerable<typename datatype<typename e::type>::type>::
        template pred_impl<e>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ENUMERABLE_HPP
