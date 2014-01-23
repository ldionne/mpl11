/*!
 * @file
 * Forward declares logical metafunctions.
 */

#ifndef BOOST_MPL11_FWD_LOGICAL_HPP
#define BOOST_MPL11_FWD_LOGICAL_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @defgroup Logical Logical
     *
     * Logical operators and conditional branch selection.
     *
     * @{
     */

    /*!
     * Boolean `StaticConstant` representing the result of short-circuit
     * logical and (`&&`) on its arguments.
     *
     * Specifically, its arguments must be metafunctions returning
     * `StaticConstant`s. Arguments are then evaluated from left to
     * right in a short-circuiting fashion. If no arguments are
     * provided, `and_` is equivalent to `true_`.
     *
     *
     * @todo
     * - Consider using folds in the implementation of `and_` and `or_`.
     * - Reformulate the documentation for all the logical metafunctions.
     */
    template <typename ...xs>
    struct and_;

    /*!
     * Boolean `StaticConstant` representing the result of short-circuit
     * logical or (`||`) on its arguments.
     *
     * Specifically, its arguments must be metafunctions returning
     * `StaticConstant`s. Arguments are then evaluated from left to
     * right in a short-circuiting fashion. If no arguments are
     * provided, `or_` is equivalent to `false_`.
     */
    template <typename ...xs>
    struct or_;

    /*!
     * Boolean `StaticConstant` representing the logical negation (`!`) of
     * its argument.
     *
     * Specifically, `not_<b>` is equivalent to `bool_<!b::%type::value>`.
     */
    template <typename b>
    struct not_;

    namespace logical_detail { template <bool> struct if_impl; }

    //! Equivalent to `if_<bool_<Condition>, Then, Else>`.
    template <bool Condition, typename Then, typename Else>
    using if_c = typename logical_detail::if_impl<Condition>::
                 template result<Then, Else>;

    //! Equivalent to `else_if<bool_<Condition>, Then, Else>`.
    template <bool Condition, typename Then, typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(else_if_c, if_c<Condition, Then, Else>);

    /*!
     * Evaluate one of two metafunctions based on a lazy condition.
     *
     * Specifically, `Condition` must be a nullary metafunction returning
     * a `StaticConstant`. If `Condition::type::value` is `true`, `if_`
     * inherits from `Then`, otherwise it inherits from `Else`.
     *
     * `if_` can be combined with `else_if` and `else_` to form a small DSL
     * that greatly improves readability.
     */
    template <typename Condition, typename Then, typename Else>
    struct if_;

    //! Alias to `if_`; provided for the added semantics when used with `if_`.
    template <typename Condition, typename Then, typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(else_if, if_<Condition, Then, Else>);

    //! Transparent alias to its argument; provided for use with `if_`.
    template <typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(else_, Else);
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LOGICAL_HPP
