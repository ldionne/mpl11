/*!
 * @file
 * Forward declares the @ref Maybe datatype.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_MAYBE_HPP
#define BOOST_MPL11_FWD_MAYBE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/fwd/bool.hpp>
#include <boost/mpl11/fwd/functional.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     * @defgroup Maybe Maybe
     *
     * `Maybe` encapsulates an optional value.
     *
     * A `Maybe` either contains a value (represented as `just<x>`), or it is
     * empty (represented as `nothing`).
     *
     *
     * ### Instance of
     * `Functor`
     *
     * @todo
     * - Instantiate `Comparable` and `Orderable` for `Maybe`. This might
     *   require `Maybe` to become a parametric datatype. Can we handle this?
     *
     * @{
     */
    struct Maybe;

    //! Creates an optional value containing `x`.
    template <typename x>
    struct just;

    //! Creates an empty optional value.
    struct nothing BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Applies a metafunction class to a `Maybe`, with a fallback result.
     *
     * Specifically, `maybe` takes a default value `def`, a metafunction
     * class `f` and a `Maybe` `m`. If `m` is `nothing`, `def` is returned.
     * Otherwise, the result of applying `f` to the contents of `m` is
     * returned.
     */
    template <typename def, typename f, typename m>
    struct maybe;

    //! Returns whether a `Maybe` is a `just`.
    template <typename m>
    BOOST_MPL11_DOXYGEN_ALIAS(is_just, maybe<false_, always<true_>, m>);

    //! Returns whether a `Maybe` is a `nothing`.
    template <typename m>
    BOOST_MPL11_DOXYGEN_ALIAS(is_nothing, maybe<true_, always<false_>, m>);

    //! If `m` is nothing, returns `def`. Otherwise, returns the value
    //! inside the `just`.
    template <typename def, typename m>
    BOOST_MPL11_DOXYGEN_ALIAS(from_maybe, maybe<def, quote<id>, m>);

    namespace maybe_detail { template <typename ...> struct err_from_just; }

    /*!
     * Extracts the value out of a `just`, and triggers a hard compile-time
     * error if the argument is `nothing`.
     *
     * @todo
     * Consider being SFINAE friendly.
     */
    template <typename m>
    BOOST_MPL11_DOXYGEN_ALIAS(from_just,
        maybe<maybe_detail::err_from_just<>, quote<id>, m>);
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_MAYBE_HPP
