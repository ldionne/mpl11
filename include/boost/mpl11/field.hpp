/*!
 * @file
 * Defines the @ref Field typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FIELD_HPP
#define BOOST_MPL11_FIELD_HPP

#include <boost/mpl11/fwd/field.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/fwd/ring.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct Field : false_ { };

    template <>
    struct instantiate<Field> {
        template <typename Left, typename Right = Left>
        struct with;

        template <typename Datatype>
        struct with<Datatype> : true_ {
            template <typename x, typename y>
            using quot_impl = mult<box<x>, recip<box<y>>>;

            template <typename x>
            using recip_impl = quot<one<Datatype>, box<x>>;
        };
    };

    template <typename x, typename y>
    struct quot :
        Field<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template quot_impl<typename x::type, typename y::type>
    { };

    template <typename x>
    struct recip :
        Field<typename datatype<typename x::type>::type>::
        template recip_impl<typename x::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FIELD_HPP
