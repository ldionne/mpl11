/*!
 * @file
 * Forward declares the @ref Enumerable typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_ENUMERABLE_HPP
#define BOOST_MPL11_FWD_ENUMERABLE_HPP

#include <boost/mpl11/fwd/bool.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Enumerable Enumerable
     *
     * The `Enumerable` typeclass defines operations on sequentially
     * ordered datatypes.
     *
     *
     * ### Methods
     * `succ` and `pred`.
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @{
     */
    template <typename Datatype, typename = true_>
    struct Enumerable;

    //! Returns the successor of the given object.
    template <typename e>
    struct succ;

    //! Returns the predecessor of the given object.
    template <typename e>
    struct pred;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ENUMERABLE_HPP
