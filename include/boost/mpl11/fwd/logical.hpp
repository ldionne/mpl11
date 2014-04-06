/*!
 * @file
 * Forward declares logical metafunctions.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_LOGICAL_HPP
#define BOOST_MPL11_FWD_LOGICAL_HPP

#include <boost/mpl11/detail/config.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @defgroup Logical Logical
     *
     * Logical operators and conditional branch selection.
     *
     * @{
     */

    /*!
     * Returns the result of short-circuit _logical and_ (`&&`) on its
     * arguments.
     *
     * Arguments must be `StaticConstant`s that will be unboxed from left to
     * right in a short-circuiting fashion. If no arguments are provided,
     * `and_` is equivalent to `true_`.
     */
    template <typename ...xs>
    struct and_;

    /*!
     * Returns the result of short-circuit _logical or_ (`||`) on its
     * arguments.
     *
     * Arguments must be `StaticConstant`s that will be unboxed from left to
     * right in a short-circuiting fashion. If no arguments are provided,
     * `or_` is equivalent to `false_`.
     */
    template <typename ...xs>
    struct or_;

    /*!
     * Returns the _logical negation_ (`!`) of its argument.
     *
     * Specifically, `not_<x>` is equivalent to `bool_<!x::%type::value>`.
     */
    template <typename x>
    struct not_;

    namespace logical_detail { template <bool> struct if_impl; }

    //! Equivalent to `if_<bool_<Condition>, Then, Else>`.
    template <bool Condition, typename Then, typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(if_c,
            typename logical_detail::if_impl<Condition>::
            template result<Then, Else>);

    //! Equivalent to `else_if<bool_<Condition>, Then, Else>`.
    template <bool Condition, typename Then, typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(else_if_c, if_c<Condition, Then, Else>);

    /*!
     * Evaluates one of two branches based on a condition.
     *
     * Specifically, `if_<Condition, Then, Else>` is equivalent to `Then`
     * if `Condition::%type::value` evaluates to `true`, and to `Else`
     * otherwise.
     *
     * `if_` can be combined with `else_if` and `else_` to improve
     * readability.
     */
    template <typename Condition, typename Then, typename Else>
    struct if_;

    //! Equivalent to `if_`; provided for use with `if_`.
    template <typename Condition, typename Then, typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(else_if, if_<Condition, Then, Else>);

    //! Transparent alias to its argument; provided for use with `if_`.
    template <typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(else_, Else);
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LOGICAL_HPP
