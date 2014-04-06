/*!
 * @file
 * Forward declares the @ref Monad typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_MONAD_HPP
#define BOOST_MPL11_FWD_MONAD_HPP

#include <boost/mpl11/fwd/bool.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Monad Monad
     *
     * `Monad`s are `Functor`s with additional structure allowing values
     * to be lifted and nested monads to be flattened.
     *
     *
     * ### Refines
     * `Functor`
     *
     * ### Methods
     * `unit` and `join_`
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @{
     */
    template <typename Datatype, typename = true_>
    struct Monad;

    //! Flatten one level of nested monads.
    template <typename monad>
    struct join_;

    //! Lift a value into the monad.
    template <typename MonadType, typename x>
    struct unit;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_MONAD_HPP
