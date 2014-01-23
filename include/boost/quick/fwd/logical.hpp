/*!
 * @file
 * Forward declares logical metafunctions.
 */

#ifndef BOOST_MPL11_FWD_LOGICAL_HPP
#define BOOST_MPL11_FWD_LOGICAL_HPP

namespace boost { namespace mpl11 {
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
     * - Consider creating a Logical module, at least in the documentation.
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LOGICAL_HPP
