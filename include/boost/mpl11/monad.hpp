/*!
 * @file
 * Defines the @ref Monad typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_MONAD_HPP
#define BOOST_MPL11_MONAD_HPP

#include <boost/mpl11/fwd/monad.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>

#ifndef BOOST_MPL11_NO_ASSERTIONS
#   include <boost/mpl11/functor.hpp>
#endif


namespace boost { namespace mpl11 {
    template <typename monad>
    struct join_ :
        Monad<typename datatype<typename monad::type>::type>::
        template join_impl<monad>
    { };

    template <typename MonadType, typename x>
    struct unit
        : Monad<MonadType>::template unit_impl<x>
    { };

    template <>
    struct instantiate<Monad> {
        template <typename Datatype>
        struct with : true_ {
#ifndef BOOST_MPL11_NO_ASSERTIONS
            static_assert(Functor<Datatype>::value, "Monad requires Functor");
#endif
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_MONAD_HPP
