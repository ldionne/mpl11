/*!
 * @file
 * Defines the @ref Group typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_GROUP_HPP
#define BOOST_MPL11_GROUP_HPP

#include <boost/mpl11/fwd/group.hpp>

#include <boost/mpl11/fwd/bool.hpp>
#include <boost/mpl11/fwd/core.hpp>
#include <boost/mpl11/fwd/monoid.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct instantiate<Group> {
        template <typename Left, typename Right = Left>
        struct with;

        template <typename Datatype>
        struct with<Datatype> : true_ {
            template <typename x, typename y>
            using minus_impl = plus<box<x>, negate<box<y>>>;

            template <typename x>
            using negate_impl = minus<zero<Datatype>, box<x>>;
        };
    };
}} // end namespace boost::mpl11


#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct Group : false_ { };

    template <typename x, typename y>
    struct minus :
        Group<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template minus_impl<typename x::type, typename y::type>
    { };

    template <typename x>
    struct negate :
        Group<typename datatype<typename x::type>::type>::
        template negate_impl<typename x::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_GROUP_HPP
