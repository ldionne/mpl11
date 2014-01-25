/*!
 * @file
 * Forward declares logical metafunctions.
 */

#ifndef BOOST_MPL11_FWD_LOGICAL_HPP
#define BOOST_MPL11_FWD_LOGICAL_HPP

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
     * _logical and_ (`&&`) on its arguments.
     *
     * Arguments must be `StaticConstant`s that will be unboxed from left to
     * right in a short-circuiting fashion. If no arguments are provided,
     * `and_` is equivalent to `true_`.
     *
     *
     * @todo
     * - Consider using folds in the implementation of `and_` and `or_`.
     */
    template <typename ...xs>
    struct and_;

    /*!
     * Boolean `StaticConstant` representing the result of short-circuit
     * _logical or_ (`||`) on its arguments.
     *
     * Arguments must be `StaticConstant`s that will be unboxed from left to
     * right in a short-circuiting fashion. If no arguments are provided,
     * `or_` is equivalent to `false_`.
     */
    template <typename ...xs>
    struct or_;

    /*!
     * Boolean `StaticConstant` representing the _logical negation_ (`!`) of
     * its argument.
     *
     * Specifically, `not_<x>` is equivalent to `bool_<!x::%type::value>`.
     */
    template <typename x>
    struct not_;

    namespace logical_detail { template <bool> struct if_impl; }

    //! Equivalent to `if_<bool_<condition>, then_branch, else_branch>`.
    template <bool condition, typename then_branch, typename else_branch>
    using if_c = typename logical_detail::if_impl<condition>::
                 template result<then_branch, else_branch>;

    //! Equivalent to `else_if<bool_<condition>, then_branch, else_branch>`.
    template <bool condition, typename then_branch, typename else_branch>
    using else_if_c = if_c<condition, then_branch, else_branch>;

    /*!
     * Evaluates one of two branches based on a `StaticConstant` condition.
     *
     * Specifically, `if_<condition, then_branch, else_branch>` is equivalent
     * to `then_branch` if `condition` evaluates to `true`, and to
     * `else_branch` otherwise.
     *
     * `if_` can be combined with `else_if` and `else_` to improve
     * readability.
     */
    template <typename condition, typename then_branch, typename else_branch>
    struct if_;

    //! Equivalent to `if_`; provided for use with `if_`.
    template <typename condition, typename then_branch, typename else_branch>
    using else_if = if_<condition, then_branch, else_branch>;

    //! Transparent alias to its argument; provided for use with `if_`.
    template <typename else_branch>
    using else_ = else_branch;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LOGICAL_HPP
